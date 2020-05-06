#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define MSGSIZE 255

int main(int argc, char **argv)
{
  int sock_fd;
  int conn_fd;
  FILE *fd;
  int i;
  char buf[MSGSIZE];
  struct sockaddr_un *myaddr;
  sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);

  if(sock_fd<0)
    {
      printf("Error:socket\n");
      exit(0);
    }

  unlink("mysocket");

  myaddr = (struct sockaddr_un *)malloc(sizeof(struct sockaddr_un));

  memset(myaddr, 0, sizeof(struct sockaddr_un));

  myaddr->sun_family = AF_UNIX;
  strcpy(myaddr->sun_path, "mysocket");

  if(bind(sock_fd,(struct sockaddr *)myaddr, sizeof(struct sockaddr_un)) != 0)
    {
      printf("Error: bind\n");
      exit(0);
    }

  if(listen(sock_fd, 5) != 0){
    printf("Error:listen\n");
    exit(0);
  }

  conn_fd = accept(sock_fd, NULL, NULL);

  if(conn_fd < 0)
    {
      printf("Error:accept\n");
      exit(0);
    }

  while(1){
    memset(buf, 0, MSGSIZE);
    recv(conn_fd, buf, MSGSIZE, 0);
    printf("Received: %s\n",buf);

    if(strcmp(buf, "exit\n") == 0)
      break;
    memset(buf, 0, MSGSIZE);
    strcpy(buf, "ACK");
    send(conn_fd, buf, strlen(buf), 0);

  }
  close(conn_fd);
  close(sock_fd);
}
