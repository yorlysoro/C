#include<stdio.h>
#include <string.h>


typedef struct Informacion {
	char nombre[50];
	char apellidos[50];
	int numerotelf;
	char direccion[50];
}informacion;

struct Estudiante {
	informacion estudianteinf;
	int numEstudiantes;
	char carrera[50];
};

struct Empleado {
	informacion empleadoinf;
	int numEmpleado;
};


int main(void)
{
	struct Estudiante infEstu;
	struct Empleado infEmpl;
	
	strcpy(infEstu.estudianteinf.nombre, "Juan");
	strcpy(infEstu.estudianteinf.apellidos, "Perez");
	infEstu.estudianteinf.numerotelf = 123456;
	strcpy(infEstu.estudianteinf.direccion, "Direccion Estudiante");
	infEstu.numEstudiantes = 1;
	strcpy(infEstu.carrera, "Sistemas");
	
	strcpy(infEmpl.empleadoinf.nombre, "Jose");
	strcpy(infEmpl.empleadoinf.apellidos, "Manuel");
	infEmpl.empleadoinf.numerotelf = 123456;
	strcpy(infEmpl.empleadoinf.direccion, "Direccion Empleado");
	infEmpl.numEmpleado = 1;
	
	printf("%s\n", infEstu.estudianteinf.nombre);
	printf("%s\n", infEstu.estudianteinf.apellidos);
	printf("%d\n", infEstu.estudianteinf.numerotelf);
	printf("%s\n", infEstu.estudianteinf.direccion);
	printf("%d\n", infEstu.numEstudiantes);
	printf("%s\n", infEstu.carrera);
	printf("%s\n", infEmpl.empleadoinf.nombre);
	printf("%s\n", infEmpl.empleadoinf.apellidos);
	printf("%d\n", infEmpl.empleadoinf.numerotelf);
	printf("%s\n", infEmpl.empleadoinf.direccion);
	printf("%d\n", infEmpl.numEmpleado);
	
	
	return 0;
}
