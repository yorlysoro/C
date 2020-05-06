#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int x;
int turno;

void enter_region(int);
void leave_region(int);

void process_A(void *arg)
{
  while(1){
    enter_region(0);
    x++;
    printf(".");
    leave_region(0);
  }
}

void process_B(void *arg){
  while(1){
    enter_region(1);
    x--;
    printf(";");
    leave_region(1);
  }
}

int main(int argc, char **argv)
{
  pthread_t pA;
  pthread_t pB;

  printf("Main Started\n");

  x = 5;
  turno = 0;

  pthread_create(&pA, 0, (void *)process_A, 0);
  pthread_create(&pB, 0, (void *)process_B, 0);

  sleep(10);

  printf("Main Finished! x is %d\n", x);
}

void enter_region(int pid){
  while(pid != turno){
    printf("%d!", pid);
  }
}

void leave_region(int pid){
  turno = 1 - pid;
}
