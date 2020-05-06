#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if(pid == -1)
		perror("fork");
	else if(pid == 0)
		printf("proceso hijo con pid = %d\n", pid);
	else
		printf("proceso padre con pid = %d\n", pid);
} 
