#include "headers.h"

int main(int argc, char* argv[])
{

	int srv_socket, cl_socket;
	int srv_len, cl_len;
	int status = 0;
	int opt = 1;
	char str[100];
	char msg[] = "Hello from Server";

	struct sockaddr_in srv_address;
	struct sockaddr_in cl_address;
	int adrlen = sizeof(srv_address);

	if(argc != 2)
	{
		logs("use <port number>\n");
		return -1;
	}

	logs("hello from server\n");
	//create a socket
	srv_socket = socket(AF_INET, SOCK_STREAM,0);
	if(srv_socket < 0){
		logs("socket");
		exit(EXIT_FAILURE);
	}
	if(setsockopt(srv_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0)
	{
		logs("setsockopt");
		exit(EXIT_FAILURE);
	}
	srv_address.sin_family =  AF_INET;
	srv_address.sin_addr.s_addr = INADDR_ANY;
	srv_address.sin_port = htons( atoi(argv[1]));
		
	//bind
	if(bind(srv_socket, (struct sockaddr*)&srv_address, sizeof(srv_address)) < 0)
	{
		logs("bind\n");
		exit(EXIT_FAILURE);
	}

	// listen make queue
	if(listen(srv_socket, 5) < 0)
	{
		logs("listen ");
		exit(EXIT_FAILURE);
	}
	
	//accept and wait for other clients
	while(1)
	{
		cl_socket = accept(srv_socket, (struct sockaddr *) &cl_address, (socklen_t *)&adrlen);
		if(cl_socket < 0)
		{
			logs("accept");
			return -1;
		}
		//logs("client info:%s\n", inet_ntoa(*cl_address));
		logs("REQUEST FROM:%s PORT:%d\n",inet_ntop(AF_INET,&cl_address.sin_addr,str,sizeof(str)),htons(cl_address.sin_port));
		//send msg to client
		status = send(cl_socket, msg, sizeof(msg),0);
		logs("msg sent\n");
		status = read(cl_socket, msg, sizeof(msg));	
		logs("msg recv:%s\n",msg);
	}	

	logs("server_exit\n");
}
