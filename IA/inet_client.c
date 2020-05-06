#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MSGSIZE 255

#define SERVER_PORT 9999

int main(int argc, char **argv)
{
  int sock_fd;
  int conn_fd;
  FILE *fd;
  int i;
  char buf[MSGSIZE];

  struct sockaddr_in *server_addr;

  int server_port;

  sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  if(sock_fd < 0){
    perror("Error: socket");
    exit(0);
  }

  server_addr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));

  memset(server_addr, 0, sizeof(struct sockaddr_in));

  server_port = SERVER_PORT;

  server_addr->sin_family = AF_INET;

  server_addr->sin_port = htons(server_port);

  if(inet_aton("127.0.0.1",&(server_addr->sin_addr)) < 0){
    perror("Error: invalid network addres");
    exit(0);
  }

  if(connect(sock_fd,(struct sockaddr *)server_addr, sizeof(struct sockaddr_in)) != 0){
    perror("Error:connect");
    exit(0);
  }

  while(1){
    memset(buf, 0, MSGSIZE);
    fgets(buf, 80, stdin);
    printf("Sent: %s\n", buf);
    send(sock_fd, buf, strlen(buf),0);

    if(strcmp(buf,"exit\n") == 0)
	break;

      memset(buf, 0, MSGSIZE);
      recv(sock_fd, buf, MSGSIZE,0);
      printf("received from server: %s\n", buf);

  }
  close(sock_fd);
}
