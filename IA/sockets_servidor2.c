#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUERTO 5000
#define SIZE 255

int main(int argc, char *argv[])
{
  int mi_socket, tam, numbytes;
  char buffer[SIZE];
  struct sockaddr_in mi_estructura;

  mi_estructura.sin_family = AF_INET;
  mi_estructura.sin_port = htons(PUERTO);
  mi_estructura.sin_addr.s_addr = INADDR_ANY;
  memset(&(mi_estructura.sin_zero),'\0', 8);

  mi_socket = socket(AF_INET,SOCK_DGRAM, 0);
  tam = sizeof(struct sockaddr);
  bind(mi_socket,(struct sockaddr *)&mi_estructura, tam);

  while(1)
    {
      numbytes = recvfrom(mi_socket, buffer, SIZE-1, 0, (struct sockaddr *)&mi_estructura, &tam);
      buffer[numbytes] = '\0';

      printf("Server UDP: %d bytes recibidos\n", numbytes);
      printf("Server UDP: recibido:%s\n", buffer);
    }
  close(mi_socket);
  return 0;
}
