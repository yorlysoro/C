/*
 * Quisort.c
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
int lista[6] = {4,2,6,5,1,3};
void Quisort(int lista[],int,int);
int main(int argc, char **argv)
{
	int x;
	for(x = 0; x < 6; x++)
	{
		printf("%d ", lista[x]);
	}
	putchar('\n');
	Quisort(lista,0,6);
	for(x = 0; x < 6; x++)
	{
		printf("%d ", lista[x]);
	}
	putchar('\n');
	return 0;
}
void Quisort(int lista[], int x, int y)
{
	int fin,inicio,pivote,aux;
	aux = 0;
	fin = y;
	inicio = x;
	pivote = lista[x];
	
	while(x <= y)
	{
		while(lista[x] < pivote)
			x += 1;
		while(lista[y] > pivote)
			y -= 1;
		if (x <= y)
		{
			aux = lista[x];
			lista[x] = lista[y];
			lista[y] = aux;
			x += 1;
			y -= 1;
		}
	}
	if(inicio < y)
		Quisort(lista,inicio,y);
	if(x < fin)
		Quisort(lista,x,fin);
}


