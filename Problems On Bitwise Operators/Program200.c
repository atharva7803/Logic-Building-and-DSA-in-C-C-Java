#include<stdio.h>

void DisplayBinary(int iNo){
    int iDigit = 0;

    printf("Binary Conversion is: \n");

    while(iNo != 0){
        iDigit = iNo % 2;
        printf("%d",iDigit);
        iNo = iNo / 2;
    }
    printf("\n");
}

int main(){
    int iValue = 0;

    printf("Enter number: \n");
    scanf("%d", &iValue);

    DisplayBinary(iValue);

    return 0;
}