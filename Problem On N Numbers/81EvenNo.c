#include<stdio.h>
#include<stdlib.h>

void DisplayEven(int arr[], int iSize){

    int i = 0;

    printf("Even Elements are: \n");
    for(i = 0; i < iSize; i++){
        if(arr[i] % 2 == 0){
            printf("%d\n", arr[i]);
        }
    }    
}


int main(){

    int iCount = 0;
    int *brr = NULL;


    printf("Enter no of elements you want: \n");
    scanf("%d", &iCount);

    brr = (int *)malloc(iCount * sizeof(int));

    printf("Enter the elements: \n");
    for(int i = 0; i < iCount; i++){
        scanf("%d", &brr[i]);
    }

    printf("Enterd elements are: \n");
    for(int i = 0; i < iCount; i++){
        printf("%d\n", brr[i]);
    }

    DisplayEven(brr, iCount);
    

    free(brr);

    return 0;
}


