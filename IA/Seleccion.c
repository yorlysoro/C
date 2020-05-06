/*
 * Seleccion.c
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

int main(int argc, char **argv)
{
	int x,y,aux,minimo;
	int lista[6] = {4,2,6,5,1,3};
	for(x = 0; x < 6; x++)
	{
		printf("%d ", lista[x]);
	}
	putchar('\n');
	for(x = 0; x < 6; x++)
	{
		minimo = x;
		for(y = x; y < 6; y++)
		{
			if(lista[y] < lista[minimo])
				minimo = y;
		}
		aux = lista[x];
		lista[x] = lista[minimo];
		lista[minimo] = aux;
	}
	for(x = 0; x < 6; x++)
	{
		printf("%d ", lista[x]);
	}
	putchar('\n');
	return 0;
}

