#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node, *PNode, **PPNode; 



// ----------------------------------------------------------------------


void InsertFirst(PPNode First, PPNode Last, int no){

    PNode newn = NULL;

    newn = (PNode)malloc(sizeof(Node));

    newn -> data = no;
    newn -> next = NULL;

    if(*First == NULL && *Last == NULL){
        *First = newn;
        *Last = newn;   
    }
    else{
        newn -> next = *First;
        *First = newn;
    }

    (*Last) -> next = *First;

}



// ---------------------------------------------------------------

// Insert Last
void InsertLast(PPNode First, PPNode Last, int no){     
    PNode newn = NULL;      

    newn = (PNode)malloc(sizeof(Node));     

    newn -> data = no;                      
    newn -> next = NULL;

    if(*First == NULL && *Last == NULL){
        *First = newn;
        *Last = newn;   
    }
    else{       
        (*Last) -> next = newn;
        *Last = newn;     
    }

    (*Last) -> next = *First;  
}



// ********************************************************************

// Insert At Position
void InsertAtPos(PPNode First, PPNode Last, int no, int iPos){     
    int iLen = 0;
    PNode newn = NULL;
    PNode temp = NULL;

    iLen = CountNode(*First, *Last);

    if(iPos < 1 || iPos > iLen+1){      
        printf("Invalid Position\n");
        return;
    }    

    if(iPos == 1){
        InsertFirst(First, Last, no);
    }

    else if(iPos == iLen + 1){
        InsertLast(First, Last, no);
    }

    else{

        newn = (PNode)malloc(sizeof(Node));

        newn -> data = no;
        newn -> next = NULL;

        temp = *First;

        for(int i = 1; i < iPos-1; i++){
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        
    }
}




// ----------------------------------------------------------------------

void DeleteFirst(PPNode First, PPNode Last){

    if((*First == NULL) && (*Last == NULL)){       // Case 1: LL is empty
        printf("Unable to delete as Linked List is Empty!\n");
        return;
    }
    else if(*First == *Last){      // Case 2: LL contains 1 node
        free(*First);    // Or  free(*Last);
        *First = NULL;
        *Last = NULL;
    }
    else{       // Case 3: LL contains more than 1 node
        *First = (*First) -> next;
        free((*Last) -> next);
        (*Last) -> next = *First;
    }
}



// ----------------------------------------------------------------------

void DeleteLast(PPNode First, PPNode Last){
    PNode temp = NULL;

    if((*First == NULL) && (*Last == NULL)){       // Case 1: LL is empty
        printf("Unable to delete as Linked List is Empty!\n");
        return;
    }
    else if(*First == *Last){      // Case 2: LL contains 1 node
        free(*First);    // Or  free(*Last);
        *First = NULL;
        *Last = NULL;
    }
    else{       // Case 3: LL contains more than 1 node
        temp = *First;
        while(temp -> next != *Last){
            temp = temp -> next;
        }
        free(Last);
        *Last = temp;
        (*Last) -> next = *First;  
    }
}




// ********************************************************************

// Delete At Position
void DeleteAtPos(PPNode First, PPNode Last, int iPos){     
    int iLen = 0;
    PNode temp = NULL;
    PNode delete = NULL;    // Node to delete

    iLen = CountNode(*First, *Last);

    if(iPos < 1 || iPos > iLen){     
        printf("Invalid Position\n");
        return;
    }    

    if(iPos == 1){
        DeleteFirst(First, Last);
    }

    else if(iPos == iLen){
        DeleteLast(First, Last);
    }

    else{  
        temp = *First;
        for(int i = 1; i < iPos-1; i++){    
            temp = temp -> next;
        }
        delete = temp -> next;
        temp -> next = delete -> next;
        free(delete); 
    }
}



// ----------------------------------------------------------------------

void Display(PNode First, PNode Last){  
    if (First == NULL && Last == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    
    do{
        printf("| %d | -> ", First->data);
        First = First->next;
    } while(First != Last -> next);

    printf("\n");
}



// ----------------------------------------------------------------------

int CountNode(PNode First, PNode Last){     
    int iCnt = 0;
    if (First == NULL && Last == NULL) {
        printf("Linked List is empty\n");
        return 0;
    }
    
    do{
        iCnt++;
        First = First->next;
    } while(First != Last -> next);

    return iCnt;
}





int main(){
    PNode head = NULL;
    PNode tail = NULL;
    int iRet = 0;

    Display(head, tail);

    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);

    Display(head, tail);

    iRet = CountNode(head, tail);
    printf("Number of nodes are : %d\n", iRet);

// ----------------------------------------------------------------------

    InsertLast(&head, &tail, 101);
    InsertLast(&head, &tail, 111);
    InsertLast(&head, &tail, 112);

    Display(head, tail);

    iRet = CountNode(head, tail);
    printf("Number of nodes are : %d\n", iRet);


// ----------------------------------------------------------------------

    InsertAtPos(&head, &tail, 71, 4);

    Display(head, tail);

    iRet = CountNode(head, tail);
    printf("Number of nodes are : %d\n", iRet);



// ----------------------------------------------------------------------

    DeleteFirst(&head, &tail);

    Display(head, tail);

    iRet = CountNode(head, tail);
    printf("Number of nodes are : %d\n", iRet);


// ----------------------------------------------------------------------

    DeleteLast(&head, &tail);

    Display(head, tail);

    iRet = CountNode(head, tail);
    printf("Number of nodes are : %d\n", iRet);


// ----------------------------------------------------------------------

    DeleteAtPos(&head, &tail, 2);

    Display(head, tail);

    iRet = CountNode(head, tail);
    printf("Number of nodes are : %d\n", iRet);

    return 0;
}