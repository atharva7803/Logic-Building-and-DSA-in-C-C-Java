
/* Off the bit of the number whose 4th bit is On
 Input:12     0   0   0   0   [1]   1   0   0
 Output: 4    0   0   0   0   [0]   1   0   0     here 4th bit is off


            0   0   0   0   1   1   0   0
            1   1   1   1   0   1   0   0
            ----------------------------- &
            0   0   0   0   0   1   0   0


    1111    1111    1111    1111    1111    1111    1111    0111    here 4ht  bit should be off
    f       f       f       f       f       f       f       7
    0xfffffff7

*/


#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 0xfffffff7;
    unsigned int iResult = 0;

    printf("Enter number: \n");
    scanf("%u", &iNo);

    iResult = iNo & iMask;

    printf("Updated number is: %u\n", iResult);  

    return 0;
}





