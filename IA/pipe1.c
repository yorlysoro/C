#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
  pid_t newpid;
  int fd[2];
  char message[255];
  int i;

  if(pipe(fd) != 0){
    printf("Error");
    exit(0);
  }

  /*
    fd[0] = lectura
    fd[1] = escritura
  */

  for(i = 0; i < 255; i++)
    {
      message[i] = 0;
    }
  printf("[%d] Program started\n", getpid());

  newpid = fork();

  if(newpid == 0){
    //hijo
    close(fd[1]);//cerrar el extremo de salida del hijo
    sleep(rand() % 10);
    printf("Attemting to read from parent...\n");
    read(fd[0], message, 255);
    printf("Read from parent: %s\n", message);
  }
  else
    {
      //padre
      close(fd[0]); //cerrar el extremo de entrada del padre
      strcpy(message, "Hello child!");
      sleep(rand() % 5);
      printf("Sending message to child\n");
      write(fd[1], message, strlen(message));
    }
  printf("[%d] Program Finished\n", getpid());
}
