//
// Created by uxk18qau on 25/11/2019.
//
#include <stdlib.h>
#include <stdbool.h>
#ifndef CW2_PART1_H
#define CW2_PART1_H
void *allocate(size_t bytes);
void deallocate(void *memory);
void initialise(void *memory , size_t size);
typedef struct MemInfoStruct{
    bool Free;
    int Size;
    struct MemInfoStruct *PrevPtr;
    struct MemInfoStruct *NextPtr;
}MemInfo;
#endif //CW2_PART1_H
