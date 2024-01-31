#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT      1234
#define BACKLOG   2
#define MAXDATASIZE 1000

void process_cli(int connectfd, struct sockaddr_in client);

int main(void) {
    int listenfd, connectfd;
    pid_t pid;
    struct sockaddr_in server, client;
    int sin_size;

    /* Create TCP Socket */
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed.");
        exit(1);
    }

    /* Initialize server address structure */
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    /* Bind server address to listenfd */
    if (bind(listenfd, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1) {
        perror("bind error.");
        exit(1);
    }

    /* Listen on listenfd */
    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen error.");
        exit(1);
    }

    sin_size = sizeof(struct sockaddr_in);
    while (1) {
        if ((connectfd = accept(listenfd, (struct sockaddr*)&client, &sin_size)) == -1) {
            perror("accept error.");
            exit(1);
        }

        if ((pid = fork()) > 0) {
            close(connectfd);
            continue;
        } else if (pid == 0) {
            close(listenfd);
            process_cli(connectfd, client);
            exit(0);
        } else {
            printf("fork error.\n");
            exit(0);
        }
    }

    close(listenfd);
    return 0;
}

void process_cli(int connectfd, struct sockaddr_in client) {
    int num;
    char recvbuf[MAXDATASIZE], sendbuf[MAXDATASIZE], cli_name[MAXDATASIZE];
    
    printf("You got a connection from %s.\n", inet_ntoa(client.sin_addr));
    
    num = recv(connectfd, cli_name, MAXDATASIZE, 0);
    if (num == 0) {
        close(connectfd);
        printf("Client disconnected.\n");
        return;
    }
    
    cli_name[num - 1] = '\0';
    printf("Client name is %s.\n", cli_name);

    while ((num = recv(connectfd, recvbuf, MAXDATASIZE, 0)) > 0) {
        recvbuf[num] = '\0';
        printf("Received client (%s) message: %s\n", cli_name, recvbuf);

        for (int i = 0; i < num - 1; i++)
            sendbuf[i] = recvbuf[num - i - 2];

        sendbuf[num - 1] = '\0';
        send(connectfd, sendbuf, strlen(sendbuf), 0);
    }

    close(connectfd);
}
