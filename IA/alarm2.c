#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>


void gestiona_alarma(int sig);

int tiempo;

int main(void)
{
  struct itimerval mi_alarma;

  mi_alarma.it_interval.tv_sec = 2;
  mi_alarma.it_interval.tv_usec = 0;

  signal(SIGALRM, gestiona_alarma);
  while(1)
    {
      tiempo = 8;
      printf("Pulse sobre 'Intro' o el programa terminara");
      printf(" en 10 segundos\n");
      mi_alarma.it_value.tv_sec = 2;
      mi_alarma.it_value.tv_usec = 0;
      setitimer(ITIMER_REAL, &mi_alarma, NULL);
      getchar();
      mi_alarma.it_value.tv_sec = 0;
      mi_alarma.it_value.tv_usec = 0;
      setitimer(ITIMER_REAL, &mi_alarma, NULL);
    }
}

void gestiona_alarma(int sig)
{
  signal(SIGALRM, gestiona_alarma);
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
