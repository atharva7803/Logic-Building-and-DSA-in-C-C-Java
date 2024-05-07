// Problem Statement:- 
// Accept two numbers from user and perfrom their addition.
// Code with proper coding conventions

#include<stdio.h>

int main(){

    // int i, j, k;
    int iValue1 = 0, iValue2 = 0;     // i stands for integer data type
    int iResult = 0;

    printf("Enter the first number: ");
    scanf("%d", &iValue1);

    printf("Enter the second number: ");
    scanf("%d", &iValue2);

    iResult = iValue1 + iValue2;

    printf("Addition is: %d\n", iResult);

    return 0;
}