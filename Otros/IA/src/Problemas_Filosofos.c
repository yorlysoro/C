#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <unistd.h>

#define FILOSOFOS 5
#define IZQUIERDA (i+FILOSOFOS-1)%FILOSOFOS
#define DERECHA (i+1)%FILOSOFOS
#define PENSANDO 0
#define AMBRIENTO 1
#define COMIENDO 2

typedef void (*funcion_inicia_hilos)(void * arg);

typedef struct {
	pthread_t id;
	pthread_attr_t attr;
	funcion_inicia_hilos inicia_funcion;
	void * arg;
}Hilo;

sem_t mutex;
sem_t s[FILOSOFOS];
int Estado[FILOSOFOS];
int ids[FILOSOFOS];

Hilo * inicia_funcion(funcion_inicia_hilos funcion, void * arg)
{
	Hilo * t;
	t = (Hilo*)malloc(sizeof(Hilo));
	t->inicia_funcion = funcion;
	t->arg = arg;
	pthread_attr_init(&(t->attr));
	pthread_create(&(t->id), &(t->attr), (void*)t->inicia_funcion, t->arg);
	return t;
}

void down(sem_t *sem)
{
	sem_wait(sem);
}

void up(sem_t *sem)
{
	sem_post(sem);
}

void test(int i)
{
	if(Estado[i] == AMBRIENTO && Estado[IZQUIERDA] != COMIENDO && Estado[DERECHA] != COMIENDO){
		Estado[i] = COMIENDO;
		up(&s[i]);
	}
}

void Obtiene_Tenedores(int i){
	down(&mutex);
	Estado[i] = AMBRIENTO;
	printf("\tFilosofo %d esta intentando tomar los tenedores...\n", i);
	test(i);
	up(&mutex);
	down(&s[i]);
	printf("\tFilosofo %d a acquirido los tenedores!!\n", i);
}

void Soltar_Tenedores(int i){
	down(&mutex);
	Estado[i] = PENSANDO;
	printf("\tFilosofo %d ha dejado los tenedores...\n", i);
	test(IZQUIERDA);
	test(DERECHA);
	up(&mutex);
}

void Filosofo(void *param)
{
	int i;
	i = *((int *)(param));
	printf("Filosofo %d esta pensando...\n", i);
	sleep(rand()%3);
	while(1){
		printf("Filosofo %d esta ambriento!!!!\n", i);
		Obtiene_Tenedores(i);
		printf("\tFilosofo %d esta comiendo.\n",i);
		sleep(rand()%5);
		Soltar_Tenedores(i);
		printf("Filosofo %d estas pensando...\n", i);
		sleep(rand()%3);
	}
}

int main(int argc, char *argv[])
{
	int i;
	puts("Main Iniciado");
	sem_init(&mutex, 0, 1);

	for(i = 0; i < FILOSOFOS; i++)
	{
		Estado[i] = PENSANDO;
		sem_init(&s[i], 0, 0);
		ids[i] = i;
		inicia_funcion(Filosofo, (void*)&ids[i]);
	}
	sleep(20);
	puts("Main Terminado");
	return 0;
}
