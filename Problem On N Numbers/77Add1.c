#include<stdio.h>

int Addition(int ptr[], int iSize){

    int i = 0;
    int iSum = 0;

    for(i = 0; i < iSize; i++){
        iSum += ptr[i];
    }
    return iSum;
}

int main(){

    int arr[5] = {10,20,30,40,50};

    int iRet = 0;
    iRet = Addition(arr, 5);
    
    printf("Addition is: %d\n", iRet);

    return 0;
}