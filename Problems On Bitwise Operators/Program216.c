
/* Toggle the 4th bit
    Position: 4

    Input: 12       0   0   0   0   [1]   1   0   0
    Input: 4        0   0   0   0   [0]   1   0   0

    Input: 21       0   0   0   1   [0]   1   0   1
    Input: 29       0   0   0   1   [1]   1   0   1


                    0   0   0   0   [1]   1   0   0     here toggle the 4th bit
                    0   0   0   0   [1]   0   0   0
                    --------------------------------  ^  
                    0   0   0   0   [0]   1   0   0    

----------------------------------------------------------------

                    0   0   0   0   [0]   1   0   0     here toggle the 4th bit
                    0   0   0   0   [1]   0   0   0
                    --------------------------------  ^  
                    0   0   0   0   [1]   1   0   0  


*/


#include<stdio.h>
#include<stdbool.h>


int main(){
    unsigned int iNo = 0;
    unsigned int iMask = 0x00000008;
    unsigned int iResult = 0;

    printf("Enter number: \n");
    scanf("%u", &iNo);

    iResult = iNo ^ iMask;

    printf("Updated number is: %u\n", iResult);  

    return 0;
}





