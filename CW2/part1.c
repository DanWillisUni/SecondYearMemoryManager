//
// Created by uxk18qau on 25/11/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "part1.h"
bool CheckIfInitilized();
bool CheckIfNULL(void *mem);
void printNodes();
void *CreateNode(void *TestPtr,size_t bytes);
void *SetFullNode(void *TestPtr);
void *FirstNode;
bool initilised;
int main() {
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
    FirstNode = (void*) malloc(100);    
    void * one = allocate(16);
    initialise(FirstNode,100);
    void * two = allocate(10);
    void * three = allocate(42);
    deallocate(three);
    deallocate(one);
    void * four = allocate(10);
}
bool CheckIfInitilized(){
    if (initilised == 0){
        printf("Error: Uninitilised\n");
        return false;
    } else {
        return true;
    }
}
bool CheckIfNULL(void *mem){
    if (mem == NULL){
        printf("Error: isNULL\n\n");
        return true;
    } else {
        return false;
    }
}
void *allocate(size_t bytes){
    printNodes();
    printf("Allocate %i\n",bytes);
    bool cont = true;
    void *n = NULL;
    if (CheckIfInitilized()==true){
        MemInfo *TestPtr;
        TestPtr = (MemInfo *)FirstNode;
        do{
            printf("TestNode:\n  Size: %i\n  Free: %i\n",TestPtr->Size,TestPtr->Free);
            if(TestPtr->Free == 0 && (int)bytes + sizeof(MemInfo) < TestPtr->Size){
                n=CreateNode(TestPtr,bytes);
                break;
            } else if (TestPtr->Free == 0 && (int)bytes <= TestPtr->Size) {
                n=SetFullNode(TestPtr);
                break;
            }
            printf("\n");
            if (TestPtr->NextPtr==NULL){
                cont = false;
            } else {
                TestPtr = (MemInfo *)TestPtr->NextPtr; //look at the next node
            }
        }while (cont == true); //while node is not null
    }
    printNodes();
    return n;
}
void *CreateNode(void * Memory,size_t bytes){
    printf("Accept Node\n");
    MemInfo *TestPtr;
    TestPtr = (MemInfo *)Memory;
    MemInfo *NewPtr;
    NewPtr = (MemInfo *)(char *)Memory + TestPtr->Size - bytes;
    if (TestPtr->NextPtr != NULL){
        MemInfo *NextPtr;
        NextPtr = (MemInfo *)TestPtr->NextPtr;
        NextPtr->PrevPtr = NewPtr;
    }
    NewPtr->Free=1;
    NewPtr->Size=bytes;
    NewPtr->NextPtr=TestPtr->NextPtr;
    NewPtr->PrevPtr=TestPtr;
    TestPtr->NextPtr=NewPtr;
    int NewSize = TestPtr->Size - (bytes + sizeof(MemInfo));
    TestPtr->Size=NewSize;
    printf("Old Node New:\n  Size: %i\n  Free: %i \n",TestPtr->Size,TestPtr->Free);
    printf("New Node New:\n  Size: %i\n  Free: %i\n",NewPtr->Size,NewPtr->Free);
    printf("Success\n\n");
    return NewPtr;
}
void *SetFullNode(void * Memory){
    MemInfo *TestPtr;
    TestPtr = (MemInfo *)Memory;
    printf("Accept Node\nSet Full\n");
    TestPtr->Free=1;
    printf("Node New:\n  Size: %i\n  Free: %i \n",TestPtr->Size,TestPtr->Free);
    printf("Success\n\n");
    return TestPtr;
}
void deallocate(void *memory){
    //printNodes();
    printf("Deallocate\n");
    if (CheckIfInitilized()==true && CheckIfNULL(memory) == false){
        MemInfo *this;
        this = (MemInfo *)memory;
        if (this->Free==1){
            if (this->NextPtr!=NULL){
                MemInfo *next;
                next = (MemInfo *)this->NextPtr;
                if (next->Free == 0){
                    //combine next and this
                    this->Free = 0;
                    this->NextPtr=next->NextPtr;
                    int newSize = sizeof(MemInfo) + this->Size + next->Size;
                    this->Size=newSize;
                }
            }
            if (this->PrevPtr!=NULL){
                MemInfo *prev;
                prev = (MemInfo *)this->PrevPtr;
                if (prev->Free == 0){
                    //combine next and this
                    prev->NextPtr=this->NextPtr;
                    int newSize = sizeof(MemInfo) + this->Size + prev->Size;
                    prev->Size=newSize;
                }
            }
        }
        printf("Success\n\n");
    }
    //printNodes();
}
void initialise(void *memory , size_t size){
    printf("Initilise memory of size %i\n",size);
    MemInfo *mem;
    mem = (MemInfo *)memory;
    mem->Free=0;
    mem->Size=size-sizeof(MemInfo);
    mem->NextPtr=NULL;
    mem->PrevPtr=NULL;
    printf("Size: %i\n",mem->Size);
    printf("Success\n\n");
    initilised = 1;
}
void printNodes(){
    bool cont = true;
    void *n = NULL;
    MemInfo *TestPtr;
    TestPtr = (MemInfo *)FirstNode;
    printf("Print Nodes");
    do{
        printf("Node:\n  Size: %i\n  Free: %i\n  Prev: %d\n Next: %d\n",TestPtr->Size,TestPtr->Free,TestPtr->PrevPtr,TestPtr->NextPtr);
        if (TestPtr->NextPtr==NULL){
            cont = false;
        } else {
            TestPtr = (MemInfo *)TestPtr->NextPtr; //look at the next node
        }
    }while (cont == true); //while node is not null
    printf("\n");
}