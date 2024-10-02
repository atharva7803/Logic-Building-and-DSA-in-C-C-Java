#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE First, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}   

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("| %d |->",First->data);
        First = First -> next;
    }
    printf("NULL\n");
} 

int Count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First -> next;
    }
    return iCnt;
} 



int Addition(PNODE First){
    int iSum = 0;

    while(First != NULL){
        iSum = iSum + First->data;
        First = First -> next;
    }
    return iSum;
}



int EvenCount(PNODE First){
    int iCnt = 0;

    while(First != NULL){
        if((First->data) % 2 == 0){
            iCnt++;
        }
        First = First -> next;
    }
    return iCnt;
}



int main()
{
    PNODE Head = NULL;
    int iRet = 0;
    
    InsertFirst(&Head,42);
    InsertFirst(&Head,10);
    InsertFirst(&Head,50);
    InsertFirst(&Head,21);
    InsertFirst(&Head,10);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);
    
    Display(Head);

    iRet = EvenCount(Head);
    printf("Even no of elements is:%d\n",iRet);
    
    return 0;
}
