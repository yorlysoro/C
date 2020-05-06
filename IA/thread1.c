#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void rutina(void);
void *thread1(void *arg);

int main(int argc, char *arg[])
{
  pthread_t t;
  pthread_attr_t attr;
  printf("Hello from program\n");
  //rutina();
  //thread1(0);
  pthread_create(&t, 0, thread1, 0);
  rutina();
  printf("Bye from program\n");
  return 0;
}

void rutina(void)
{
  int i;
  printf("Entering rutina\n");
  for(i = 0; i < 10; i++)
    {
      printf("%d ", i);
      fflush(stdout);
      sleep(1);
    }
}

void * thread1(void *arg)
{
  char i;
  printf("Thread created\n");
  printf("Thread Finished\n");

  for(i = 'a'; i <= 'z'; i++)
    {
      printf("%c ", i);
      fflush(stdout);
      sleep(2);
    }
}
