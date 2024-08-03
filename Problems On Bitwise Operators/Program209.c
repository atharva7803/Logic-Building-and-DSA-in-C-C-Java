
// Find hexadecimal of 256 (9th bit)

// 0000     0000    0000    0000    0000    0001    0000    0000
// 0        0       0       0       0       1       0       0
// 0x00000100

#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 0x00000100;
    unsigned int iResult = 0;

    printf("Enter number: \n");
    scanf("%u", &iNo);

    iResult = iNo & iMask;

    if(iResult == iMask){
        printf("9th bit is On\n");
    } else{
        printf("9th bit is Off\n");
    }   

    return 0;
}





