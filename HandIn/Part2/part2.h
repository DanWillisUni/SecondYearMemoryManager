//
// Created by Dan on 06/12/2019.
//
#include <stdlib.h>
#include <stdbool.h>
#ifndef PART2_PART2_H
#define PART2_PART2_H
void *FirstNode;
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
#endif //PART2_PART2_H
