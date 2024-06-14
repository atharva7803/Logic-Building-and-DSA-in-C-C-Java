#include<stdio.h>
#include<stdlib.h>

int CountOdd(int arr[], int iSize){

    int i = 0;
    int iFreq = 0;

    for(i = 0; i < iSize; i++){
        if(arr[i] % 2 != 0){
            iFreq++;
        }
    }
    return iFreq;    
}


int main(){

    int iCount = 0, iRet = 0;
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

    iRet = CountOdd(brr, iCount);
    printf("Frequency of Odd elemets are: %d\n", iRet);
    

    free(brr);

    return 0;
}


