/*
 * pipas.c
 * 
 * Copyright 2016 copyleft <copyleft@debian>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#define SIZE 512

int main(int argc, char **argv)
{
	pid_t pid;
	int p[2], readbytes;
	char buffer[SIZE];
	
	pipe(p);
	if((pid = fork())== 0)
	{
		close(p[1]);
		while((readbytes = read(p[0],buffer,SIZE))>0)
			write(1,buffer,readbytes);
		close(p[0]);
	}
	else
	{
		close(p[0]);
		strcpy(buffer, "Esto llega desde la tuberia\n");
		write(p[1],buffer,strlen(buffer));
		close(p[1]);
	}
	waitpid(pid,NULL,0);
	return 0;
}

