
// Find hexadecimal of 4096 (13th bit)

// 0000     0000    0000    0000    0001    0000    0000    0000
// 0        0       0       0       1       0       0       0
// 0x00001000

#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 0x00001000;
    unsigned int iResult = 0;

    printf("Enter number: \n");
    scanf("%u", &iNo);

    iResult = iNo & iMask;

    if(iResult == iMask){
        printf("13th bit is On\n");
    } else{
        printf("13th bit is Off\n");
    }   

    return 0;
}





