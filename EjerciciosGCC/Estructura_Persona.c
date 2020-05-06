#include <stdio.h>

struct fecha
{
	char dia[20], mes[20], anyo[20];
};

struct persona
{
	char nombre[20];
	char edad[20];
	char altura[20];
	char peso[20];
	struct fecha fec;
};


struct persona_empleado
{
	struct persona unapersona;
	char salario[20];
	char horas_por_semana[20];
};

void entrada(struct persona_empleado *p);
void muestra(struct persona_empleado up);

int main(void)
{
	struct persona_empleado p;
	entrada(&p);
	muestra(p);
	return 0;
}

void entrada(struct persona_empleado *p)
{
	printf("\nIntroduzca su nombre: ");
	fgets(p->unapersona.nombre,20,stdin);

	printf("\nIntrduzca su edad: ");
	fgets(p->unapersona.edad,20,stdin);

	printf("\nIntroduzca su altura: ");
	fgets(p->unapersona.altura,20,stdin);

	printf("\nIntroduzca su peso: ");
	fgets(p->unapersona.peso,20,stdin);

	printf("\nIntroduzca su fecha de nacimiento: ");
	fgets(p->unapersona.fec.dia,20,stdin);
	fgets(p->unapersona.fec.mes,20,stdin);
	fgets(p->unapersona.fec.anyo,20,stdin);

	printf("\nIntroduzca el salario: ");
	fgets(p->salario,20,stdin);

	printf("\nIntroduzca numero de horas: ");
	fgets(p->horas_por_semana,20,stdin);

}

void muestra(struct persona_empleado up)
{
	puts("\n\n\tDatos de un empleado");
	puts("\n\n\t--------------------");
	printf("\nNombre: %s \n", up.unapersona.nombre);
	printf("Edad: %s \n", up.unapersona.edad);
	printf("Fecha de nacimiento: %s-%s-%s\n", up.unapersona.fec.dia, 
	up.unapersona.fec.mes, up.unapersona.fec.anyo);
	printf("Altura: %s\n", up.unapersona.altura);
	printf("Peso: %s\n", up.unapersona.peso);
	printf("Numero de horas: %s\n", up.horas_por_semana);
}
