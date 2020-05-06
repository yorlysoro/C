/*
 * Busqueda_Binaria.c
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
int FnIntBusqueda_Binaria(int lista[], int dato);
void SbBuscar(int lista[], int dato);
int main(int argc, char **argv)
{
	int lista[6] = {4,2,6,5,1,3};
	SbBuscar(lista,3);
	return 0;
}

int FnIntBusqueda_Binaria(int lista[],int dato)
{
	int izquierda,derecha,medio;
	izquierda = 0;
	derecha = 5;
	while(izquierda <= derecha)
	{
		medio = (izquierda+derecha)/2;
		if(dato == lista[medio])
			return medio;
		else if (dato < lista[medio])
			derecha = medio - 1;
		else
			izquierda = medio + 1;
	}
	return 0;
}

void SbBuscar(int lista[],int dato)
{
	if(!FnIntBusqueda_Binaria(lista,dato))
		puts("No se encontro el dato");
	else
		printf("Se encontro el dato en la posicion %d\n", FnIntBusqueda_Binaria(lista,dato));
}
