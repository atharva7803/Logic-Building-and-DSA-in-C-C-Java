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
    int iPos = -1;
    
    while(First != NULL){
        if(First->data == no){
            iPos = iCnt;
            break;
        }
        iCnt++;
        First = First -> next;
    }
    return iPos;
}



int SearchLastOccurence(PNODE First, int no){
    int iCnt = 1; 
    int lastPos = -1; 

    while (First != NULL) {
        if (First->data == no) {
            lastPos = iCnt; 
        }
        iCnt++;
        First = First->next;
    }
    return lastPos;
}



void SumDigits(PNODE First){
    int iDigit = 0;
    int iSum = 0;
    int iNo = 0;
    while (First != NULL) {
        iNo = First -> data;
        while(iNo != 0){
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo /= 10;
        }
        printf("%d\n", iSum);
        iSum = 0;

        First = First->next;
    }
}



void SumFactors(PNODE First) {
    int iSum = 0;
    int iNo = 0;

    while (First != NULL) {
        iNo = First->data;
        for (int i = 1; i <= iNo / 2; i++) {
            if (iNo % i == 0) {
                iSum = iSum + i;
            }
        }
        printf("%d\n", iSum);
        iSum = 0;

        First = First->next;
    }
}



bool CheckPerfect(int iNo){
    int iSum = 0;
    for (int i = 1; i <= iNo / 2; i++) {
        if (iNo % i == 0) {
            iSum = iSum + i;
        }
    }
    if(iSum == iNo){
        return true;
    }
    else{
        return false;
    }
}

void DisplayPerfect(PNODE First){
    while(First != NULL){
        if(CheckPerfect(First->data) == true){
            printf("Perfect number from LL is: %d\n", First->data);
        }
        First = First -> next;
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
    InsertFirst(&Head,28);
    InsertFirst(&Head,10);
    InsertFirst(&Head,21);
    InsertFirst(&Head,496);
    
    Display(Head);


    DisplayPerfect(Head);

    
    return 0;
}
