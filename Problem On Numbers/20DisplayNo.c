#include <stdio.h>

void Display(int iNo) {
    int iCnt = 1;

    for(int iCnt = 1; iCnt <= iNo; iCnt++){
        printf("%d\n", iCnt);
    }
}

int main() {
    int iValue = 0;
    printf("Enter the number of times to print a number: ");
    scanf("%d", &iValue);  
    
    Display(iValue);

    return 0;
}
