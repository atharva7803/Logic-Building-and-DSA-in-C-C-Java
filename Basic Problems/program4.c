/* Problem Statement:- 
 Accept two floating numbers from user and perfrom their addition.
 Code with proper coding conventions

 Step 1: Understand the problem statement
 Step 2: Write the algorithm
 Step 3: Decide the programming language
 Step 4: Write the program
 Step 5: Test the program


Step1 : Understand the problem statement
        We conclude that the 2 numbers are of floating point format

Step2: Write the algorithm
        START
        1. Accept first number from user and consider it as no1.
        2. Accept second number from user and consider it as no2.
        3. Create one variable to store the answer as ans.
        4. Perform the addtition of no1 and no2.
        5. Store the result into ans.
        6. Display the value of ans as a result.
        STOP    

Step3: Decide the programming language
        We are going to write in C language for this program.

Step4: Write the program

Step5: Test the program
        Test Cases:-

        Input 1 = 10.0, Input 2 = 20.0
        Output = 30.0

        Input 2 = 10.0, Input 2 = 0
        Output = 10.0

        Input 3 = 0 Input 2 = 20.0
        Output = 20.0

        Input 4 = 0 Input 2 = 0
        Output = 0.0

        Input 5 = 10.0 Input 2 = -7.0
        Output = 3.0

        Input 1 = -10.0 Input 2 = -7.0
        Output = -17.0

*/

#include<stdio.h>

///////////////////////////////////////////////////////////// 
//
//  Function Name: addition
//  Description: It is used to perform addition of 2 floats
//  Input: float, float
//  Output: float
//  Author: Atharva Vilas Bhoite
//  Date: 15/04/2024
//
//////////////////////////////////////////////////////////////

float addtion(float fno1, float fno2){
    float fans = 0.0;
    fans = fno1 + fno2;
    return fans;
}

//////////////////////////////////////////////////////////////
// Function name: main
// Description: It is a entry point function
//////////////////////////////////////////////////////////////

int main(){

    // int i, j, k;
    float fValue1 = 0.0, fValue2 = 0.0;     // i stands for integer data type
    float fResult = 0.0;

    printf("Enter the first number: ");
    scanf("%f", &fValue1);

    printf("Enter the second number: ");
    scanf("%f", &fValue2);

    fResult = addtion(fValue1, fValue2);

    printf("Addition is: %f\n", fResult);

    return 0;
}