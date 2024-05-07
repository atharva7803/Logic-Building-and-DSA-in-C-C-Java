// Problem Statement:- 
// Accept two numbers from user and perfrom their addition.


#include<stdio.h>

int main(){

    int i, j, k;
    printf("Enter the first number: ");
    scanf("%d", &i);

    printf("Enter the second number: ");
    scanf("%d", &j);

    k = i + j;

    printf("Addition is: %d\n", k);

    return 0;
}