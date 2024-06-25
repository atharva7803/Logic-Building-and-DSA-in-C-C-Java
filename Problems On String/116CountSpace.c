// Count the no of spaces

#include<stdio.h>

int CountSpace(char *str){
    int iCount = 0;
    while(*str != '\0'){
        if(*str == ' ') {
            iCount++;
        }
        str++;
    }
    return iCount;
}

int main(){

    char Arr[100];
    int iRet = 0;

    printf("Enter String: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    iRet = CountSpace(Arr);

    printf("Space Count: %d\n", iRet);

    return 0;
}