#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define tratamiento_padre()
#define tratemiento_hijo()

void main(void)
{
  int pid;
  int d1;
  int d2;

  d1 = open("/bin/sh", O_RDONLY);
  if(d1 == -1){
    perror("open(padre)");
    exit(1);
  }
  printf("padre: posicion actual = %ld\n", (long)lseek(d1,(off_t)0,SEEK_CUR));
  pid = fork();
  if(pid == -1)
    {
      perror("fork");
      exit(1);
    }
  else if(pid == 0)
    {
      d2 = open("/bin/ls", O_RDONLY);
      if(d2 == -1)
	{
	  perror("open(hijo)");
	  exit(1);
	}
      printf("hijo:posicion actual = %ld\n",(long)lseek(d1,(off_t)0,SEEK_CUR));

      (void)lseek(d1,(off_t)1000,SEEK_SET);
      tratamiento_hijo();
    }
  else
    {
      sleep(5);
      printf("padre:posicion actual = %ld\n", (long)lseek(d1,(off_t)0,SEEK_CUR));
      tratamiento_padre();
    }
}
