#include <stdio.h>
#include <ctype.h>

typedef struct arreglostruc{
	char nombre[50], apellido[50], edad[50];
}arreglotype;

int main(void)
{
	arreglotype xpersona[5];
	int i;
	for(i = 0; i < 5; i++)
	{
		puts("Nombre:\b");
		fgets(xpersona[i].nombre,50,stdin);
		puts("Apellido:\b");
		fgets(xpersona[i].apellido,50,stdin);
		puts("Edad:\b");
		fgets(xpersona[i].edad,50,stdin);
	}
	for(i = 0;i < 5; i++)
	{
		printf("%s %s %s\n", xpersona[i].nombre, xpersona[i].apellido, xpersona[i].edad);
	}
	
	
	return 0;
}
//int verificar_str(char entrada[50])
//{
	//int numeros[50];
	//int i;
	//for(i = 0; i < 50; i++)
	//{
		//if(entrada != '\0')
		//{
			//if(isdigit(entrada[i]) != 0)
			//{
				//numeros[i] = (int)entrada[i];
			//}
		//}
	//}
	//return numeros[50];
//}
