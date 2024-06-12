#include<stdio.h>

int Addition(int arr[], int iSize){

    int i = 0;
    int iSum = 0;

    for(i = 0; i < iSize; i++){
        iSum += arr[i];
    }
    return iSum;
}

int main(){

    int brr[5];
    int iRet = 0;

    printf("Enter the Values to add: ");
    for(int i = 0; i < 5; i++){
        scanf("%d", &brr[i]);
    }
    
    iRet = Addition(brr, 5);

    printf("Addition is: %d\n", iRet);

    return 0;
}