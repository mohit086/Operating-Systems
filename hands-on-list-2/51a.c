#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
//server, run first
int main(){
    struct sockaddr_in serv, cli;
    int sd;
    sd = socket(AF_INET, SOCK_STREAM, 0); // Internet TCP sockets
    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY; // accepts connections from any IP address
    serv.sin_port = htons(5000); // port 5000
    bind(sd, (struct sockaddr *)&serv, sizeof(serv)); // bind the server to the socket
    listen(sd, 0); // prepare to accept connections
    int nsd;
    int len = sizeof(cli);
    nsd = accept(sd, (struct sockaddr *)&cli, (unsigned int *)&len); //accept connections
    char buf[100];
    read(nsd, buf, sizeof(buf)); // read the client request
    write(1, buf, sizeof(buf)); // write response to standard output
    write(nsd, "This is msg from server\n", sizeof("This is msg from server\n"));
    close(sd);
    return(0);
}