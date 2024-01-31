#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT        12345
#define BUFFER_SIZE 1024

void reverseString(char* str)
{
  int length = strlen(str);
  int i, j;
  char temp;

  for (i = 0, j = length - 1; i < j; ++i, --j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

int main(void)
{
  int sockfd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_len = sizeof(client_addr);
  char buffer[BUFFER_SIZE];

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("Create socket failed.");
    exit(1);
  }

  // Bind socket to address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("Bind failed.");
    close(sockfd);
    exit(1);
  }

  while (1) {
    // Receive string from the client
    memset(buffer, 0, sizeof(buffer));
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &addr_len);

    // Display client's IP address and port number
    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Reverse the received string
    reverseString(buffer);

    // Send reversed string back to the client
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, addr_len);
  }

  close(sockfd);
  return 0;
}
