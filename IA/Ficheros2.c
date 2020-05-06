/*
 * Ficheros2.c
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
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	FILE *fichero;
	
	char contenido[100];
	char arch_cont[100];
	
	fichero = fopen("palabras.txt", "r+");
	fseek(fichero,0L,SEEK_END);
	if(!fichero)
	{
		fputs("No se pudo crear el archivo",stderr);
		exit(1);
	}
	else
	{
		fgets(contenido,100,stdin);
		if(!fwrite(contenido,sizeof(char),100,fichero))
		{
			fputs("No se pudo agregar contenido al fichero", stderr);
			fclose(fichero);
			exit(2);
		}
		else
		{
			puts("Se agrego el contenido al archivo");
			fclose(fichero);
		}
	}
	if(!(fichero = fopen("palabras.txt","r")))
	{
		fputs("No se puede leer el fichero", stderr);
		fclose(fichero);
		exit(3);
	}
	else
	{
		while(!ferror(fichero) && !feof(fichero))
		{
			fread(arch_cont,sizeof(char),100,fichero);
			printf("%s", arch_cont);
			
		}
	}
	fclose(fichero);
	
	return 0;
}

