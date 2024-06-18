#include<stdio.h>
#include<stdlib.h>


void Display(int arr[], int iSize){
    for(int i = iSize - 1; i >= 0; i--){
        printf("%d\n",arr[i]);
    }
}


int main(){

    int *brr = NULL;
    int iCount = 0, iRet = 0;

    printf("Enter number of elements that you want to enter: \n");
    scanf("%d", &iCount);

    brr = (int *)malloc(iCount * sizeof(int));

    printf("Enter the elements: \n");
    for(int i = 0; i < iCount; i++){
        scanf("%d",&brr[i]);
    }

    printf("Reversed array is: \n");
    Display(brr, iCount);

    free(brr);

    return 0;
}