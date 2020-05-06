#include <stdio.h>
#define N_VENDEDORES 18
#define N_PRODUCTOS 10
/*Cacula el numero de ventas de cada vendedor y el total
 * de ventas de todos los vendedores*/
int mostrarMenu();


double mostrarTotal(double v[][N_PRODUCTOS]);
double totalVendedor(double v[][N_PRODUCTOS], int nVendedor);

int main(void)
{
	double ventas[N_VENDEDORES][N_PRODUCTOS]={0};
	int resp=mostrarMenu();
	int nvend, nprod;
	double cantidad;
	
	while(resp!=4)
	{
		switch(resp)
		{
			case 1:
				printf("Numero de vendedor: "); scanf("%d", &nvend);
				printf("Numero de producto: "); scanf("%d", &nprod);
				printf("Cantidad vendida: "); scanf("%lf", &cantidad);
				ventas[nvend][nprod]=cantidad;
				break;
			case 2:
				printf("Numero de vendedor: "); scanf("%d", &nvend);
				printf("Ventas total del vendedor %d=%.2lf\n", nvend, totalVendedor(ventas,nvend));
				break;
			case 3:
				printf("Total de ventas = %.2lf\n", mostrarTotal(ventas));
				break;
		}
		resp=mostrarMenu();
	}
	return 0;
			
}

int mostrarMenu()
{
	int resp;
	printf("\n\n");
	printf("1)Añadir datos\n");
	printf("2)Mostrar total de vendedor\n");
	printf("3)Mostrar total de ventas\n");
	printf("4)Salir\n");
	scanf("%d", &resp);
	return resp;
}

double mostrarTotal(double v[][N_PRODUCTOS])
{
	double resp = 0;
	int i, j;
	for(i = 0; i < N_VENDEDORES; i++)
	{
		for(j = 0; j<N_PRODUCTOS; j++)
		{
			resp+=v[i][j];
		}
	}
	return resp;
}

double totalVendedor(double v[][N_PRODUCTOS], int nVendedor)
{
	double resp = 0;
	int i;
	for(i = 0; i < N_PRODUCTOS; i++)
	{
		resp+=v[nVendedor][i];
	}
	return resp;
}
