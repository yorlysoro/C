/*
 * Ficheros.c
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

int main(int argc, char **argv)
{
	char nombre[11] = "datos.dat" , mensaje[81] = "";
	
	FILE *fichero;
	long int comienzo,final;
	
	fichero = fopen(nombre,"r");
	printf("Fichero:%s->", nombre);
	if(fichero)
		printf("existe(abierto)\n");
	else
	{
		printf("Error(No abierto)\n");
		return 1;
	}
	if((comienzo = ftell(fichero)) < 0)
		printf("Error:ftell no ha funcionado\n");
	else
		printf("Posicion del fichero: %ld\n\n", comienzo);
		
	fseek(fichero,0L,SEEK_END);
	final = ftell(fichero);
	
	fseek(fichero,0L,SEEK_SET);
	fgets(mensaje,80,fichero);
	printf("Tamano de fichero %s : %ld bytes\n", nombre, final-comienzo);
	printf("Mensaje del fichero: %s\n", mensaje);
	printf("\nTamano del mensaje usando strlen: %zd\n", strlen(mensaje));
	
	if(!fclose(fichero))
		printf("Fichero cerrado\n");
	else
	{
		printf("Error fichero no cerrado\n");
		return 1;
	}
	return 0;
}

