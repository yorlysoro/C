/*
 * Busqueda_Lineal.c
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
int FnIntBusquedaLineal(int lista[],int dato);
void SbBuscar(int lista[], int dato);
int main(int argc, char **argv)
{
	int lista[6] = {4,2,6,5,1,3};
	
	SbBuscar(lista,5);
	return 0;
}

int FnIntBusquedaLineal(int lista[],int dato)
{
	int x;
	for(x = 0; x < 6; x++)
	{
		if(lista[x] == dato)
			return x;
	}
	return 0;
}

void SbBuscar(int lista[], int dato)
{
	if(!FnIntBusquedaLineal(lista,dato))
		puts("No se encontro el dato");
	else
		printf("Se encontro el dato en la posicion %d\n", FnIntBusquedaLineal(lista,dato));
}
