#include<stdio.h>

// void Display(int *ptr, int iSize)    internall it will convert as
void Display(int ptr[], int iSize){

    int i = 0;

    for(i = 0; i < iSize; i++){
        printf("%d\n", ptr[i]);
        // printf("%d\n", *(ptr + i));
    }
}

int main(){

    int arr[5] = {10,20,30,40,50};

    Display(arr, 5);

    return 0;
}