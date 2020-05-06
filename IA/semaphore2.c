#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void enter_region();
void leave_region();

int x = 5;

void process_A(void *arg){
  while(1){
    enter_region();
    x++;
    printf(".");
    sleep(rand() % 5);
    leave_region();
  }
}

void process_B(void *arg)
{
  while(1)
    {
      enter_region();
      x--;
      printf(";");
      sleep(rand() % 5);
      leave_region();
    }
}

void up(sem_t *s){
  sem_post(s);
}

void down(sem_t *s){
  sem_wait(s);
}

sem_t mutex;

int main(int argc, char **argv)
{
  pthread_t pA;
  pthread_t pB;

  printf("Main Started\n");

  sem_init(&mutex, 0, 1);

  pthread_create(&pA, 0, (void *)process_A, 0);
  pthread_create(&pB, 0, (void *)process_B, 0);

  sleep(20);

  printf("Mai finished x is now %d\n", x);
  return 0;
}

void enter_region(void){
  down(&mutex);
}
void leave_region(void){
  up(&mutex);
}
