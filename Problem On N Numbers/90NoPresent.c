#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Check if given no is present in the array or not
bool Search(int arr[], int iSize, int iNo){

    int i = 0;
    bool bFlag = false;

    for(i = 0; i < iSize; i++){
        if(arr[i] == iNo){
            bFlag = true;
            break;
        }
    }
    return bFlag;    
}


int main(){

    int iCount = 0, iRet = 0, iValue = 0;
    int *brr = NULL;
    bool bRet = false;


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


    printf("Enter the elements that you want to search: \n");
    scanf("%d", &iValue);


    bRet = Search(brr, iCount, iValue);

    if(bRet == true){
        printf("Given no is present in the array\n");
    }
    else{
        printf("Given no is not present in the array\n");
    }
    

    free(brr);

    return 0;
}


