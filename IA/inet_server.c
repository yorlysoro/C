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

  int server_port;

  struct sockaddr_in *server_addr;
  struct sockaddr_in *client_addr;
  int client_addrlen;

  int n;

  sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  if(sock_fd < 0){
    perror("socket");
    exit(0);
  }

  server_port = SERVER_PORT;

  server_addr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));

  memset(server_addr, 0, sizeof(struct sockaddr_in));

  server_addr->sin_family = AF_INET;

  server_addr->sin_port = htons(server_port);

  if(inet_aton("127.0.0.1", &(server_addr->sin_addr)) < 0)
    {
      perror("Error: invalid network address");
      exit(0);
    }

  if(bind(sock_fd, (struct sockaddr *)server_addr, sizeof(struct sockaddr_in)) != 0){
    perror("Bind");
    exit(0);
  }

  if(listen(sock_fd, 5) != 0)
    {
      perror("Listen");
      exit(0);
    }

  printf("Server Listening at port %d\n", server_port);


  client_addr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
  client_addrlen = sizeof(struct sockaddr_in);

  conn_fd = accept(sock_fd, (struct sockaddr *)client_addr, (socklen_t *)&client_addrlen);

  if(conn_fd < 0)
    {
      perror("Accept");
      exit(0);
    }

  printf("Connected from: %s on port %d\n", inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));

  while(1){
    memset(buf, 0, MSGSIZE);
    n = recv(conn_fd, buf, MSGSIZE, 0);

    if(n == 0)
      {
	printf("Connection Closed\n");
	break;
      }
    printf("Received: %s\n", buf);

    if(strcmp(buf, "exit\n") == 0)
      break;
    send(conn_fd,buf,strlen(buf),0);
  }
  close(conn_fd);
  close(sock_fd);
}
