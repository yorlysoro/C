#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define MAXSIZE 512

const char * addr_name = "mysocket";

typedef struct {
  int code;
  char data[MAXSIZE];
}message;

int main(int argc, char *argv[])
{
  int s;
  int c;
  message m;

  struct sockaddr_un addr;

  if((s = socket(PF_UNIX, SOCK_STREAM, 0)) == -1)
    {
      perror("Socket");
      exit(1);
    }
  addr.sun_family = AF_UNIX;
  strcpy(addr.sun_path, addr_name);

  if(bind(s, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) != 0)
    {
      perror("bind");
      unlink("mysocket");
      exit(1);
    }
  if(listen(s, 10) != 0)
    {
      perror("listen");
      unlink("mysocket");
      exit(1);
    }

  while(1)
    {
      c = accept(s, 0, 0);
      printf("Client connected\n");

      while(1)
	{
	  if(recv(c,(void *)&m, sizeof(message), 0) < 0)
	    {
	      printf("Server recv error\n");
	      break;
	    }
	  m.code = 1;

	  if(send(c,(void *)&m, sizeof(message), 0) < 0)
	    {
	      printf("Server send error\n");
	      break;
	    }
	}
      printf("Client connection finished\n");
      close(c);
    }
}
