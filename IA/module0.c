/*
 * module0.c
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
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	char linea[80];
	printf("Hello from task:%d\n", argc);
	for(i = 0;i<argc;i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	strcpy(linea,"");
	
	strcat(linea,"hello");
	strcat(linea," World\n");
	
	puts(linea);
	
	sprintf(linea, "Argc is:%d, Argv is at 0x%x\n", argc, &argv);
	
	puts(linea);
	
	printf("Bye from task PID = %d\n", getpid());
	return 0;
}

