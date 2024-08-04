
// Find hexadecimal of 6th and 9th bit

// 0000     0000    0000    0000    0000    0001    0010    0000
// 0        0       0       0       0       1       2       0
// 0x00000120

#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 0x00000120;
    unsigned int iResult = 0;

    printf("Enter number: \n");
    scanf("%u", &iNo);

    iResult = iNo & iMask;

    if(iResult == iMask){
        printf("6th and 9th bit is On\n");
    } else{
        printf("6th and 9th bit is Off\n");
    }   

    return 0;
}





