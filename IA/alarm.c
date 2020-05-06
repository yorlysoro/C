#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void gestiona_alarma(int sig);

int tiempo;

int main(void)
{
  signal (SIGALRM, gestiona_alarma);
  while(1)
    {
      tiempo = 8;
      printf("Pulse sobre 'Intro' o el programa terminara");
      printf(" en 10 segundos\n");
      alarm(2);
      getchar();
      alarm(0);
    }
}

void gestiona_alarma(int sig)
{
  signal(SIGALRM, gestiona_alarma);
  alarm(2);
  if(tiempo)
    {
      printf("Le quedan %d segundos \n", tiempo);
      tiempo -= 2;
    }
  else
    {
      printf("Demasiado tarde, el programa termina\n");
      exit(1);
    }
}
