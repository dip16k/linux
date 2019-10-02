#include "headers.h"

int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 

	if(argc !=2){
		logc("use <port>\n");
		return -1;
	}

	logc("welcome to the client\n");
	//create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        logc("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(atoi(argv[1])); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        logc("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

   if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        logc("\nConnection Failed \n"); 
        return -1; 
    } 
    send(sock , hello , strlen(hello) , 0 ); 
    logc("Hello message sent\n"); 
    valread = read( sock , buffer, 1024); 
    logc("%s\n",buffer ); 
    return 0; 

}
