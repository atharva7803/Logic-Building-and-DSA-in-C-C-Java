#include<stdio.h>
#include<stdlib.h>


int Maximum(int arr[], int iSize){
    int iMax = arr[0];
    for(int i = 0; i < iSize; i++){
        if(arr[i] > iMax){
            iMax = arr[i];
        }
    }
    return iMax;
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

    iRet = Maximum(brr, iCount);
    printf("Maximum number is: %d\n", iRet);

    free(brr);

    return 0;
}