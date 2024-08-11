#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;      // $ (change)
}Node, *PNode,**PPNode;



void Display(PNode First){
    printf("\nNULL <->");        
    while(First != NULL){
        printf("| %d |<->", First->data);
        First = First -> next;
    }
    printf(" NULL\n");
}

// ------------------------------------------------------------------------------

int CountNode(PNode First){
    int iCnt = 0;
    while(First != NULL){
        iCnt++;
        First = First -> next;
    }
    return iCnt;
}

// ------------------------------------------------------------------------------

void InsertFirst(PPNode First, int no){
    PNode newn = NULL;

    newn = (PNode)malloc(sizeof(Node));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;              // $

    if(*First == NULL){
        *First = newn;
    }
    else{
        newn -> next = *First;
        (*First) -> prev = newn;      // $

        *First = newn;
    }

}

// ------------------------------------------------------------------------------

void InsertLast(PPNode First, int no){
    PNode newn = NULL;      
    PNode temp = NULL;      

    newn = (PNode)malloc(sizeof(Node));     

    newn -> data = no;                      
    newn -> next = NULL;
    newn -> prev = NULL;    // $

    if(*First == NULL){
        *First = newn;
    } 
    else{       
        temp = *First;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;    // $
        newn -> next = NULL;    // $
    }
}

// ------------------------------------------------------------------------------

void InsertAtPos(PPNode First, int no, int iPos){
    int iLen = 0;
    PNode newn = NULL;
    PNode temp = NULL;


    iLen = CountNode(*First);

    if(iPos < 1 || iPos > iLen+1){      // iLen+1 bcz after last node we can still insert but after that its invalid
        printf("Invalid Position\n");
        return;
    }    

    if(iPos == 1){
        InsertFirst(First, no);
    }

    else if(iPos == iLen + 1){
        InsertLast(First, no);
    }

    else{

        newn = (PNode)malloc(sizeof(Node));

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;    // $

        temp = *First;

        for(int i = 1; i < iPos-1; i++){
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;    // $ 
        temp -> next = newn;
        newn -> prev = temp;        // $
    }
}

// ------------------------------------------------------------------------------

void DeleteFirst(PPNode First){
    // Here no need of temo pointer 

    if(*First == NULL){
        printf("Unable to delete the node as LL is Empty!");
        return;
    }
    else if((*First) -> next == NULL){
        free(*First);
        *First = NULL;
    }
    else{
        *First = (*First) -> next;
        free((*First) -> prev);         // $
        (*First) -> prev = NULL;        // $
    }
}

// ------------------------------------------------------------------------------

void DeleteLast(PPNode First){
    PNode temp = NULL;

    if(*First == NULL){
        printf("Unable to delete the node as LL is Empty!");
        return;
    }
    else if((*First) -> next == NULL){
        free(*First);
        *First = NULL;
    }
    else{
        temp = *First;
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

// ------------------------------------------------------------------------------

void DeleteAtPos(PPNode First, int iPos){
    int iLen = 0;
    PNode temp = NULL;
    PNode delete = NULL;

    iLen = CountNode(*First);

    if(iPos < 1 || iPos > iLen){      // iLen+1 bcz after last node we can still insert but after that its invalid
        printf("Invalid Position\n");
        return;
    }    

    if(iPos == 1){
        DeleteFirst(First);
    }

    else if(iPos == iLen){
        DeleteLast(First);
    }

    else{

        temp = *First;

        for(int i = 1; i < iPos-1; i++){
            temp = temp -> next;
        }
        delete = temp -> next;
        temp -> next = delete -> next;
        delete -> next -> prev = temp;      // $
        free(delete);
    }
}

// ------------------------------------------------------------------------------

int main(){

    PNode head = NULL;
    int iRet = 0;

    InsertFirst(&head, 8);
    InsertFirst(&head, 4);
    InsertFirst(&head, 12);

    Display(head);

    iRet = CountNode(head);

    printf("Number of elements are: %d\n", iRet);

    // ------------------------------------------------------------------------------

    InsertLast(&head, 111);
    InsertLast(&head, 121);
    InsertLast(&head, 151);

    Display(head);

    iRet = CountNode(head);

    printf("Number of elements are: %d\n", iRet);

    // ------------------------------------------------------------------------------

    DeleteFirst(&head);

    Display(head);

    iRet = CountNode(head);

    printf("Number of elements are: %d\n", iRet);

    // ------------------------------------------------------------------------------

    DeleteLast(&head);

    Display(head);

    iRet = CountNode(head);

    printf("Number of elements are: %d\n", iRet);

        // ------------------------------------------------------------------------------

    InsertAtPos(&head, 10, 3);

    Display(head);

    iRet = CountNode(head);

    printf("Number of elements are: %d\n", iRet);

    // ------------------------------------------------------------------------------

    DeleteAtPos(&head, 4);

    Display(head);

    iRet = CountNode(head);

    printf("Number of elements are: %d\n", iRet);

    return 0;
}