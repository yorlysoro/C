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

  if(sock_fd < 0)
    {
      printf("Error: socket\n");
      exit(0);
    }

  myaddr = (struct sockaddr_un *)malloc(sizeof(struct sockaddr_un));

  memset(myaddr, 0, sizeof(struct sockaddr_un));

  myaddr->sun_family = AF_UNIX;
  strcpy(myaddr->sun_path, "mysocket");

  if(connect(sock_fd, (struct sockaddr *)myaddr, sizeof(struct sockaddr_un)) != 0){
      perror("Error: conecct");
      exit(0);
    }

    while(1){
      memset(buf, 0, MSGSIZE);
      fgets(buf, 80, stdin);
      printf("Sent: %s\n", buf);
      send(sock_fd, buf, strlen(buf), 0);

      if(strcmp(buf, "exit\n") == 0)
	{
	  break;
	}
      memset(buf,0,MSGSIZE);
      recv(sock_fd, buf, MSGSIZE,0);
      printf("Received from server:%s\n", buf);
    }
    close(sock_fd);
}
    
