// To display commenting concept

#include<stdio.h>

float addtion(
    float fno1,             // First input
    float fno2              // Second input
    ) {
    float fans = 0.0;       // Varaible to stor result
    fans = fno1 + fno2;
    return fans;
}

int main(){

    // int i, j, k;
    float fValue1 = 0.0;    // Varaible to store first input 
    float fValue2 = 0.0;    // Variable to store second input 
    float fResult = 0.0;    // Variable to store return value

    printf("Enter the first number: ");
    scanf("%f", &fValue1);

    printf("Enter the second number: ");
    scanf("%f", &fValue2);

    fResult = addtion(fValue1, fValue2);

    printf("Addition is: %f\n", fResult);

    return 0;
}