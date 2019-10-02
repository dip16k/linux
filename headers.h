#ifndef HEADERS_H
#define HEADERS_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/socket.h>
	#include <sys/types.h>
	#include <unistd.h>
	#include <sys/un.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	
	#include<netinet/in.h>	
	#include<string.h>

	#define TAGS "[SERVER]"
	#define logs(...) printf(TAGS __VA_ARGS__);
	
	#define TAGC "[CLIENT]"
	#define logc(...) printf(TAGC __VA_ARGS__);

#endif //
