#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node, *PNode, **PPNode;     


void InsertFirst(PPNode First, int no){     // TC: O(1) 
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

// ---------------------------------------------------------------

// Insert Last
void InsertLast(PPNode First, int no){     // TC: O(n)
    PNode newn = NULL;      
    PNode temp = NULL;      

    newn = (PNode)malloc(sizeof(Node));     

    newn -> data = no;                      
    newn -> next = NULL;

    if(*First == NULL){
        *First = newn;
    } 
    else{       
        temp = *First;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newn;
        
    }

}

// ----------------------------------------------------------------------

void Display(PNode First){      // O(n)
    while(First != NULL){
        printf("| %d |->", First -> data);
        First = First -> next;
    }
    printf("NULL\n");
}


// ----------------------------------------------------------------------

int CountNode(PNode First){     // O(n)
    int iCnt = 0;
    while(First != NULL){
        iCnt++;
        First = First -> next;
    }
    return iCnt;
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

    // ---------------------------------------------------

    InsertLast(&head, 111);
    InsertLast(&head, 121);
    InsertLast(&head, 151);

    Display(head);

    iRet = CountNode(head);

    printf("Number of elements are: %d\n", iRet);

    return 0;
}