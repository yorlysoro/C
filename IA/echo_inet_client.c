#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXSIZE 512

const char *addr_name = "mysocket";

typedef struct {
  int code;
  char data[MAXSIZE];
}message;

int main(int argc, char **argv)
{
  int s;
  int c;
  message *msg;
  char line[MAXSIZE];

  struct sockaddr_in addr;

  if((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror("Socket");
      exit(1);
    }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(1234);

  if(inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr) <= 0)
    {
      perror("inet_pton");
      exit(1);
    }

  msg = (message *)malloc(sizeof(message));

  while(1)
    {
      msg->code = 2;
      memset(msg->data, 0, MAXSIZE);

      memset(line, 0, MAXSIZE);
      fgets(line, MAXSIZE - 1, stdin);

      if(strlen(line) <= 1)
	continue;

      strncpy(msg->data, line, MAXSIZE);

      if(send(s, (void *)msg, sizeof(message), 0) < 0)
	{
	  printf("Client send error\n");
	  break;
	}

      printf("Sent: %d %s\n", msg->code, msg->data);

      if(recv(s, (void *)msg, sizeof(message), 0) < 0)
	{
	  printf("Client receive error\n");
	  break;
	}

      printf("Received: %d %s\n", msg->code, msg->data);

    }
  close(c);
  printf("Finished\n");
}
