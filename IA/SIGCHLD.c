#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
void desvia(int sig)
{
  printf("Terminacion del proceso hijo %d\n", wait(NULL));
}

int main(void)
{
  struct sigaction action;
  int i;

  action.sa_handler = desvia;
  action.sa_flags = 0;
  //action.sa_mask = NULL;

  sigaction (SIGCHLD, &action, NULL);

  for(i = 0; i < 5; i++)
    {
      switch(fork())
	{
	case 0:
	  sleep(1);
	  exit(0);
	  break;
	default:
	  pause();
	}
    }
  return 0;
}
