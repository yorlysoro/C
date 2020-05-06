#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <linux/types.h>
#include <linux/dirent.h>
#include <linux/unistd.h>

void main(void)
{
  int dir;
  struct dirent *dp;
  char buf[1024];
  int i,n;

  dir = open(".", O_RDONLY);
  if(dir == -1){
    perror("open");
    exit(1);
  }
  n = getdents(dir, buf, sizeof(buf));
  if(n == -1)
    {
      perror("getdents");
      exit(1);
    }
  while(n > 0)
    {
      i = 0;
      while(i < n)
	{
	  dp = (struct dirent *)(buf + i);
	  printf("%s\n", dp->d_name);
	  i += dp->d_reclen;
	}
      n = getdents(dir, buf, sizeof(buf));
      if(n == -1)
	{
	  perror("getdents");
	  exit(1);
	}
    }
  (void)close(dir);
  exit(0);
}
