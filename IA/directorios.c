#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include <dirent.h>
#include <stdlib.h>

int main(void)
{
    DIR *dir;
    struct dirent *dp;

    dir = opendir(".");
    if(dir == NULL){
	perror("opendir");
	exit(1);
    }

    dp = readdir(dir);
    while(dp != NULL){
        printf("%s\n", dp->d_name);
	dp = readdir(dir);
      }
    (void) closedir(dir);
    exit(0);
}
