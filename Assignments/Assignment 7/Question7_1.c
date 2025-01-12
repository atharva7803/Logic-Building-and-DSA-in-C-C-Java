// 1. Write a program which accept number from user and display below pattern.

// Input: 5
// Output: *   *   *   *   *   #   #   #   #   #    

// Input:6
// Output: *   *   *   *   *   *   #   #   #   #   #   #

// Input: -5
// Output: *   *   *   *   *   #   #   #   #   #  

// Input:2
// Output: *   *   #   #

#include<stdio.h>

void Display(int iNo){      // TC: O(n)
    if(iNo < 0){
        iNo = -iNo;
    }
    for(int i = 1; i <= iNo; i++){
        printf("*\t");
    }
    for(int i = 1; i <= iNo; i++){
        printf("#\t");
    }
}

int main(){
    int iValue = 0;

    printf("Enter number: "); 
    scanf("%d",&iValue);

    Display(iValue);

    return 0;
}