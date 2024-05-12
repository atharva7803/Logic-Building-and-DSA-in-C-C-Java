#include<stdio.h>

// Time Complexity: O(N/2)
void DisplayFactor(int iNo) {
    int iCnt = 1;

    printf("Factors of %d are: \n", iNo);
    for(int iCnt = 1; iCnt <= iNo/2 ; iCnt++){      // factors always come the half of number
        if(iNo % iCnt == 0) {
            printf("%d\n", iCnt);
        }    
    }
}


int main() {
    int iValue = 0;
    printf("Enter the number to find its factors: ");
    scanf("%d", &iValue);  
    
    DisplayFactor(iValue);

    return 0;
}