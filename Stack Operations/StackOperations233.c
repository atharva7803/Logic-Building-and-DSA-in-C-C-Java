#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node, *PNode, **PPNode;   


// ----------------------------------------------------------------------

int Count(PNode First){    
    int iCnt = 0;
    while(First != NULL){
        iCnt++;
        First = First -> next;
    }
    return iCnt;
}

// ----------------------------------------------------------------------


void Push(PPNode First, int no){    
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


// -----------------------------------------------------------------------

void Display(PNode First){      
    printf("\nElements of Stack are: \n");
    while(First != NULL){
        printf("%d\n", First -> data);
        First = First -> next;
    }
    printf("\n");
}


// ----------------------------------------------------------------------

int Pop(PPNode First){
    PNode temp = NULL;
    int iValue = 0;

    if(*First == NULL){       
        printf("Unable to pop element as Stack is empty!\n");
        return -1;
    }
    else{      
        temp = *First;

        iValue = (*First) -> data;
        *First = (*First) -> next;
        free(temp);
    }
    return iValue;
}



int main() {
    PNode head = NULL;
    int iChoice = 0;
    int iNo = 0;

    printf("----------- Implementation of Stack -----------\n");
    while (iChoice != 5) {
        printf("Please select your choice:\n");
        printf("1 : Push new element in Stack\n");
        printf("2 : Pop the element from Stack\n");
        printf("3 : Display the elements from Stack\n");
        printf("4 : Count number of elements in Stack\n");
        printf("5 : Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &iChoice);

        switch (iChoice) {
            case 1:
                printf("Enter the element that you want to Push: ");
                scanf("%d", &iNo);
                Push(&head, iNo);
                break;

            case 2:
                iNo = Pop(&head);
                if (iNo != -1) {
                    printf("Popped element from Stack is: %d\n", iNo);
                }
                break;

            case 3:
                Display(head);
                break;

            case 4:
                iNo = Count(head);
                printf("Number of elements in Stack are: %d\n", iNo);
                break;

            case 5:
                printf("Thank you for using our application\n");
                break;

            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}
