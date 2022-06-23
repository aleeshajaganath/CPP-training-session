#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>


void *myThreadFun(void *vargp)
{
	sleep(1);
	printf("Printing  from Thread \n");
	return NULL;
}

int main()
{
	pthread_t thread_id;//thread object creation
	printf("Before Thread\n");

    // A normal C function that is executed as a thread
    // when its name is specified in pthread_create()
    //	pthread_create(pthread_t obj address, NULL, function pointer, NULL);
	pthread_create(&thread_id, NULL, myThreadFun, NULL);

    /* pthread_join - join with a terminated thread
    // pthread_join(pthread_t obj,NULL)
    //  On success, pthread_join() returns 0; on error, it returns an
    //    error number. */
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}
    /*
        run
        1. gcc -o thread thread.c -pthread 
        2. ./thread
        
        */
