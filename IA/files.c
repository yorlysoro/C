#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int fd1;
  int fd2;
  char buffer[1024];
  ssize_t n;

  if(argc != 3)
    {
      printf("Uso: %s origen destino\n", argv[0]);
      exit(1);
    }
  fd1 = open(argv[1], O_RDONLY);

  if(fd1 == -1)
    {
      perror("open 1");
      exit(1);
    }
  fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
  if(fd2 == -1)
    {
      perror("open 2");
      exit(1);
    }
  do
    {
      n = read(fd1, (void *) buffer, sizeof(buffer));
      if(n > 0)
	if(write(fd2, (void *)buffer, n) != n)
	  perror("write");
    }while(n > 0);
  (void) close(fd1);
  (void) close(fd2);
  exit(0);
}
