#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <sched.h>
#include <unistd.h>
#include <errno.h>

#define STACKSIZE 16384

int start_clone(void (*fn) (void *), void *data)
{
  long retval;
  void *newstack;

  newstack = (void **)malloc(STACKSIZE);

  if(!newstack)
    return -1;

  newstack = (void *) (STACKSIZE + (char *) newstack);

  retval = clone(fn, newstack, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | SIGCHLD, 1, data);

  if(retval < 0){
    errno = -retval;
    retval = -1;
  }
  return retval;
}

int show_same_vm;

void cloned_process_starts_here(void *data)
{
  printf("child:\t got argument %d as fd\n", (int)data);
  show_same_vm = 5;
  printf("child:\t vm = %d\n", show_same_vm);
  close((int)data);
}

int main(void)
{
  int fd, pid;

  fd = open("/dev/null", O_RDONLY);
  if(fd < 0){
    perror("/dev/null");
    exit(1);
  }

  printf("mother:\t fd = %d\n", fd);
  show_same_vm = 10;
  printf("mother:\t vm = %d\n", show_same_vm);
  pid = start_clone(cloned_process_starts_here, (void *) fd);
  if(pid < 0)
    {
      perror("start_clone");
      exit(1);
    }
  sleep(1);
  printf("mother:\t vm = %d\n", show_same_vm);
  if(write(fd, "c", 1) < 0)
    printf("mother:\t child closed our file descriptor\n");
  exit(0);

}
