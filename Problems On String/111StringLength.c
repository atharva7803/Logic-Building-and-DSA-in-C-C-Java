#include<stdio.h>

int strlenX(char *str){
    int iCount = 0;

    while(*str != '\0'){
        iCount++;
        str++;
    }
    return iCount;
}

int main(){

    char Arr[50];
    int iRet = 0;

    printf("Enter your full name: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    iRet = strlenX(Arr);

    printf("String length is: %d\n", iRet);

    return 0;
}