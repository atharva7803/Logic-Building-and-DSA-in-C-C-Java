#include<stdio.h>
#include<stdlib.h>

// Input: 10  20  30  40  50
// Output: 50  40  30  20  10

void Reverse(int arr[], int iSize){
    int iStart = 0, iEnd = 0, temp = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart < iEnd){
        temp = arr[iStart];
        arr[iStart] = arr[iEnd];
        arr[iEnd] = temp;

        iStart++;
        iEnd--;
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

    Reverse(brr, iCount);

    printf("Elements after reverse: \n");
    for(int i = 0; i < iCount; i++){
        printf("%d\n",brr[i]);
    }

    free(brr);

    return 0;
}