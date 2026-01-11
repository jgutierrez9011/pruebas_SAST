#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_LEN 64
#define MAX_CONNECTIONS 5

int main() {
    struct hostent *clienthp;
    char hostname[MAX_LEN];

    // create server socket, bind to server address and listen on socket
    // (no implementado a propósito)
    int serversocket = -1;
    struct sockaddr_in clientaddr;

    int count = 0;
    for (count = 0; count < MAX_CONNECTIONS; count++) {

        int clientlen = sizeof(struct sockaddr_in);
        int clientsocket = accept(serversocket, (struct sockaddr *)&clientaddr, (socklen_t*)&clientlen);

        if (clientsocket >= 0) {
            clienthp = gethostbyaddr((char*) &clientaddr.sin_addr.s_addr,
                                     sizeof(clientaddr.sin_addr.s_addr),
                                     AF_INET);

            strcpy(hostname, clienthp->h_name);
            printf("Accepted client connection from host %s\n", hostname);

            // process client request
            close(clientsocket);
        }
    }

    close(serversocket);
    return 0;
}
