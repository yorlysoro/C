#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "structs.h"

int main(int argc, char **argv)
{
  char c;
  int shmid;
  key_t key;
  char *shm, *s;
  char message[255];
  int i;

  mem_region *region;

  key = 1234;

  if((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
    {
      perror("shmget");
      exit(1);
    }

  if((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
      perror("shmat");
      exit(1);
    }

  region = (mem_region *)shm;
  i = 0;
  while(region->status != TERMINATED){
    sprintf(region->message,"hello %d", i);
    region->status = SERVER_SENT;

    while(region->status != CLIENT_SENT);
    strcpy(message, region->message);
    printf("%s\n", message);

    if(++i > 10)
      {
	region->status = TERMINATED;
      }
  }
  exit(0);
}
