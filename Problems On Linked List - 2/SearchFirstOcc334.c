#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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



int OddCount(PNODE First){
    int iCnt = 0;

    while(First != NULL){
        if((First->data) % 2 != 0){
            iCnt++;
        }
        First = First -> next;
    }
    return iCnt;
}



int FreqCount(PNODE First, int no){
    int iCnt = 0;
    
    while(First != NULL){
        if((First->data) == no){
            iCnt++;
        }
        First = First -> next;
    }
    return iCnt;
}



bool SearchElement(PNODE First, int no){
    bool bFlag = false;
    
    while(First != NULL){
        if((First->data) == no){
            bFlag = true;
            break;
        }
        First = First -> next;
    }
    return bFlag;
}



int SearchFirstOccurence(PNODE First, int no){
    int iCnt = 1;
    bool bFlag = false;
    
    while(First != NULL){
        if(First->data == no){
            bFlag = true;
            break;
        }
        iCnt++;
        First = First -> next;
    }
    if(bFlag == true){
        return iCnt;
    }
    else{
        return -1;
    }
}



int main()
{
    PNODE Head = NULL;
    int iRet = 0;
    bool bRet = false;
    
    InsertFirst(&Head,42);
    InsertFirst(&Head,10);
    InsertFirst(&Head,50);
    InsertFirst(&Head,21);
    InsertFirst(&Head,10);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);
    
    Display(Head);

    bRet = SearchElement(Head, 50);
    if(bRet == true){
        printf("Element is present in the linked list!\n");
    }
    else{
        printf("Element is not present in the linked list!\n");
    }


    iRet = SearchFirstOccurence(Head,21);
    if(iRet == -1){
        printf("Element is not present in the linked list!\n");
    }
    else{
        printf("First occurence of Element is %d\n",iRet);
    }




    
    return 0;
}
