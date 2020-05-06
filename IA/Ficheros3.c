/*
 * Ficheros3.c
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

int main(int argc, char **argv)
{
	FILE *fichero;
	char cont_arch[100];
	
	fichero = fopen("palabras.txt", "r");
	
	if(!fichero)
	{
		fputs("No se pudo leer el archivo",stderr);
		exit(1);
	}
	else
	{
		puts("Este es el contenido del archivo:");
		while(!ferror(fichero) && !feof(fichero))
		{
			fread(cont_arch,sizeof(char),100,fichero);
			printf("%s", cont_arch);
		}
	}
	fclose(fichero);
	return 0;
}

