#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node, *PNode, **PPNode;     


void InsertFirst(PPNode First, int no){     
    PNode newn = NULL;      

    newn = (PNode)malloc(sizeof(Node));     

    newn -> data = no;                      
    newn -> next = NULL;

    if(*First == NULL){
        *First = newn;
    } 
    else{       
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


// Count Node
int CountNode(PNode First){
    int iCnt = 0;
    while(First != NULL){
        iCnt++;
        First = First -> next;
    }
    return iCnt;
}

// Add previous node
int AddPrevious(PNode First){
    if(First == NULL || First->next == NULL || First->next->next == NULL){
        return First;
    }
    
}

int main(){
    PNode head = NULL;
    int iRet = 0;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    iRet = CountNode(head);

    printf("Number of elements are: %d\n", iRet);

    return 0;
}