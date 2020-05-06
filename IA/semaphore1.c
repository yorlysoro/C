#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void up(sem_t *s){
  sem_post(s);
}

void down(sem_t *s){
  sem_wait(s);
}

sem_t s1;

int main(int argc, char **argv[])
{
  int initval;
  int i;

  puts("Main started");

  puts("Please specify the initial value for the semphore");
  scanf("%d", &initval);

  sem_init(&s1, 0, initval);

  i = 1;

  while(1)
    {
      printf("Attem %d\n",  i++);
      down(&s1);
    }

  puts("Main Finished");
  return 0;
}
