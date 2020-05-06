/*
 * directorio2.c
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
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *mi_dirent;
	
	if(argc != 2)
	{
		printf("%s:%s directorio\n", argv[0], argv[0]);
		exit(-1);
	}
	if((dir = opendir(argv[1])) == NULL)
	{
		perror("opendir");
		exit(-1);
	}
	while((mi_dirent = readdir(dir))!= NULL)
		printf("%s\n",mi_dirent->d_name);
		
	closedir(dir);
	return 0;
}

