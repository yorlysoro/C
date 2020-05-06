/*
 * Problema_Barbero_Dormilon.c
 *
 *  Created on: 12/10/2017
 *      Author: yorlys
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <unistd.h>

#define SILLAS 5
#define ENESPERA 0
#define ATENDIDO 1

typedef void (*funcion_inicia_hilos)(void * arg);
typedef struct {
	pthread_t id;
	pthread_attr_t attr;
	funcion_inicia_hilos inicia_funcion;
	void * arg;
}Hilo;

int espera = 0;
sem_t clientes[SILLAS];
sem_t barbero;
int EstadoCliente[SILLAS];
sem_t mutex;
int ids[SILLAS];

void down(sem_t *sem);
void up(sem_t *sem);
Hilo * inicia_funcion(funcion_inicia_hilos funcion, void * arg);
void Barbero(void * param);
void Cliente(void * param);
void TestCliente(int i);
void ConsultarDisponibilidad(int i);
void Sentar(int i);
void Cortar(void);

int main(void)
{
	int i;
	puts("Main iniciado");
	sem_init(&mutex, 0, 1);
	for (i = 0; i < SILLAS; ++i) {
		EstadoCliente[i] = ENESPERA;
		sem_init(&clientes[i], 0, 0);
		ids[i] = i;
		inicia_funcion(Barbero, (void*)&ids[i]);
		inicia_funcion(Cliente, (void*)&ids[i]);
	}
	sleep(20);
	puts("Main Terminado");
	return 0;
}
void down(sem_t *sem)
{
	sem_wait(sem);
}

void up(sem_t *sem)
{
	sem_post(sem);
}

void TestCliente(int i)
{
	if(espera < SILLAS)
	{
		espera += 1;
		up(&clientes[i]);
		up(&mutex);
		down(&barbero);
		Sentar(i);

	}
	else
	{
		up(&mutex);
		printf("No hay sillas para el cliente %d\n", i+1);
	}
}


void Barbero(void * param)
{
	int i;
	i = *((int *)(param));
	printf("Barbero esta durmiendo...\n");
	sleep(rand()%3);
	while(1)
	{
		printf("El barbero esta verificando si hay clientes\n");
		ConsultarDisponibilidad(i);
		sleep(rand()%3);

	}
}

void ConsultarDisponibilidad(int i)
{
	if(espera == 0)
	{
		down(&clientes[i]);
		down(&mutex);
		printf("El barbero esta durmiendo...\n");

	}
	else
	{
		espera -= 1;
		up(&barbero);
		up(&mutex);
		Cortar();
	}
}


Hilo * inicia_funcion(funcion_inicia_hilos funcion, void * arg)
{
	Hilo * h;
	h = (Hilo *)malloc(sizeof(Hilo));
	h->inicia_funcion = funcion;
	h->arg = arg;
	pthread_attr_init(&(h->attr));
	pthread_create(&(h->id), &(h->attr), (void*)h->inicia_funcion, h->arg);
	return h;
}

void Sentar(int i)
{
	printf("El cliente %d esta sentado\n", i+1);
}

void Cortar(void)
{
	printf("El barbero esta trabajando\n");
}

void Cliente(void * param)
{
	int i;
	i = *((int *)(param));
	sleep(rand()%3);
	while(1)
	{
		printf("El cliente %d esta consultando si hay sillas\n", i+1);
		TestCliente(i);
		printf("El cliente %d fue atendido\n", i+1);
		sleep(rand()%3);
	}

}
