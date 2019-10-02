server:server.o
	cc server.o -o server

server.o: server.c
	cc -c server.c -o server.o

client: client.c
	cc client.c -o client

clean:
	rm -rf *.o
	rm -rf client
	rm -rf server
