#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXSIZE 512

const char *addr_name = "mysocket";

typedef struct{
  int code;
  char data[MAXSIZE];
}message;

void handle_connection(int client_fd, struct sockaddr * client_addr);

int main(int argc, char *argv[])
{
  int s;
  int c;

  struct sockaddr_in addr;
  struct sockaddr client_addr;
  int client_addr_size;

  if((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror("socket");
      exit(1);
    }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(1234);

  if(inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr) <= 0)
    {
      perror("inet_pton");
      exit(1);
    }

  if(bind(s,(struct sockaddr *)&addr, sizeof(struct sockaddr_in)) != 0)
    {
      perror("bind");
      exit(1);
    }

  if(listen(s,10) != 0)
    {
      perror("Listen");
      exit(1);
    }

  while(1)
    {
      c = accept(s, &client_addr, &client_addr_size);
      if(fork() == 0)
	handle_connection(c, &client_addr);
    }

}

void handle_connection(int client_fd, struct sockaddr * addr){
  message m;

  struct sockaddr_in * client_addr;

  client_addr = (struct sockaddr_in *)addr;

  printf("Client connected from %s at port %d\n", inet_ntoa(client_addr->sin_addr.s_addr), ntohs(client_addr->sin_port));
  while(1)
    {
      if(recv(client_fd, (void *)&m, sizeof(message), 0) < 0)
	{
	  printf("Server recv error\n");
	  break;
	}

      m.code = 1;

      if(send(client_fd, (void *)&m, sizeof(message), 0) < 0)
	{
	  printf("Server send error\n");
	  break;
	}
    }
  printf("Cliente connection finished\n");
  close(client_fd);
}
