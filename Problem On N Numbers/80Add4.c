#include<stdio.h>
#include<stdlib.h>

int Addition(int arr[], int iSize){

    int i = 0;
    int iSum = 0;

    for(i = 0; i < iSize; i++){
        iSum += arr[i];
    }
    return iSum;
}


int main(){

    int iCount = 0, iRet = 0;
    int *brr = NULL;

    // Step 1: Accept no of elements from user

    printf("Enter no of elements you want: \n");
    scanf("%d", &iCount);

    // Step 2: Allocate dynamic memory for that no of elements
    brr = (int *)malloc(iCount * sizeof(int));

    // Step 3: Accept the values form user and store into that memory
    printf("Enter the elements: \n");
    for(int i = 0; i < iCount; i++){
        scanf("%d", &brr[i]);
    }

    printf("Enterd elements are: \n");
    for(int i = 0; i < iCount; i++){
        printf("%d\n", brr[i]);
    }

    // Step 4: Pass the address at that memory to the function (Any)
    iRet = Addition(brr, iCount);
    printf("Addition is: %d\n", iRet);


    // Step 5: After using that memory free it explicitly
    free(brr);

    return 0;
}


