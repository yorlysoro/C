#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t fecha_hora;
	
	fecha_hora = time(NULL);
	printf(ctime(&fecha_hora));
	return 0;
}
