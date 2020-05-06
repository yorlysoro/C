#include <stdio.h>
#include <string.h>

struct personas{
	char nombres[50];
	char apellidos[50];
	int edad;
};

struct empleado{
		struct personas xempleado;
		int nidentificacion;
		char direccion[50];
		int nacimiento;
};

int main(void)
{
	
	struct personas persona;
	struct empleado empleado2;
	strcpy(persona.nombres, "Yorlys");
	strcpy(persona.apellidos, "Oropeza");
	persona.edad = 22;
	

	strcpy(empleado2.xempleado.nombres,"Jose");
	strcpy(empleado2.xempleado.apellidos, "Escalona");
	empleado2.xempleado.edad = 27;
	empleado2.nidentificacion = 1222;
	strcpy(empleado2.direccion, "Direccion");
	empleado2.nacimiento = 16061994;
	
	printf("%s\n", persona.nombres);
	printf("%s\n", persona.apellidos);
	printf("%d\n", persona.edad);
	
	
	
	printf("%s\n", empleado2.xempleado.nombres);
	printf("%s\n", empleado2.xempleado.apellidos);
	printf("%d\n", empleado2.xempleado.edad);
	printf("%s\n", empleado2.direccion);
	printf("%d\n", empleado2.nacimiento);	
	return 0;
	
}
