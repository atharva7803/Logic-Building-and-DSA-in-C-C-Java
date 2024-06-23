// Count the no of capital characters

#include<stdio.h>

int strCapital(char *str){
    int iCount = 0;
    while(*str != '\0'){
        if((*str >= 'A') && (*str <= 'Z')){
            iCount++;
        }
        str++;
    }
    return iCount;
}

int main(){

    char Arr[50];
    int iRet = 0;

    printf("Enter String: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    iRet = strCapital(Arr);

    printf("Capital Character Count: %d\n", iRet);

    return 0;
}