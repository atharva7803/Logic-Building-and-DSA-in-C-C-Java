#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node, *PNode, **PPNode;     // another way


void InsertFirst(PPNode First, int no){     // PPNode bcz head is itself pointer
    PNode newn = NULL;      // newn: new node

    // Step 1: allocated memory dynamically
    newn = (PNode)malloc(sizeof(Node));     

    // Step 2: Initialise the new node
    newn -> data = no;                      
    newn -> next = NULL;

    // Step 3: Check if linked list is empty
    if(*First == NULL){
        *First = newn;
    } 
    else{       // If linked list contains at least one node in it
        newn -> next = *First;
        *First = newn;
    }

}


void Display(PNode First){
    while(First != NULL){
        printf("| %d |->", First -> data);
        First = First -> next;
    }
    printf("NULL\n");
}


int main(){
    PNode head = NULL;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    return 0;
}