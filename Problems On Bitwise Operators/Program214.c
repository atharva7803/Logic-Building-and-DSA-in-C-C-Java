
/* Off the bit of the number whose 16th bit is On

    1111    1111    1111    1111    0111    1111    1111    1111    here 4ht  bit should be off
    f       f       f       f       7       f       f       f
    0xffff7fff

*/


#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 0xffff7fff;
    unsigned int iResult = 0;

    printf("Enter number: \n");
    scanf("%u", &iNo);

    iResult = iNo & iMask;

    printf("Updated number is: %u\n", iResult);  

    return 0;
}





