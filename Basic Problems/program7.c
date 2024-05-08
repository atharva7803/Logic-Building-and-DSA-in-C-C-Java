// Problem Statement:-  Take one number from user and check whether that number is divisible by 3 and 5.
//                      (User is going to enter only positive inputs).

#include<stdio.h>
#include<stdbool.h>

// Algorithm
/*
    START
        1. Accept one number as No
        2. Divide that number No by 3
        3. If remainder is 0
        4. Divide that number No by 5
        5. If remainder is 0
                then display the number divisble by 3 and 5
                otherwise display the result as odd number
    STOP
*/


///////////////////////////////////////////////////////////// 
//
//  Function Name: checkDivisible
//  Description: It is used to check whether no is divisible by 3 & 5
//  Input: int
//  Output: boolean
//  Author: Atharva Vilas Bhoite
//  Date: 16/04/2024
//
//////////////////////////////////////////////////////////////



bool CheckDivisible(unsigned int iNo){
    if((iNo % 3 == 0) && (iNo % 5 == 0))  
        return true;
    else
        return false;
}

int main(){

    unsigned iValue = 0;
    bool bResult = false;

    printf("Enter the number : \n");
    scanf("%d",&iValue);

    bResult = CheckDivisible(iValue);

    if(bResult == true){
        printf("%d is divisible by 3 and 5\n", iValue);
    }   
    else{
        printf("%d is not divisible by either 3 or 5\n", iValue);
    }

    return 0;
}


/*

    Logical Operator

    First Number    Second Number        &&       ||
    true            true                true     true
    true            false               false    true
    false           true                false    true
    false           false               false    false

*/