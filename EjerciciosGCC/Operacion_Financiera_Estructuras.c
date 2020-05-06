#include <stdio.h>
#include <time.h>
struct entrada(void);

struct fecha
{
	char mes[80],dia[80],anyo[80];
};
struct tiempo
{
	char horas[80], minutos[80];
};

struct registro_operacion 
{
	long numero_cuenta;
	float cantidad;
	int tipo_operacion;
	struct fecha f;
	struct tiempo t;
};

int main(void)
{
	struct registro_operacion w;

	w.numero_cuenta = entrada();
	printf("\n\n Operacion Realizada\n");
	printf("\t%ld\n", w.numero_cuenta);
	printf("\t%s-%s-%s \n", w.f.dia, w.f.mes, w.f.anyo);
	printf("\t%s:%s\n", w.t.horas, w.t.minutos);

	return 0;
}

struct entrada(void)
{
	struct time t;
	struct date d;
	struct registro_operacion una;
	time_t tiempo;
	struct tm *tmptr;
	tiempo = time(NULL);
	tmptr = localtime(&tiempo);
	
	printf("\nNùmero de cuenta: ");
	scanf("%ld", &una.numero_cuenta);
	puts("\nTipo de operacion");
	puts("Deposito(0)");
	puts("Retirada de fondos(1)");
	puts("Puesta al dia(2)");
	puts("Estado de la cuenta(3)");
	scanf("%d", &una.tipo_operacion);
	
	strftime(una.t.horas, 80, "%H", tmptr);
	strftime(una.t.minutos, 80, "%M", tmptr);
	strftime(una.f.anyo, 80, "%y", tmptr );
	strftime(una.f.mes, 80, "%m",tmptr);
	strftime(una.f.mes,80, "%d", tmptr);
		
	return una;
} 
