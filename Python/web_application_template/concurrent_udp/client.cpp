#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT      1234
#define MAXDATASIZE 1000

int main(void) {
    int sockfd;
    struct sockaddr_in server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Create socket failed.");
        exit(1);
    }

    /* Initialize server address structure */
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with the server's IP address

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1) {
        perror("Connection failed.");
        exit(1);
    }

    char hostname[MAXDATASIZE]; // You need to get the client's hostname here
    gethostname(hostname, sizeof(hostname));
    send(sockfd, hostname, strlen(hostname), 0);

    /* Send and receive data to/from the server */
    // ...

    close(sockfd);
    return 0;
}
