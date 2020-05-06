/*
 * fork.c
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
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	pid_t pid;
	
	printf("hola desde el programa %d\n", getpid());
	
	printf("Esto es fork\n");
	pid = fork();
	
	if(pid == 0)
	{
		puts("NOOOOOOOOOOOO");
	}
	else
	{
		puts("I AM YOUR FATHER");
		execl("/bin/ls", "/bin/ls", "-l", (char *)0);
	}
	printf("Bye from program %d\n", getpid());
	return 0;
}

