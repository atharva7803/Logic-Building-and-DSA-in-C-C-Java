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


void Enqueue(PPNode First, int no){         // Same as InsertLast()
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


// -----------------------------------------------------------------------

void Display(PNode First){      
    printf("\nElements of Queue are: \n");
    while(First != NULL){
        printf("%d\t", First -> data);
        First = First -> next;
    }
    printf("\n");
}


// ----------------------------------------------------------------------

int Dequeue(PPNode First){
    PNode temp = NULL;
    int iValue = 0;

    if(*First == NULL){       
        printf("Unable to remove element as Queue is empty!\n");
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

    printf("----------- Implementation of Queue -----------\n");
    while (iChoice != 5) {
        printf("Please select your choice:\n");
        printf("1 : Insert new element in Queue\n");
        printf("2 : Remove the element from Queue\n");
        printf("3 : Display the elements from Queue\n");
        printf("4 : Count number of elements in Queue\n");
        printf("5 : Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &iChoice);

        switch (iChoice) {
            case 1:
                printf("Enter the element that you want to Insert: ");
                scanf("%d", &iNo);
                Enqueue(&head, iNo);
                break;

            case 2:
                iNo = Dequeue(&head);
                if (iNo != -1) {
                    printf("Removed element from Queue is: %d\n", iNo);
                }
                break;

            case 3:
                Display(head);
                break;

            case 4:
                iNo = Count(head);
                printf("Number of elements in Queue are: %d\n", iNo);
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
