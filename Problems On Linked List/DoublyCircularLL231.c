#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;
typedef struct node* PNode;
typedef struct node** PPNode;


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


// ------------------------------------------------------------------------

void InsertFirst(PPNode First, PPNode Last, int no){
    PNode newn = (PNode)malloc(sizeof(Node));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (*First == NULL && *Last == NULL) {
        *First = newn;
        *Last = newn;
    } 
    else {
        newn->next = *First;
        (*First) -> prev = newn;
        *First = newn; 
    }

    (*Last) ->next = *First;
    (*First)->prev = *Last;
}

// ------------------------------------------------------------------------

void InsertLast(PPNode First, PPNode Last, int no){
    PNode newn = (PNode)malloc(sizeof(Node));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (*First == NULL && *Last == NULL) {
        *First = newn;
        *Last = newn;
    } 
    else{
        (*Last) -> next = newn;
        newn -> prev = *Last;
        *Last = newn;
    }

    (*Last) -> next = *First;
    (*First) -> prev = *Last;
}

// ********************************************************************

// Insert At Position
void InsertAtPos(PPNode First, PPNode Last,int no, int iPos){     
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
        newn -> prev = NULL;

        temp = *First;

        for(int i = 1; i < iPos-1; i++){
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;      
        newn -> prev = temp;
    }
}

// ------------------------------------------------------------------------

void DeleteFirst(PPNode First, PPNode Last){
    if(*First == NULL && *Last == NULL){
        printf("Unable to delete as Linked List is Empty!\n");
        return;  
    }
    else if(*First == *Last){
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else{
        *First = (*First) -> next;
        free((*First) -> prev);       

        (*Last) -> next = *First;
        (*First) -> prev = *Last;  
    }
}

// ------------------------------------------------------------------------

void DeleteLast(PPNode First, PPNode Last) {
    if(*First == NULL && *Last == NULL) {
        printf("Unable to delete as Linked List is Empty!\n");
        return;  
    } 
    else if(*First == *Last) {
        free(*First);
        *First = NULL;
        *Last = NULL;
    } 
    else {
        PNode temp = *Last;
        *Last = (*Last)->prev;
        (*Last)->next = *First;
        (*First)->prev = *Last;
        free(temp);
    }
}

// ------------------------------------------------------------------------

void DeleteAtPos(PPNode First, PPNode Last, int iPos){

    int iLen = 0;
    PNode temp = NULL;

    iLen = CountNode(*First, *Last);

    if(iPos < 1 || iPos > iLen) {
        printf("Invalid Position\n");
        return;
    }    

    if(iPos == 1) {
        DeleteFirst(First, Last);
    } 
    else if(iPos == iLen) {
        DeleteLast(First, Last);
    } 
    else {
        temp = *First;

        for(int i = 1; i < iPos - 1; i++) {
            temp = temp->next;
        }

        PNode delete = temp->next;
        temp->next = delete->next;
        delete->next->prev = temp;

        free(delete);
    }
}





// ----------------------------------------------------------------------

void Display(PNode First, PNode Last){
    if (First == NULL && Last == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    
    printf("<->");
    do{
        printf("| %d | <-> ", First->data);
        First = First->next;
    } while(First != Last -> next);

    printf("\n");
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
