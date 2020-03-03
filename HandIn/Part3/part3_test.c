#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "part3.h"

int main() {
    mutex = PTHREAD_MUTEX_INITIALIZER;
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
    void *mem = (void*) malloc(4000);//malloc the first node
    initialise(mem,1000,"First");//initilise the linked list with one node
    pthread_t worker1, worker2;
    pthread_create(&worker1, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_create(&worker2, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_join(worker1, NULL);
    pthread_join(worker2, NULL);
    initialise(mem+1000,1000,"Next");//initilise the linked list with one node
    pthread_create(&worker1, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_create(&worker2, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_join(worker1, NULL);
    pthread_join(worker2, NULL);
    initialise(mem+2000,1000,"Best");//initilise the linked list with one node
    pthread_create(&worker1, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_create(&worker2, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_join(worker1, NULL);
    pthread_join(worker2, NULL);
    initialise(mem+3000,1000,"Worst");//initilise the linked list with one node
    pthread_create(&worker1, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_create(&worker2, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_join(worker1, NULL);
    pthread_join(worker2, NULL);
    return 0;
}
