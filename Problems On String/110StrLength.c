#include<stdio.h>
#include<string.h>

int main(){

    char Arr[50];
    int iRet = 0;

    printf("Enter your full name: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    iRet = strlen(Arr);

    printf("String length is: %d\n", iRet);

    return 0;
}