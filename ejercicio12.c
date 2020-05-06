#include <stdio.h>
void *encuentra(char letra, char *cadena);

int main(void)
{
	char frase[80], *p, letra_busca;
	
	printf("Introducir cadena: ");
	gets(frase);
	fflush(stdin);
	printf("Letra a buscar: ");
	letra_busca = getchar();
	p=encuentra(letra_busca,frase);
	if(p)
	printf("\n %s",p);
	return 0;
}

void *encuentra(char letra, char *cadena)
{
	while(letra!=*cadena && * cadena)
	cadena++;
	
	return cadena;
}
