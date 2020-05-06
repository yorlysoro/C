#define STARTED 0
#define SERVER_SENT 1
#define CLIENT_SENT 2
#define TERMINATED 3

typedef struct mem_region{
  int status;
  int size;
  char message[255];
}mem_region;

#define SHMSZ sizeof(mem_region)
#define SHMKEY 1234
