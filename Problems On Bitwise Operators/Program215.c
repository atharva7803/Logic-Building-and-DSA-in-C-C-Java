
/* Off the bit of the number whose 10th bit is On

    1111    1111    1111    1111    0111    1101    1111    1111    here 4ht  bit should be off
    f       f       f       f       f       d       f       f
    0xfffffdff

*/


#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 0xfffffdff;
    unsigned int iResult = 0;

    printf("Enter number: \n");
    scanf("%u", &iNo);

    iResult = iNo & iMask;

    printf("Updated number is: %u\n", iResult);  

    return 0;
}





