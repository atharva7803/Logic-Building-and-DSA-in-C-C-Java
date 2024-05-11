#include<stdio.h>

void Display(int iNo){
    int iCnt = 0;
    while(iCnt < iNo){
        printf("Jay Hanuman...\n");
        iCnt++;
    }
}

int main(){

    int iValue = 0;
    printf("Enter the number of frequency to print statement: ");
    scanf("%d", &iValue);
    
    Display(iValue);

    return 0;
}