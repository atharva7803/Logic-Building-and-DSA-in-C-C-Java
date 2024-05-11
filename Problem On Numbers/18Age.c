/*
Age          Price  
0 - 4         Free
4 - 10        900
10 - 50       2000
50 or more    500
*/

#include<stdio.h>


///////////////////////////////////////////////////////////// 
//
//  Function Name: calculatePrice
//  Description: It is used to perform calculate ticket price based on age 
//  Input: Integer
//  Output: Integer
//  Author: Atharva Vilas Bhoite
//  Date: 29/04/2024
//
//////////////////////////////////////////////////////////////


int calculatePrice(int iAge){
    if((iAge >= 0) && (iAge <= 4)){     
        return 0;
    }
    else if((iAge > 4) && (iAge <= 10)){
        return 900;
    }
    else if((iAge > 10) && (iAge <= 50)){
        return 2000;
    }
    else{
        return 500;
    }
}

int main(){
    int iValue = 0;
    int iRes = 0;

    printf("Enter your Age: ");
    scanf("%d", &iValue);

    iRes = calculateFactor(iValue);
    printf("Your ticket value is: %d\n", iRes);

    return 0;
}