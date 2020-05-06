/*
 * pipas2.c
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
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 512
int main(int argc, char **argv)
{
	pid_t pid;
	int a[2], b[2], readbytes;
	char buffer[SIZE];
	pipe(a);
	pipe(b);
	
	if((pid = fork()) == 0)
	{
		close(a[1]);
		close(b[0]);
		
		while((readbytes = read(a[0], buffer, SIZE)) > 0)
			write(1,buffer,readbytes);
		close(a[0]);
		
		strcpy(buffer, "Hablando desde el hijo\n");
		write(b[1], buffer, strlen(buffer));
		close(b[1]);
	}
	else
	{
		close(a[0]);
		close(b[1]);
		strcpy(buffer, "Hablando desde el padre\n");
		write(a[1], buffer, strlen(buffer));
		close(a[1]);
		
		while((readbytes = read(b[0], buffer, SIZE)) > 0)
			write(1, buffer, readbytes);
		close(b[0]);
	}
	waitpid(pid,NULL,0);
	return 0;
}

