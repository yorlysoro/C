#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int main(int argc, char **argv)
{
  int shmid;
  key_t key;
  char *shm, *s;
  char message[255];

  mem_region * region;

  key = 1234;

  if((shmid = shmget(key, SHMSZ, 0666)) < 0)
    {
      perror("shmget:");
      exit(1);
    }

  if((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
      perror("shmat:");
      exit(1);
    }

  region = (mem_region *)shm;

  while(region->status != TERMINATED)
    {
      while(region->status != SERVER_SENT);
      strcpy(message, region->message);
      printf("%s\n", message);
      sprintf(region->message, "\tClient: You Sent: %s", message);
      region->status = CLIENT_SENT;
    }
  exit(0);
}
