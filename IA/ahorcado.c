/*
 * ahorcado.c
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
#include <ctype.h>
#include <unistd.h>
#include <time.h>
typedef struct 
{
	char nombre[50];
	int puntos;
}Ficha;

void presentacion(void);
int menu(int opc);
void menu_avanzado(void);
void anadir(void);
void borrar(void);
void ver(void);
void palabra(void);
void puntuacion(void);
void jugar(Ficha jugador);
void nombre(void);
void pantalla_juego(void);
void juego_nuevo(void);
void cargar_juego(void);
void fallo(void);

int posicion = 0;

int main(int argc, char **argv)
{
	int opcion;
	presentacion();
	do
	{
		opcion = menu(opcion);
		switch(opcion)
		{
			case 1: juego_nuevo(); break;
			case 2: cargar_juego(); break;
			case 3: puntuacion(); break;
			case 4: menu_avanzado(); break;
		}
	}while(opcion < 5); 
	return 0;
}
void presentacion(void)
{
	puts("------------------------------------------------");
	puts("\tJUEGO DEL AHORCADO");
	puts("------------------------------------------------");
	sleep(2);
}

int menu(int opc)
{
	char elegir;
	puts("--------------------------------------------------");
	puts("\tEL AHORCADO");
	puts("N)ueva partida");
	puts("C)argar partida");
	puts("V)er puntuaciones");
	puts("O)pciones avanzadas");
	puts("S)alir");
	puts("---------------------------------------------------");
	
	do
	{
		elegir = toupper(getchar());
		switch(elegir)
		{
			case 'N':opc=1;break;
			case 'C':opc=2;break;
			case 'V':opc=3;break;
			case 'O':opc=4;break;
			case 'S':opc=5;break;
			default :opc=0;
		}
	}while(opc < 1);
	return opc;
}

void juego_nuevo(void)
{
	FILE *fichero_nombres;
	FILE *fichero;
	
	long grandaria;
	char entra_nombre[50];
	char palabra[50];
	int nombre_ocupado,intentos = 0;
	Ficha datos;
	
	fichero = fopen("palabras.dat", "rb");
	
	fseek(fichero,0,SEEK_END);
	grandaria = ftell(fichero)/sizeof(palabra);
	if(grandaria==0)
	{
		puts("--------------------------------------");
		puts("\tNO HAY PALABRAS REGISTRADAS");
		puts("--------------------------------------");
		fclose(fichero);
		return;
	}
	if((fichero_nombres=fopen("jugadores.dat", "rb")) == NULL)
	{
		puts("No se puede abrir el archivo de lectura");
		exit(1);
	}
	do
	{
		nombre_ocupado = 0;
		do
		{
			nombre();
			fflush(stdin);
			scanf("%[^\n]", entra_nombre);
		}while(entra_nombre[0] == '\0');
		fread(&datos,sizeof(Ficha),1,fichero_nombres);
		while(!ferror(fichero_nombres) && !feof(fichero_nombres) && nombre_ocupado != 1)
		{
			if(strcmp(datos.nombre,entra_nombre) == 0)
			{
				nombre_ocupado = 1;
			}
			else
				fread(&datos,sizeof(Ficha),1,fichero_nombres);
		}
		if(nombre_ocupado==1)
		{
			puts("------------------------------------------");
			puts("Nombre ocupado prueba con otro");
			puts("------------------------------------------");
			sleep(1);
			intentos++;
			rewind(fichero_nombres);
		}
		if(intentos == 3)
		{
			fclose(fichero_nombres);
			return;
		}
	}while(nombre_ocupado != 0);
	
	datos.puntos = 0;
	
	strcpy(datos.nombre,entra_nombre);
	fclose(fichero_nombres);
	jugar(datos);
}

void nombre(void)
{
	puts("-----------------------------------------");
	puts("Introduzca un nombre");
	puts("-----------------------------------------");
}

void jugar(Ficha jugador)
{
	FILE *fichero;
	FILE *fichero_nombres;
	FILE *temporal;
	
	char abecedario[] = "ABCDEFGHIJKLMNOPQRSTVWXYZ";
	char caracter,opcion,borrarcaracter;
	char palabra[50];
	long grandaria;
	int fallos = 0;
	int x,aciertos,siesta=0,esta=0,p;
	Ficha registros;
	fichero = fopen("palabras.dat", "rb");
	fseek(fichero,0,SEEK_END);
	grandaria = ftell(fichero)/sizeof(palabra);
	pantalla_juego();
	
	do
	{
		srand(time(NULL));
		grandaria = (long) rand() + 1 % 20;
		fseek(fichero,sizeof(palabra)*grandaria,SEEK_SET);
		fread(palabra,sizeof(char),50,fichero);
		printf("%26.9s", jugador.nombre);
		printf("%26.11d\n",jugador.puntos);
		for(x=0;x<strlen(palabra);x++)
		{
			putchar('*');
		}
		x = 0;
		aciertos = 0;
		for(p=0;p<28;p++)
		{
			if(abecedario[p] != '\0')
			{
				printf("%5c", abecedario[p]);
			}
		}
		do
		{
			do
			{
				esta = 0;
				do
				{
					do
					{
						puts("Introduce una letra: ");
						fflush(stdin);
						caracter=toupper(getchar());
						borrarcaracter = getchar();
					}while(borrarcaracter=='\b');
				}while(!isupper(caracter));
				x = 0;
				while(abecedario[x] != '\0')
				{
					if(abecedario[x] == caracter)
					{
						esta = 1;
						abecedario[x] = '*';
						if(caracter == '*')
						{
							abecedario[x+1] = '*';
						}
					}
					x++;
				}
				x = 0;
				if(esta == 0)
				{
					puts("Letra introducida anteriormente");
				}
			}while(esta != 1);
			while(x <= strlen(palabra));
			{
				if(palabra[x] == caracter)
				{
					printf("%c\n", caracter);
					siesta = 1;
					aciertos++;
				}
				x++;
			}
			if(siesta ==0)
			{
				fallos++;
				fallo();
			}
			siesta = 0;
			for(p = 0; p < 27;p++)
			{
				printf("%c", abecedario[p]);
			}
		}while(fallos<8 && aciertos<strlen(palabra));
		if(fallos == 8)
		{
			puts("HAS PERDIDO");
			sleep(2);
		}
		if(aciertos == strlen(palabra))
		{
			puts("\tHAS GANADO");
			jugador.puntos++;
			printf("%26.11d", jugador.puntos);
			sleep(2);
		}
		for(x =0; x < strlen(palabra);x++)
		{
			printf("%26.15s", " ");
		}
		do
		{
			do
			{
				do
				{
					puts("Quieres seguir jugando?[s/n]");
					opcion=toupper(getchar());
					borrarcaracter=getchar();
				}while(borrarcaracter == '\b');
			}while(opcion != 'S' && opcion != 'N');
		}while(opcion != 'N' && opcion != 'S');
		if(opcion == 'S')
		{
			puts("Ahorcado");
			strcpy(abecedario, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
			fallos = 0;
		}
		posicion = 0;
	}while(opcion != 'N');
	
	fichero_nombres = fopen("jugadores.dat", "a+b");
	temporal = fopen("temporal", "wb");
	fread(&registros,sizeof(Ficha),1,fichero_nombres);
	while(!ferror(fichero_nombres) && !feof(fichero_nombres))
	{
		if(strcmp(registros.nombre,jugador.nombre) != 0)
		{
			fwrite(&registros,sizeof(Ficha),1,temporal);
		}
		fread(&registros,sizeof(Ficha),1,fichero_nombres);
	}
	fwrite(&jugador,sizeof(Ficha),1,temporal);
	
	fclose(temporal);
	fclose(fichero_nombres);
	fclose(fichero);
	remove("jugadores.dat");
	rename("temporal", "jugadores.dat");
			
}

void pantalla_juego(void)
{
	Ficha ficha;

	puts("--------------------------------------------");
	puts("\tEL AHORCADO");
	puts("---------------------------------------------");
	printf("Nombre: %s\n", ficha.nombre);
	printf("Puntos: %d\n", ficha.puntos);
	puts("----------------------------------------------");
}

void fallo(void)
{
	puts("------------------------------------------------");
	puts("\tFALLASTES");
	puts("-------------------------------------------------");
	if(posicion==8) 
		posicion = 0;
}

void cargar_juego(void)
{
	FILE *fichero_nombres;
	FILE *fichero;
	FILE *fichero_jugadores;
	
	char entra_nombre[50];
	char palabra[50];
	long grandaria;
	int nombre_ocupado,intentos=0;
	Ficha datos;
	
	fichero_jugadores = fopen("jugadores.dat", "rb");
	
	fseek(fichero_jugadores,0,SEEK_END);
	grandaria=ftell(fichero_jugadores)/sizeof(palabra);
	
	if(grandaria == 0)
	{
		puts("No ha jugadores registrados");
		sleep(2);
		fclose(fichero_jugadores);
		return;
	}
	fclose(fichero_jugadores);
	fichero = fopen("palabras.dat", "rb");
	
	fseek(fichero,0,SEEK_END);
	grandaria=ftell(fichero)/sizeof(palabra);
	if(grandaria == 0)
	{
		puts("No hay palabras registradas");
		sleep(2);
		fclose(fichero);
		return;
	}
	
	if((fichero_nombres=fopen("jugadores.dat","a+b")) == NULL)
	{
		puts("No se pudo abrir el fichero de lectura");
		exit(1);
	}
	do
	{
		nombre_ocupado = 0;
		do
		{
			nombre();
			fflush(stdin);
			scanf("%[^\n]", entra_nombre);
		}while(entra_nombre[0] == '\0');
		fread(&datos,sizeof(Ficha),1,fichero_nombres);
		while(!ferror(fichero_nombres) && !feof(fichero_nombres) && nombre_ocupado != 1)
		{
			if(strcmp(datos.nombre,entra_nombre) == 0)
			{
				nombre_ocupado = 1;
			}
			else
				fread(&datos,sizeof(Ficha),1,fichero_nombres);
		}
		if(nombre_ocupado == 0)
		{
			puts("Nombre no encontrado.Prueba con otro");
			sleep(1);
			intentos++;
			rewind(fichero_nombres);
		}
		if(intentos==3)
		{
			fclose(fichero_nombres);
			return;
		}
	}while(nombre_ocupado!=1);
	jugar(datos);
}

void puntuacion(void)
{
	int i = 0;
	Ficha registro,aux;
	FILE *fichero;
	FILE *temporal;
	FILE *temporal_malo;
	
	temporal_malo = fopen("temṕ_malo", "w+b");
	temporal = fopen("temporal", "w+b");
	fichero = fopen("jugadores.dat", "a+b");
	
	fread(&aux,sizeof(Ficha),1,fichero);
	if(!ferror(fichero) && !feof(fichero))
	{
		do
		{
			fread(&registro,sizeof(Ficha),1,fichero);
			while(!ferror(fichero) && !feof(fichero))
			{
				if(aux.puntos>registro.puntos)
				{
					fread(&registro,sizeof(Ficha),1,fichero);
				}
				else
				{
					strcpy(aux.nombre,registro.nombre);
					aux.puntos = registro.puntos;
					fread(&registro,sizeof(Ficha),1,fichero);
				}
			}
			fwrite(&aux,sizeof(Ficha),1,temporal);
			
			rewind(fichero);
			fread(&registro,sizeof(Ficha),1,fichero);
			while(!ferror(fichero) && !feof(fichero))
			{
				if(strcmp(registro.nombre,aux.nombre) != 0)
				{
					fwrite(&registro,sizeof(Ficha),1,temporal_malo);
				}
				fread(&registro,sizeof(Ficha),1,fichero);
			}
			fclose(fichero);
			fclose(temporal_malo);
			remove("jugadores.dat");
			rename("temp_malo", "jugadores.dat");
			
			fichero=fopen("jugadores.dat", "a+b");
			temporal_malo = fopen("temp_malo", "w+b");
			fread(&aux,sizeof(Ficha),1,fichero);
		}while(!ferror(fichero) && !feof(fichero));
		fclose(fichero);
		fclose(temporal_malo);
		fclose(temporal);
		remove("jugadores.dat");
		remove("temp_malo");
		rename("temoral", "jugadores.dat");
		
		fichero = fopen("jugadores.dat", "a+b");
		puts("\tLista de jugadores");
		fread(&registro,sizeof(Ficha),1,fichero);
		i = 0;
		while(!feof(fichero))
		{
			i++;
			if(i %21==0)
			{
				
				puts("Pulse cualquier tecla para seguir");
				getchar();
				puts("Lista de jugadores");
				i = 1;
			}
			printf("%10.2s ", registro.nombre);
			printf("%60.2d\n", registro.puntos);
			fread(&registro,sizeof(Ficha),1,fichero);
			fflush(stdin);
		}
		getchar();
		fclose(fichero);
	}
	else
	{
		fclose(temporal);
		fclose(temporal_malo);
		fclose(fichero);
		remove("temporal");
		remove("temp_malo");
		remove("jugadores.dat");
		puts("Jugador no registrado");
		sleep(2);
	}
}

void menu_avanzado(void)
{
	char opcion;
	int elegir;
	do
	{
		puts("-----------------------------------------------");
		puts("\tEL AHORCADO");
		puts("A)nadir palabras");
		puts("B)orrar palabras");
		puts("V)er palabras");
		puts("S)alir");
		puts("MENU DE OPCIONES AVANZADAS");
		puts("-------------------------------------------------");
		do
		{
			opcion = toupper(getchar());
			switch(opcion)
			{
				case 'A' : elegir=1;break;
				case 'B' : elegir=2;break;
				case 'V' : elegir=3;break;
				case 'S' : elegir=4;break;
				default : elegir=0;
			}
		}while(elegir<1);
		if(elegir==1) anadir();
		if(elegir==2) borrar();
		if(elegir==3) ver();
	}while(elegir!=4);
}


void anadir(void)
{
	FILE *fichero;
	
	char entra_palabra[50];
	char buscar_palabra[50];
	char opci,borrarcaracter,comprobar;
	int x,i,p;
	
	do
	{
		for(i = 0; i < 50; i++)
		{
			entra_palabra[i] = '\0';
			buscar_palabra[i] = '\0';
		}
		if((fichero=fopen("palabras.dat","a+b")) == NULL)
		{
			puts("No se pudo abrir el fichero");
			exit(1);
		}
		x = 0;
		do
		{
			p = 0;
			comprobar = 0;
			do
			{
				palabra();
				fflush(stdin);
				scanf("%[^\n]", entra_palabra);
			}while(entra_palabra[0] == '\0');
			while(entra_palabra[p] != '\0')
			{
				entra_palabra[p] = toupper(entra_palabra[p]);
				if(!isalpha(entra_palabra[p]))
				{
					puts("No pueden haber espacios ni caracteres en la palabra");
					sleep(2);
					comprobar = 1;
					entra_palabra[p] = '\0';
				}
				else p++;
			}
		}while(comprobar != 0);
		fread(buscar_palabra,sizeof(char),50,fichero);
		while(!feof(fichero) && x != 1)
		{
			if(strcmp(entra_palabra,buscar_palabra)== 0)
			{
				puts("Esta palabra ya existe en el fichero");
				x = 1;
				sleep(1);
			}
			fread(buscar_palabra,sizeof(char),50,fichero);
		}
		if(x == 0)
		{
			fwrite(entra_palabra,sizeof(char),50,fichero);
			fclose(fichero);
			puts("La palabra se anadido con exito");
			sleep(2);
		}
		else
		{
			fclose(fichero);
		}
		do
		{
			do
			{
				puts("Quieres anadir otras palabras[s/n]?");
				fflush(stdin);
				opci=toupper(getchar());
				borrarcaracter=getchar();
			}while(borrarcaracter=='\b');
		}while(opci != 'S' && opci != 'N');
	}while(opci!='N');
}

void palabra(void)
{
	puts("-----------------------------------------------------");
	puts("INTRODUZCA LA PAlABRA");
	puts("------------------------------------------------------");
}

void borrar(void)
{
	FILE *fichero;
	FILE *temporal;
	
	char entra_palabra[50];
	char buscar_palabra[50];
	char opci,borrarcaracter;
	int i,comprobar = 0;
	
	do
	{
		comprobar = 0;
		for(i = 0; i < 50; i++)
		{
			entra_palabra[i] = '\0';
			buscar_palabra[i] = '\0';
		}
		if((fichero=fopen("palabras.dat", "a+b")) == NULL)
		{
			puts("No se puede abrir el fichero");
			exit(1);
		}
		if((temporal = fopen("temporal","w+b")) == NULL)
		{
			puts("No se puede abrir el fichero temporal");
			exit(1);
		}
		fread(buscar_palabra,sizeof(char),50,fichero);
		if(!feof(fichero))
		{
			do
			{
				palabra();
				fflush(stdin);
				scanf("%[^\n]", entra_palabra);
			}while(entra_palabra[0] == '\0');
			for(i = 0;i <= strlen(entra_palabra); i++)
			{
				entra_palabra[i] = toupper(entra_palabra[i]);
			}
			while(!ferror(fichero) && !feof(fichero))
			{
				if(strcmp(entra_palabra,buscar_palabra)!= 0)
				{
					fwrite(buscar_palabra,sizeof(char),50,temporal);
				}
				else
				{
					comprobar = 1;
				}
				fread(buscar_palabra,sizeof(char),50,fichero);
			}
			if(comprobar == 0)
			{
				puts("La palabra no existe en el fichero");
				sleep(1);
			}
			else
			{
				puts("Palabra borrada con exito");
				sleep(1);
			}
			fclose(temporal);
			fclose(fichero);
			remove("palabras.dat");
			rename("temporal", "palabras.dat");
			do
			{
				do
				{
					puts("Quiere eliminar mas palabras[s/n]?");
					fflush(stdin);
					opci=toupper(getchar());
					borrarcaracter=getchar();
				}while(borrarcaracter == '\b');
			}while(opci != 'S' && opci != 'N');
		}
		else
		{
			fclose(fichero);
			fclose(temporal);
			puts("No hay ninguna palabra en el fichero");
			sleep(2);
			return;
		}
	}while(opci != 'N');
}

void ver(void)
{
	int i = 0;
	char aux[50];
	char palabra[50];
	
	FILE *fichero;
	FILE *temporal;
	FILE *temporal_malo;
	
	temporal_malo = fopen("temp_malo", "w+b");
	temporal = fopen("temporal", "w+b");
	fichero = fopen("palabras.dat", "a+b");
	fread(aux,sizeof(char),50,fichero);
	if(!feof(fichero))
	{
		do
		{
			fread(palabra,sizeof(char),50,fichero);
			while(!ferror(fichero) && !feof(fichero))
			{
				if(strcmp(aux,palabra)<0)
				{
					fread(palabra,sizeof(char),50,fichero);
				}
				else
				{
					strcpy(aux,palabra);
					fread(palabra,sizeof(char),50,fichero);
				}
			}
			fwrite(aux,sizeof(char),50,temporal);
			rewind(fichero);
			fread(palabra,sizeof(char),50,fichero);
			while(!ferror(fichero) && !feof(fichero))
			{
				if(strcmp(palabra,aux) != 0)
				{
					fwrite(palabra,sizeof(char),50,temporal_malo);
				}
				fread(palabra,sizeof(char),50,fichero);
			}
			fclose(fichero);
			fclose(temporal_malo);
			remove("palabras.dat");
			rename("temp_malo", "palabras.dat");
			fichero = fopen("palabras.dat", "a+b");
			temporal_malo = fopen("temp_malo", "w+b");
			fread(aux,sizeof(char),50,fichero);
		}while(!ferror(fichero) && !feof(fichero));
		fclose(fichero);
		fclose(temporal_malo);
		fclose(temporal);
		remove("palabras.dat");
		remove("temp_malo");
		rename("temporal", "palabras.dat");
		fichero = fopen("palabras.dat", "a+b");
		
		puts("Lista de palabras");
		fread(palabra,sizeof(char),50,fichero);
		i = 0;
		while(!feof(fichero))
		{
			i++;
			if(i % 21 == 0)
			{
				puts("Pulsa cualquier teclas para seguir");
				puts("Lista de palabras");
				getchar();
				i = 1;
			}
			printf("%33.2s", palabra);
			fread(palabra,sizeof(char),50,fichero);
			fflush(stdin);
		}
		fclose(fichero);
		getchar();
	}
	else
	{
		fclose(temporal);
		fclose(temporal_malo);
		fclose(fichero);
		puts("No hay ninguna palabra en el fichero");
		sleep(2);
		remove("temporal");
		remove("palabras.dat");
		remove("temp_malo");
	}
}
