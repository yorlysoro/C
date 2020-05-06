#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <unistd.h>

#define MAXELEMENTOS 10
#define SIGUIENTE (ACTUAL + 1)%MAXELEMENTOS
#define ANTERIOR (ACTUAL + MAXELEMENTOS - 1)%MAXELEMENTOS

typedef void (*funcion_inicia_hilos)(void *arg);

typedef struct {
	pthread_t id;
	pthread_attr_t attr;
	funcion_inicia_hilos inicia_funcion;
	void * arg;
}Hilo;

sem_t mutex;
sem_t lleno;
sem_t vacio;
int ACTUAL;
int Elementos[MAXELEMENTOS];

Hilo * inicia_thread(funcion_inicia_hilos funcion, void * arg){
	Hilo *t;
	t = (Hilo*)malloc(sizeof(Hilo));
	t->inicia_funcion = funcion;
	t->arg = arg;
	pthread_attr_init(&(t->attr));
	pthread_create(&(t->id), &(t->attr), (void *)t->inicia_funcion, t->arg);
	return t;
}

void down(sem_t *sem)
{
	sem_wait(sem);
}

void up(sem_t *sem){
	sem_post(sem);
}

int Insertar_Elemento()
{
	int Elemento;
	Elemento = ACTUAL;
	Elementos[ACTUAL] = Elemento;
	ACTUAL = SIGUIENTE;
	return Elemento;
}

int Remover_Elemento()
{
	int Elemento;
	Elemento = Elementos[ANTERIOR];
	ACTUAL = ANTERIOR;
	return Elemento;
}

void Productor(void *param){
	while(1){
		sleep(rand() % 2);
		down(&vacio);
		down(&mutex);
		printf("Productor: %d\n", Insertar_Elemento());
		up(&mutex);
		up(&lleno);
	}
}

void Consumidor(void *param)
{
	while(1){
		sleep(rand() % 2);
		down(&lleno);
		down(&mutex);
		printf("\tConsumidor: %d\n", Remover_Elemento());
		up(&mutex);
		up(&vacio);
	}
}

int main(int argc, char *argv[])
{
	puts("Main Iniciado");
	sem_init(&mutex, 0, 1);
	sem_init(&vacio, 0, MAXELEMENTOS);
	sem_init(&lleno, 0, 0);
	
	inicia_thread(Productor, NULL);
	inicia_thread(Consumidor, NULL);
	sleep(30);
	puts("Main Finalizado");
	return 0;
}
