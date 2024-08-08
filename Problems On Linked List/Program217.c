#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

typedef struct node Node;
typedef struct node * PNode;    // p - pointer node
typedef struct node ** PPNode;  // pp - pointer to pointer node

int main(){

    PNode head = NULL;                  // New syntax
    // struct node *head = NULL;           Old syntax 

    Node obj;
    // struct node obj;

    return 0;
}