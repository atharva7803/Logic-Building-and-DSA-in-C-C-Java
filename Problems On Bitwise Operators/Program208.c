
// Find hexadecimal of 8


#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 0x00000008;
    unsigned int iResult = 0;

    printf("Enter number: \n");
    scanf("%u", &iNo);

    iResult = iNo & iMask;

    if(iResult == iMask){
        printf("4th bit is On\n");
    } else{
        printf("4th bit is Off\n");
    }   

    return 0;
}





