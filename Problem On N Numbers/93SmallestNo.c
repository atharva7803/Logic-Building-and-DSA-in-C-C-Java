#include<stdio.h>
#include<stdlib.h>


int Minimum(int arr[], int iSize){
    int iMin = arr[0];
    for(int i = 0; i < iSize; i++){
        if(arr[i] < iMin){
            iMin = arr[i];
        }
    }
    return iMin;
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

    iRet = Minimum(brr, iCount);
    printf("Minimum number is: %d\n", iRet);

    free(brr);

    return 0;
}