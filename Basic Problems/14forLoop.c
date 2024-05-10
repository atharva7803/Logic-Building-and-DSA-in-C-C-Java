#include<stdio.h>

void Display(int iNo){
    for(int iCnt = 0; iCnt < iNo; iCnt++){
        printf("Jay Hanuman...\n");
    }
}

int main(){

    int iValue = 0;
    printf("Enter the number of frequency to print statement: ");
    scanf("%d", &iValue);
    
    Display(iValue);

    return 0;
}