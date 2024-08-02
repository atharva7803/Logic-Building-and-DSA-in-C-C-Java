
// Check whether 9th bit is on or off


#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 256;
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





