
// Find hexadecimal of 11th and 12th bit

// 0000     0000    0000    0000    0000    1100    0000    0000
// 0        0       0       0       0       c       0       0
// 0x00000c00

#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 0x00000c00;
    unsigned int iResult = 0;

    printf("Enter number: \n");
    scanf("%u", &iNo);

    iResult = iNo & iMask;

    if(iResult == iMask){
        printf("11th and 12th bit is On\n");
    } else{
        printf("11th and 12th bit is Off\n");
    }   

    return 0;
}





