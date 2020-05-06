#include <stdio.h>
#include <unistd.h>

typedef struct Libros {
	int Cantidad;
	char Autor[35];
	char Edicion[35];
	char Titulo[35];
}libros;


libros crearlibros(void);

int main(void)
{
	libros Libro;
	
	Libro = crearlibros();
	printf("Titulo %s", Libro.Titulo);
	printf("Autor %s", Libro.Autor);
	printf("Edicion %s", Libro.Edicion);
	printf("Cantidad %d\n", Libro.Cantidad);
	return 0;
}

libros crearlibros(void)
{
	libros libro;
	
	puts("Introduzca el autor:");
	fgets(libro.Autor, 35, stdin);
	puts("Introduzca la edicion:");
	fgets(libro.Edicion, 35, stdin);
	puts("Introduzca el titulo:");
	fgets(libro.Titulo, 35, stdin);
	puts("Introduzca la cantidad:");
	scanf("%d", &libro.Cantidad);
	return libro;
}
