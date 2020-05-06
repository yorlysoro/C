#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void desvia(int sig);

int main(void)
{
  sigset_t mascara, pendientes;
  if(signal(SIGINT, desvia) == SIG_ERR)
    {
      perror("señal SIGINT no desviable");
      exit(1);
    }
      sigemptyset(&mascara);
      sigaddset(&mascara, SIGINT);
      if(sigprocmask(SIG_BLOCK, &mascara, NULL) < 0)
	{
	  perror("SIG_BLOCK en sigprocmask");
	  exit(1);
	}
      sleep(5);

      if(sigpending(&pendientes) < 0)
	{
	  perror("sigpending");
	  exit(1);
	}
      if(sigismember(&pendientes, SIGINT))
	printf("Señal SIGINT pendiente\n");
      if(sigprocmask(SIG_UNBLOCK, &mascara, NULL) < 0)
	{
	  perror("SIG_UNBLOCk en sigprocmask");
	  exit(1);
	}
      printf("Señal SIGINT desbloqueada\n");
      return 0;
}

void desvia(int sig)
{
  printf("Señal recibida: %s\n", strsignal(sig));
}
