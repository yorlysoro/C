#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
	char* nm;
	int dia;
	int ms;
	int aa;
	char mes[11];
}PERSONA;

void entradas(PERSONA *p);
char* mes_asci(short n);
int convierte_a_int(char *cad);

int main(void)
{
	FILE *pff;
	char nf[] = "Personas.dat";
	char r = 'S';
	if((pff = fopen(nf, "w+")) == NULL)
	{
		puts("Error al abrir el archivo");
		exit(-1);
	}
	
	while(toupper(r) == 'S')
	{
		PERSONA pt;
		entradas(&pt);
		printf("%s %d-%d-%d %s\n", pt.nm, pt.dia, pt.ms, pt.aa, pt.mes);
		fprintf(pff, "%s %d-%d-%d %s\n", pt.nm, pt.dia, pt.ms, pt.aa, pt.mes);
		printf("Otro registro?: "); scanf("%c %*c", &r);
		
	}
	fclose(pff);
	return 0;
}

void entradas(PERSONA *p)
{
	char bf[81];
	printf("Nombre: ");  
	gets(bf);
	p->nm = (char*)malloc((strlen(bf)+1) * sizeof(char));
	strcpy(p->nm,bf);
	printf("Fecha de nacimiento(dd mm aaaa): ");
	fgets(bf,81,stdin);
	p->dia = convierte_a_int(bf);
	fgets(bf,81,stdin);
	p->ms = convierte_a_int(bf);
	fgets(bf,81,stdin);
	p->aa = convierte_a_int(bf);
	printf("\n%s\n", mes_asci(p->ms));
	strcpy(p->mes, mes_asci(p->ms));
}

int convierte_a_int(char *cad)
{
	int num = atoi(cad);
	return num;
}

char* mes_asci(short n)
{
	static char *mes[12] =
	{
		"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
		"Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
	};
	if(n >= 1 && n <= 12)
	return mes[n-1];
	else
	return "Error mes";
}
