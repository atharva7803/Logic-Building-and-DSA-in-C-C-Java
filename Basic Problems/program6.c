// Problem Statement:-  Take one number from user and check whether that number is even or odd.
//                      (User is going to enter only positive inputs).

#include<stdio.h>
#include<stdbool.h>

// Algorithm
/*
    START
        1. Accept one number as No
        2. Divide that number No by 2
        3. If remainder is 0
                then displat the result as even number
                otherwise display the result as odd number
    STOP
*/


///////////////////////////////////////////////////////////// 
//
//  Function Name: checkEvenOdd
//  Description: It is used to check whether no is even or odd
//  Input: int
//  Output: boolean
//  Author: Atharva Vilas Bhoite
//  Date: 16/04/2024
//
//////////////////////////////////////////////////////////////



bool CheckEvenOdd(unsigned int iNo){
    if(iNo % 2 == 0) 
        return true;
    else
        return false;
}

int main(){

    unsigned iValue = 0;
    bool bResult = false;

    printf("Enter the number : \n");
    scanf("%d",&iValue);

    bResult = CheckEvenOdd(iValue);

    if(bResult == true){
        printf("%d is even number\n", iValue);
    }   
    else{
        printf("%d is odd number\n", iValue);
    }

    return 0;
}