#include<stdio.h>

// Bitwise Or (|)
int main(){
    unsigned int iNo1 = 0, iNo2 = 0, iRet = 0;

    printf("Enter first number: \n");
    scanf("%d", &iNo1);

    printf("Enter second number: \n");
    scanf("%d", &iNo2);

    iRet = iNo1 | iNo2;

    printf("Result of bitwise | is: %u\n",iRet);

    return 0;
}


/*      
        OP1     OP2     Result
        1       1       1
        1       0       1
        0       1       1
        0       0       0

        iNo1        11      0 0 0 0 1 0 1 1
        iNo1        15      0 0 0 0 1 1 1 1
        ------------------------------------- &
                            0 0 0 0 1 1 1 1   = 15


        iNo1        67      0 1 0 0 0 0 1 1
        iNo1        34      0 0 1 0 0 0 1 0
        ------------------------------------- &
                            0 1 1 0 0 0 1 1   = 99  
*/




