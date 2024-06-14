#include<stdio.h>
#include<stdlib.h>

int Search(int arr[], int iSize, int iNo){

    int i = 0;
    int iFreq = 0;

    for(i = 0; i < iSize; i++){
        if(arr[i] == iNo){
            iFreq++;
        }
    }
    return iFreq;    
}


int main(){

    int iCount = 0, iRet = 0, iValue = 0;
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


    printf("Enter the elements that you want to search: \n");
    scanf("%d", &iValue);


    iRet = Search(brr, iCount, iValue);
    printf("Frequency of that number is: %d\n", iRet);
    

    free(brr);

    return 0;
}


