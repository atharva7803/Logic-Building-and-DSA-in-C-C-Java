// Count the no of small characters

#include<stdio.h>

int strCapital(char *str){
    int iCount = 0;
    while(*str != '\0'){
        if((*str >= 'a') && (*str <= 'z')){
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

    printf("Small Character Count: %d\n", iRet);

    return 0;
}