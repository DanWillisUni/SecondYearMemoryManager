//
// Created by Dan on 06/12/2019.
//
//includes
#include <stdio.h>
#include <stdbool.h>
#include "part1.h"
//private function definitions
bool CheckIfNULL(void *mem);
void printNodes();
void *CreateNode(MemInfo * Node,size_t bytes);
void *SetFullNode(MemInfo * Node);
//methods
bool CheckIfNULL(void *mem){//checks if the pointer is null
    if (mem == NULL){//if the pointer is null
        printf("Error: isNULL\n");//print an error
        return true;
    } else {
        return false;
    }
}
void *allocate(size_t bytes){
    printf("----------------------------------------\n");//for help seeing seperating methods
    printNodes();//prints all the nodes
    printf("Allocate %i\n",bytes);
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
    if (n!=NULL){//if there was space for it
        n =(char *)n + sizeof(MemInfo);//adds for the pointer to be moved to accomodate the start of the memory
    } else {
        printf("No size big enough allocated NULL\n");
    }
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
    printf("----------------------------------------\n");
    printNodes();//prints all the nodes
    printf("Deallocate\n");
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
}
void initialise(void *memory , size_t size){//initilises the firstnode
    printf("Initilise memory of size %i\n",size);
    MemInfo *mem;//create a meminfo struct
    mem = (MemInfo *)memory; //set the mem info struct
    mem->Free=true;//set free to true
    mem->Size=size-sizeof(MemInfo);//set the size
    mem->NextPtr=NULL;//set the next pointer to null
    mem->PrevPtr=NULL;//set the prev pointer to null
    printf("Size: %i\n",mem->Size);
    printf("Success\n");
}
void printNodes(){
    printf("--------------------\n");
    printf("Print Nodes\n");
    for (MemInfo * Node=FirstNode;Node != NULL;Node=Node->NextPtr){//for all nodes
        printf("Node: %d, Size: %i, Free: %i, Prev: %d, Next: %d\n",(int)Node,Node->Size,Node->Free,(int)Node->PrevPtr,(int)Node->NextPtr);//print all the info about a node
    }
    printf("--------------------\n");
}


