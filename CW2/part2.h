//
// Created by Dan on 25/11/2019.
//
#include <stdbool.h>
#include <stdlib.h>
#ifndef CW2_PART2_H
#define CW2_PART2_H
void *allocate(size_t bytes);
void deallocate(void *memory);
void initialise(void *memory , size_t size,char *algorithm);
typedef struct MemInfoStruct{
    bool Free;
    int Size;
    void *PrevPtr;
    void *NextPtr;
}MemInfo;
#endif //CW2_PART2_H
