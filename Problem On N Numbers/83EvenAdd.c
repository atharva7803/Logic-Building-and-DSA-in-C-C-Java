#include<stdio.h>
#include<stdlib.h>

int AddEven(int arr[], int iSize){

    int i = 0;
    int iSum = 0;

    for(i = 0; i < iSize; i++){
        if(arr[i] % 2 == 0){
            iSum += arr[i];
        }
    }
    return iSum;    
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

    iRet = AddEven(brr, iCount);
    printf("Addition of even elemets are: %d\n", iRet);
    

    free(brr);

    return 0;
}


