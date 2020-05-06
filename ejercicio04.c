#include <stdio.h>
int main(void)
{
	int opcion=0;
	struct ficha{
		char nombre[40];
		char apellido[50];
		unsigned edad;
	}emplead,usuario;
	
	do{
		printf("1.empleados\n");
		printf("2.usuarios\n");
		printf("0.Visualizar\n");
		scanf("%i", &opcion);
		
		if(opcion == 0)
		break;
		if(opcion == 1)
		{
			printf("Nombre: ");
			gets(emplead.nombre);
			printf("Apellido: ");
			gets(emplead.apellido);
			printf("Edad: ");
			scanf("%i", &emplead.apellido);
		}
		else
		{
			printf("Nombre: ");
			gets(usuario.nombre);
			printf("Apellidos: ");
			gets(usuario.apellido);
			printf("Edad: ");
			scanf("%i", &usuario.edad);
		}
	}while(opcion!=0);
	
	printf("%s %s\n", emplead.nombre,emplead.apellido);
	printf("%u años\n", emplead.edad);
	printf("%s %s\n", usuario.nombre, usuario.apellido);
	printf("%u años\n", usuario.edad);
	return 0;
}
