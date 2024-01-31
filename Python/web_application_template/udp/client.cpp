#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT        12345
#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
    exit(1);
  }

  int sockfd;
  struct sockaddr_in server_addr;
  char buffer[BUFFER_SIZE];

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("Create socket failed.");
    exit(1);
  }

  // Send data to the server
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);

  while (1) {
    // Read string from command line
    printf("Enter a string (or type 'exit' to quit): ");
    fgets(buffer, sizeof(buffer), stdin);

    // Check for exit condition
    if (strncmp(buffer, "exit", 4) == 0) {
      break;
    }

    // Send string to the server
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Receive inverted string from the server
    memset(buffer, 0, sizeof(buffer));
    recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);

    // Display inverted string
    printf("Inverted string: %s", buffer);
  }

  close(sockfd);
  return 0;
}
