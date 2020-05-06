#include <stdio.h>
#include <stdlib.h>

#define N_FILAS 25
#define N_COLUMNAS 4
#define LIBRE 0
#define OCUPADO 1

int mostrarMenu();
void reservarAsiento(int a[][N_COLUMNAS]);
void cancelarAsiento(int a[][N_COLUMNAS]);
void mostrarOcupacion(int a[][N_COLUMNAS]);

int main(void)
{
	int asiento[N_FILAS][N_COLUMNAS];
	int resp = mostrarMenu();
	while(1)
	{
		switch(resp)
		{
			case 1:
			reservarAsiento(asiento);
			break;
			case 2:
			cancelarAsiento(asiento);
			break;
			case 3:
			mostrarOcupacion(asiento);
			break;
			case 4:
			printf("Adios\n");
			exit(1);
			default: printf("Opcion invalida\n");
		}
	}
	resp=mostrarMenu();
	return 0;
}


int mostrarMenu()
{
	int resp;
	printf("\n\n");
	printf("1)Reservar Asiento\n");
	printf("2)Cancelar Asiento\n");
	printf("3)Mostrar Ocupacion\n");
	printf("4)Salir\n");
	scanf("%d", &resp);
	return resp;
}

void reservarAsiento(int a[][N_COLUMNAS])
{
	int fila,col;
	
	printf("Escriba la fila del asiento a reservar: "); scanf("%d", &fila);
	printf("Escriba la columna del asiento a reservar: "); scanf("%d", &col);
	
	if(a[fila][col] == OCUPADO) printf("Ese asiento ya esta reservado\n");
	else {
		a[fila][col] = OCUPADO;
		printf("Reserva realizada\n");
	}
	main();
}

void cancelarAsiento(int a[][N_COLUMNAS])
{
	int fila,col;
	
	printf("Escriba la fila del asientos a cancelar: "); scanf("%d", &fila);
	printf("Escriba la columna del asiento a cancelar: "); scanf("%d", &col);
	
	if(a[fila][col] == LIBRE) 
	printf("Ese asiento no esta ocupado\n");
	else
	{
		a[fila][col] = LIBRE;
		printf("Cancelacion realizada\n");
	}
	main();
}


void mostrarOcupacion(int a[][N_COLUMNAS])
{
	int i,j;
	
	for(i = 0; i < N_FILAS; i++)
	{
		for(j = 0;j<N_COLUMNAS;j++)
		{
			printf("Fila %d, columna %d", i,j);
			if(a[i][j] == LIBRE ) printf("Libre\n");
			else printf("Ocupado\n");
		}
	}
	main();
}
