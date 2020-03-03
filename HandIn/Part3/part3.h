//
// Created by Dan on 06/12/2019.
//
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#ifndef PART3_PART3_H
#define PART3_PART3_H
void *FirstNode;
pthread_mutex_t mutex;
void Testing();
void *(*allocatePtr) (size_t);
void *allocate(size_t bytes);
void deallocate(void *memory);
void initialise(void *memory , size_t size, char* algorithm);
typedef struct MemInfoStruct{
    bool Free;
    int Size;
    struct MemInfoStruct *PrevPtr;
    struct MemInfoStruct *NextPtr;
}MemInfo;
#endif //PART3_PART3_H
