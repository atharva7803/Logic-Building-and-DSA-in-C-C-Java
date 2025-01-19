// 5. Write a program which accept range from user and display all numbers in between that range in reverse order.

// Input: 23 35
// Output:  35 34 33 32 31 30 29 28 27 26 25 24 23

// Input: 10 18
// Output: 18 17 16 15 14 13 12 11 10

// Input: 10 10
// Output: 10

// Input:90 18
// Output: Invalid range

#include<stdio.h>

void RangeDisplayRev(int iStart, int iEnd){
    if(iStart > iEnd){
        printf("Invalid Range!");
    }
    while(iStart <= iEnd){
        printf("%d ", iEnd);
        iEnd--;
    }
}

int main(){
    int iValue1 = 0, iValue2 = 0;

    printf("Enter starting point: "); 
    scanf("%d", &iValue1);

    printf("Enter ending point: "); 
    scanf("%d", &iValue2);

    RangeDisplayRev(iValue1, iValue2);

    return 0;
}