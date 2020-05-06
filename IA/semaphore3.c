#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void up(sem_t *s){
  sem_post(s);
}

void down(sem_t *s){
  sem_wait(s);
}

sem_t s;
#define MAXTHREADS 5

void thread(void *arg){
  int myId;
  int i;

  myId = *((int *) arg);

  printf("Thread %d started\n", myId);

  sleep(rand() % 5);
  printf("Thread %d attempting to use semaphore\n", myId);
  down(&s);

  printf("Thread %d has the semaphore!\n", myId);
  sleep(rand() % 3);

  printf("Thread %d releasing the semaphore\n", myId);
  up(&s);

  printf("Thread %d finished\n", myId);
}

int main(int argc, char **argv)
{
  int i;
  pthread_t t[MAXTHREADS];
  int id[MAXTHREADS];

  printf("Main Started\n");

  srand(10000);

  sem_init(&s, 0,1);
  for(i=0; i < MAXTHREADS; i++)
    {
      id[i] = i;
      pthread_create(&t[i], 0, (void *)thread, (void *)&id[i]);
    }

  printf("Waiting for threads to exit...\n");

  for(i=0; i < MAXTHREADS; i++)
    {
      pthread_join(t[i], 0);
    }

  printf("Main Finished\n");
}
