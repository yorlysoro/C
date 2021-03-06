#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

const char * shmem_name = "/urandom";
const char * full_name = "/full_sem";
const char * empty_name = "/empty_sem";
const char * mutex_name = "/mutex_sem";

void handle_sigint(int num);

void cleanup(void);

#define N 10

int fd;
sem_t * empty;
sem_t * full;
sem_t * mutex;

int main(int argc, char **argv)
{
  int buf[N];
  int i;

  int *ptr;

  struct sigaction new_action;

  srand(time(NULL));

  new_action.sa_handler = handle_sigint;
  sigemptyset(&new_action.sa_mask);
  new_action.sa_flags = 0;

  sigaction(SIGINT, &new_action, 0);

  if((empty = sem_open(empty_name, O_CREAT | O_RDWR, S_IRWXU, 0)) == SEM_FAILED){
    sem_unlink(empty_name);
    perror("sem_open");
    exit(0);
  }

  if((full = sem_open(full_name, O_CREAT | O_RDWR, S_IRWXU, 0)) == SEM_FAILED){
    sem_unlink(empty_name);
    perror("sem_open");
    exit(0);
  }

  if((mutex = sem_open(mutex_name, O_CREAT| O_RDWR, S_IRWXU, 0)) == SEM_FAILED){
    sem_unlink(empty_name);
    sem_unlink(full_name);
    perror("sem_open");
    exit(0);
  }
  if((fd = shm_open(shmem_name, O_CREAT | O_RDWR, S_IRWXU)) == -1)
    {
      sem_unlink(empty_name);
      sem_unlink(full_name);
      sem_unlink(mutex_name);
      perror("open");
      exit(1);
    }

  ftruncate(fd, sizeof(int) * N);

  if((ptr = mmap(0, sizeof(int) * N, PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1){
    cleanup();
    perror("mmap");
    exit(1);
  }

  while(1)
    {
      for(i = 0; i < N; i++)
	buf[i] = rand() % N;
      sem_wait(empty);
      sem_wait(mutex);

      memcpy(ptr, buf, sizeof(int) * N);

      sem_post(mutex);
      sem_post(full);
    }
  close(fd);

  cleanup();
  exit(0);
}

void handle_sigint(int num)
{
  cleanup();
  exit(1);
}

void cleanup(){
  shm_unlink(shmem_name);
  sem_unlink(empty_name);
  sem_unlink(full_name);
  sem_unlink(mutex_name);
}
