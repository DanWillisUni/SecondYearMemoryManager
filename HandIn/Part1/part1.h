//
// Created by Dan on 06/12/2019.
//
#include <stdlib.h>
#include <stdbool.h>
#ifndef PART1_PART1_H
#define PART1_PART1_H
void *FirstNode;
void *allocate(size_t bytes);
void deallocate(void *memory);
void initialise(void *memory , size_t size);
typedef struct MemInfoStruct{
    bool Free;
    int Size;
    struct MemInfoStruct *PrevPtr;
    struct MemInfoStruct *NextPtr;
}MemInfo;
#endif //PART1_PART1_H
