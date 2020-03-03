//
// Created by Dan on 06/12/2019.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "part3.h"
#include <pthread.h>

void *NextStarting;
void *CreateNode(MemInfo *Node,size_t bytes);
void *SetFullNode(MemInfo *Node);
void printNodes();
void *allocateFirstFit(size_t bytes);
void *allocateNextFit(size_t bytes);
void *allocateBestFit(size_t bytes);
void *allocateWorstFit(size_t bytes);
bool CheckIfNULL(void *mem);
void lock();
void unlock();

void Testing(){
    void * a = allocate(100);
    void * b = allocate(200);
    deallocate(a);
    void * c = allocate(300);
    deallocate(c);
    deallocate(b);
    a = allocate(200);
    b = allocate(300);
    c = allocate(200);
    void *d = allocate(100);
    deallocate(b);
    deallocate(d);
    b = allocate(100);
    deallocate(a);
    deallocate(c);
    deallocate(b);
    //random
    a = allocate(20);
    b = allocate(3);
    deallocate(b);
    void * e = allocate(39);
    void * f = allocate(342);
    deallocate(f);
    void * g = allocate(394);
    deallocate(a);
    deallocate(c);
    void * h = allocate(23);
    deallocate(h);
    void * i = allocate(47);
    deallocate(g);
    void * j = allocate(239);
    deallocate(e);
    deallocate(i);
    void * k = allocate(103);
    void * l = allocate(29);
    deallocate(l);
    void * m = allocate(92);
    void * n = allocate(37);
    void * o = allocate(237);
    void * p = allocate(47);
    deallocate(j);
    deallocate(m);
    deallocate(n);
    deallocate(k);
    void * q = allocate(28);
    void * r = allocate(93);
    void * s = allocate(67);
    deallocate(r);
    deallocate(q);
    void * t = allocate(39);
    void * u = allocate(34);
    void * v = allocate(29);
    void * w = allocate(39);
    void * x = allocate(93);
    void * y = allocate(29);
    deallocate(o);
    deallocate(u);
    deallocate(p);
    deallocate(x);
    deallocate(v);
    void * z = allocate(100);
    deallocate(s);
    deallocate(t);
    deallocate(z);
    deallocate(w);
    deallocate(y);
}
void lock(){
    printf("Lock %d\n",pthread_self());
    pthread_mutex_lock(&mutex);//locks
}
void unlock(){
    printf("Unlock %d\n",pthread_self());
    pthread_mutex_unlock(&mutex);//unlock
}
void *allocate(size_t bytes){
    void *n = NULL;
    if (allocatePtr == NULL) {//if the allocation pointer is null
        fprintf(stderr,"Error: No Allocate Pointer\n");//print error
        return n;
    } else {
        if (bytes > 0){//if the bytes is greater than 0
            n=allocatePtr(bytes);//use the algorithm to assign new pointer
        } else {
            fprintf(stderr,"Error: cannot assign a memory slot of 0\n");
        }
        if (n!=NULL){//if there was space
            n =(char *)n + sizeof(MemInfo);//get the pointer to point to the start of the useable memory
        } else {
            printf("No size big enough allocated NULL\n");
        }
        return n;
    }
}
bool CheckIfNULL(void *mem){
    if (mem == NULL){
        printf("Error: isNULL\n");
        return true;
    } else {
        return false;
    }
}
void *allocateFirstFit(size_t bytes){
    lock();
    printf("----------------------------------------\n");
    printNodes();
    printf("Allocate First %i in thread%d\n",bytes,pthread_self());
    void *n = NULL;//set return value to null so that is the default
    if (bytes > 0){//if the size being allocated is greater than 0
        for (MemInfo * Node=FirstNode;Node != NULL;Node=Node->NextPtr){//for each node
            if(Node->Free == true && (int)bytes + sizeof(MemInfo) < Node->Size){//if the node is free, and big enough to create a new node in
                n=CreateNode(Node,bytes);//create new node
                break;//break the for
            } else if (Node->Free == true && (int)bytes <= Node->Size) {//else if the size is big enough to just set the node to allocated
                n=SetFullNode(Node);//set the node to allocated
                break;//break the for
            }
            printf("\n");
        }
    }
    printNodes();//prints nodes to see the differance
    printf("----------------------------------------\n");
    unlock();
    return n;
}
void *allocateNextFit(size_t bytes){
    lock();
    printf("----------------------------------------\n");
    printNodes();//print the nodes
    printf("Allocate Next %i \n",bytes);
    void *n = NULL;
    MemInfo *NextNode;//creates struct
    NextNode = (MemInfo *)NextStarting;//gets the pointer to the new node
    for (MemInfo * Node=NextNode->NextPtr;Node != NextStarting;Node=Node->NextPtr){//for each node
        if (Node==NULL){// if the next is null
            Node=FirstNode;//set the node to the firstnode
        }
        if(Node->Free == true && (int)bytes + sizeof(MemInfo) < Node->Size){//if node is free and big enough to create a new node and still have space
            n=CreateNode(Node,bytes);//create a new node
            break;//break for
        } else if (Node->Free == true && (int)bytes <= Node->Size) {//else if its big enough to have just set it to allocated
            n=SetFullNode(Node);//set the node to full
            break;//break the for
        }
        printf("\n");
    }
    if (n!=NULL){
        NextStarting = n;//set the next startting to where it left off
    }
    printNodes();//print nodes
    printf("----------------------------------------\n");
    unlock();
    return n;
}
void *allocateBestFit(size_t bytes){
    lock();
    printf("----------------------------------------\n");
    printNodes();//prints nodes
    printf("Allocate Best %i in thread%d\n",bytes,pthread_self());
    void *n = NULL;
    void *LowestIndex = NULL;//sets the lowest index to NULL
    int LowestLength = INT_MAX;//set the lowest length to the max
    for (MemInfo * Node=FirstNode;Node != NULL;Node=Node->NextPtr){//for every nide
        if (Node->Free == true && (int)bytes <= Node->Size && LowestLength > Node->Size) {//if its big enough and free and smaller than the current smallest
            LowestIndex = Node;//update lowest index
            LowestLength = Node->Size;//update lowest size
        }
    }
    if (LowestIndex != NULL){//if the index isnt null
        if (LowestLength > (int)bytes + sizeof(MemInfo)){//if the size is big enough to put in a new node
            n=CreateNode(LowestIndex,bytes);//create new node
        } else {//else
            n=SetFullNode(LowestIndex);//set node to full
        }
    }
    printNodes();//print nodes
    printf("----------------------------------------\n");
    unlock();
    return n;
}
void *allocateWorstFit(size_t bytes){
    lock();
    printf("----------------------------------------\n");
    printNodes();//prints nodes
    printf("Allocate Worst %i in thread%d\n",bytes,pthread_self());
    void *n = NULL;
    void *HighestIndex = NULL;//sets the highest index to NULL
    int HighestLength = INT_MIN;//set the highest length to the min
    for (MemInfo * Node=FirstNode;Node != NULL;Node=Node->NextPtr){//for every nide
        if (Node->Free == true && (int)bytes <= Node->Size && HighestLength < Node->Size) {//if its big enough and free and larger than the current smallest
            HighestIndex = Node;//update lowest index
            HighestLength = Node->Size;//update lowest size
        }
    }
    if (HighestIndex != NULL){//if the index isnt null
        if (HighestLength > (int)bytes + sizeof(MemInfo)){//if the size is big enough to put in a new node
            n=CreateNode(HighestIndex,bytes);//create new node
        } else {//else
            n=SetFullNode(HighestIndex);//set node to full
        }
    }
    printNodes();//print nodes
    printf("----------------------------------------\n");
    unlock();
    return n;
}
void *CreateNode(MemInfo * Node,size_t bytes){//creates a new node
    printf("Accept Node\n");
    MemInfo *NewNode;//creates struct
    NewNode = (MemInfo *)((char *)Node + Node->Size - bytes);//gets the pointer to the new node
    if (Node->NextPtr != NULL){//if the next pointer is not null
        Node->NextPtr->PrevPtr = NewNode;//change the next pointers previous to the new node
    }
    NewNode->Free=false;//set the new node to allocated
    NewNode->Size=bytes;//set the size to the size specified
    NewNode->NextPtr=Node->NextPtr;//set the new nodes next to the nodes next
    NewNode->PrevPtr=Node;//set the newnode previous to the node
    Node->NextPtr=NewNode;//set the node next to the new node
    int NewSize = Node->Size - (bytes + sizeof(MemInfo));//get the size
    Node->Size=NewSize;//set the size of the node
    printf("Org Node: %d, Size: %i, Free: %i, Prev: %d, Next: %d\n",(int)Node,Node->Size,Node->Free,(int)Node->PrevPtr,(int)Node->NextPtr);
    printf("New Node: %d, Size: %i, Free: %i, Prev: %d, Next: %d\n",(int)NewNode,NewNode->Size,NewNode->Free,(int)NewNode->PrevPtr,(int)NewNode->NextPtr);
    printf("Success\n");
    return NewNode;//return the pointer to the new node
}
void *SetFullNode(MemInfo * Node){
    printf("Accept Node\nSet Full\n");
    Node->Free=false;//sets the node to allocated
    printf("Node: %d, Size: %i, Free: %i, Prev: %d, Next: %d\n",(int)Node,Node->Size,Node->Free,(int)Node->PrevPtr,(int)Node->NextPtr);
    printf("Success\n");
    return Node;//returns the node
}
void deallocate(void *memory){
    lock();
    printf("----------------------------------------\n");
    printNodes();//prints all the nodes
    printf("Deallocatein thread%d\n",pthread_self());
    if (CheckIfNULL(memory) == false){//checks is the pointer is null
        MemInfo *this;//creates a meminfo struct called this
        this = (MemInfo *)memory -1;//defines this as the memory going to be deallocated
        if (this->Free==false){//if it is allocated
            this->Free=true;//set this to free
            if (this->NextPtr!=NULL&&this->NextPtr->Free == true){//if the next pointer isnt null
                //combine next and this
                printf("Combine Next and this\n");
                int newSize = sizeof(MemInfo) + this->Size + this->NextPtr->Size;//redefine size
                this->NextPtr=this->NextPtr->NextPtr;//set new pointer for this.next
                this->Size=newSize; //redefine the this size
                if (this->NextPtr!=NULL) {//if this next is not null
                    this->NextPtr->PrevPtr = this;//change this next preevious to this
                }
            }
            if (this->PrevPtr!=NULL && this->PrevPtr->Free == true){
                //combine next and this
                printf("Combine prev and this\n");
                int newSize = (int)sizeof(MemInfo) + this->Size + this->PrevPtr->Size;//works out the new size of the prev
                this->PrevPtr->NextPtr=this->NextPtr;//set prev next to next
                this->PrevPtr->Size=newSize;//set the new size of the
                if (this->NextPtr!=NULL){//if next not null
                    this->NextPtr->PrevPtr=this->PrevPtr;//set next prev to prev
                }
            }
            printf("Success\n");
        }
    }
    printNodes();//print all nodes
    printf("----------------------------------------\n");
    unlock();
}
void initialise(void *memory , size_t size, char * algorithm){
    lock();
    printf("Initilise memory of size %i\n",size);
    MemInfo *mem;//create a meminfo struct
    mem = (MemInfo *)memory; //set the mem info struct
    mem->Free=true;//set free to true
    mem->Size=size-sizeof(MemInfo);//set the size
    mem->NextPtr=NULL;//set the next pointer to null
    mem->PrevPtr=NULL;//set the prev pointer to null
    printf("Size: %i\n",mem->Size);
    if (algorithm != NULL){
        if(strcmp(algorithm,"Next") == 0) {//if the algorithm is next
            NextStarting = memory;//set the next starting node to the first node
            allocatePtr = &allocateNextFit;//set the allocate function pointer
        } else if (strcmp(algorithm,"Best") == 0){//if the algorithem is best
            allocatePtr = &allocateBestFit;//set the function pointer to best fit
        } else if(strcmp(algorithm,"Worst") == 0){//if the algorithm to be used is worst fit
            allocatePtr = &allocateWorstFit;//set the fuction pointer to worst fit
        }else if(strcmp(algorithm,"First") == 0){//if the algorithm is first
            allocatePtr = &allocateFirstFit;//set the fuction pointer to firstfit
        }
    } else {
        allocatePtr = &allocateFirstFit;//set the fuction pointer to firstfit
    }
    FirstNode = memory;
    printf("Success\n");
    unlock();
}
void printNodes(){
    printf("--------------------\n");
    printf("Print Nodes\n");
    for (MemInfo * Node=FirstNode;Node != NULL;Node=Node->NextPtr){//for all nodes
        printf("Node: %d, Size: %i, Free: %i, Prev: %d, Next: %d\n",(int)Node,Node->Size,Node->Free,(int)Node->PrevPtr,(int)Node->NextPtr);//print all the info about a node
    }
    printf("--------------------\n");
}