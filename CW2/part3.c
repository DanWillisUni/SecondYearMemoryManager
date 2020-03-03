//
// Created by Dan on 25/11/2019.
//
#include "part3.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
void *CreateNode(void *TestPtr,size_t bytes);
void *SetFullNode(void *TestPtr);
void printNodes();
void *allocateFirstFit(size_t bytes);
void *allocateNextFit(size_t bytes);
void *allocateBestFit(size_t bytes);
void *allocateWorstFit(size_t bytes);
bool CheckIfInitilized();
bool CheckIfNULL(void *mem);
void Testing();
void lock();
void unlock();

void *FirstNode;
bool initilised = false;
void *NextStarting;
void *(*allocatePtr) (size_t);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
    FirstNode = (void*) malloc(100);
    initialise(FirstNode, 100, "First");
    pthread_t worker1, worker2;
    pthread_create(&worker1, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_create(&worker2, NULL, (void *(*)(void *)) &Testing, NULL);
    pthread_join(worker1, NULL);
    pthread_join(worker2, NULL);
}
void Testing(){
    printf("--------------------------------------------------------------\n");
    void * two = allocate(10);
    void * three = allocate(42);
    deallocate(three);
    //deallocate(NULL);
    void * four = allocate(10);
}
void lock(){
    printf("Lock %d\n",pthread_self());
    pthread_mutex_lock(&mutex);
}
void unlock(){
    printf("Unlock %d\n",pthread_self());
    pthread_mutex_unlock(&mutex);
}
bool CheckIfInitilized(){
    if (initilised == false){
        fprintf(stderr,"Error: Uninitilised\n");
        return false;
    } else {
        return true;
    }
}
bool CheckIfNULL(void *mem){
    if (mem == NULL){
        fprintf(stderr,"Error: isNULL\n\n");
        return true;
    } else {
        return false;
    }
}
void *allocate(size_t bytes){
    void *n = NULL;
    if (allocatePtr == NULL) {
        fprintf(stderr,"Error: No Allocate Pointer\n");
        return n;
    } else {
        n=allocatePtr(bytes);
        return (char *)n + sizeof(MemInfo);
    }
}
void *allocateFirstFit(size_t bytes){
    lock();
    printNodes();
    printf("Allocate First %i\n",bytes);
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
    unlock();
    return n;
}
void *allocateNextFit(size_t bytes){
    lock();
    printNodes();
    printf("Allocate First %i\n",bytes);
    bool cont = true;
    void *n = NULL;
    if (CheckIfInitilized()==true){
        MemInfo *TestPtr;
        TestPtr = (MemInfo *)NextStarting;
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
            if (TestPtr->NextPtr == NextStarting) {
                cont = false;
            } else if (TestPtr->NextPtr == NULL) {
                if (FirstNode == NextStarting) {
                    cont = false;
                } else {
                    TestPtr = (MemInfo *)FirstNode;
                }
            } else {
                TestPtr = (MemInfo *)TestPtr->NextPtr; //look at the next node
            }
        }while (cont == true); //while node is not null
    }
    printNodes();
    NextStarting = n;
    unlock();
    return n;
}
void *allocateBestFit(size_t bytes){
    lock();
    printNodes();
    printf("allocate Best %i\n",bytes);
    void *n = NULL;
    if(CheckIfInitilized()==true){
        void *LowestIndex = NULL;
        int LowestLength = INT_MAX;
        bool cont = true;
        bool CreateNew = true;
        MemInfo *TestPtr;
        TestPtr = (MemInfo *)FirstNode;
        do{
            printf("TestNode:\n");
            int requiredSize = bytes + sizeof(MemInfo);
            int testSize = TestPtr->Size;
            printf("Size: %i\n",TestPtr->Size);
            int testFree = TestPtr->Free;
            printf("Free: %i\n",TestPtr->Free);
            if(testFree == 0 && testSize<LowestLength){
                if(requiredSize < testSize){
                    printf("Change lowest size to %i\n",testSize);
                    LowestIndex = TestPtr;
                    LowestLength = testSize;
                    CreateNew = true;
                } else if((int)bytes <= testSize){
                    printf("Change lowest size to %i\n",testSize);
                    LowestIndex = TestPtr;
                    LowestLength = testSize;
                    CreateNew = false;
                }
            }
            if (TestPtr->NextPtr==NULL){
                printf("EndofNodes\n");
                cont = false;
            } else {
                printf("Go to NextNode\n");
                TestPtr = (MemInfo *)TestPtr->NextPtr; //look at the next node
            }
        }while (cont == true); //while node is not null
        if (LowestIndex != NULL){
            if (CreateNew == true){
                n=CreateNode(LowestIndex,bytes);
            } else {
                n=SetFullNode(LowestIndex);
            }
        }
    }
    printNodes();
    unlock();
    return n;
}
void *allocateWorstFit(size_t bytes){
    lock();
    printNodes();
    printf("allocate Worst %i\n",bytes);
    void *n = NULL;
    if(CheckIfInitilized()==true){
        void *HighestIndex = NULL;
        int HighestLength = INT_MIN;
        bool cont = true;
        bool CreateNew = true;
        MemInfo *TestPtr;
        TestPtr = (MemInfo *)FirstNode;
        do{
            printf("TestNode:\n");
            int requiredSize = bytes + sizeof(MemInfo);
            int testSize = TestPtr->Size;
            printf("Size: %i\n",TestPtr->Size);
            int testFree = TestPtr->Free;
            printf("Free: %i\n",TestPtr->Free);
            if(testFree == 0 && testSize>HighestLength){
                if(requiredSize <= testSize){
                    printf("Change highest size to %i\n",testSize);
                    HighestIndex = TestPtr;
                    HighestLength = testSize;
                    CreateNew = true;
                } else if((int)bytes <= testSize){
                    printf("Change highest size to %i\n",testSize);
                    HighestIndex = TestPtr;
                    HighestLength = testSize;
                    CreateNew = false;
                }
            }
            if (TestPtr->NextPtr==NULL){
                printf("EndofNodes\n");
                cont = false;
            } else {
                printf("Go to NextNode\n");
                TestPtr = (MemInfo *)TestPtr->NextPtr; //look at the next node
            }
        }while (cont == true); //while node is not null
        if (HighestIndex != NULL){
            if (CreateNew == true){
                n=CreateNode(HighestIndex,bytes);
            } else {
                n=SetFullNode(HighestIndex);
            }
        }
    }
    printNodes();
    unlock();
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
void initialise (void *memory,size_t size,char *algorithm){
    printf("Initilise memory of size %i\n",size);
    MemInfo *mem;
    mem = (MemInfo *)memory;
    mem->Free=0;
    mem->Size=size-sizeof(MemInfo);
    mem->NextPtr=NULL;
    mem->PrevPtr=NULL;
    printf("Size: %i\n",mem->Size);
    //set the pointer to the function
    if(algorithm == "Next") {
        NextStarting = FirstNode;
        allocatePtr = &allocateNextFit;
    } else if (algorithm == "Best"){
        allocatePtr = &allocateBestFit;
    } else if(algorithm == "Worst"){
        allocatePtr = &allocateWorstFit;
    }else if(algorithm == NULL || algorithm == "First"){
        allocatePtr = &allocateFirstFit;
    }
    initilised = true;
    printf("Success\n\n");
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