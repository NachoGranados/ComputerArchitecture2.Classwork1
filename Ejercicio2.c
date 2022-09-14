// libraries
#include <stdio.h>
#include <pthread.h>

// global variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int sharedCounter = 0;

// this functions belogns to both threads
void *threadsFunction() {
	
	printf("Inicio del hilo\n");
		
	// lock resource
	pthread_mutex_lock(&mutex);	
	
	sharedCounter ++;
   	
   	printf("Contador compartido = %d\n", sharedCounter);
   	
   	// unlock resource
   	pthread_mutex_unlock(&mutex);
   	
   	printf("Fin del hilo\n\n");
	    
}

int main() {
	
	pthread_t thread1;
	pthread_t thread2;
	
	int write1 = pthread_create(&thread1, NULL, threadsFunction, NULL);
	int write2 = pthread_create(&thread2, NULL, threadsFunction, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL); 

	return 0;
     
}

