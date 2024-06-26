// Take character form user and return its frequency

#include<stdio.h>
#include<stdbool.h>

int CountFreq(char *str, char ch){
    int iCnt = 0;

    while(*str != '\0'){
        if(*str == ch){
            iCnt++;
        }
        str++;
    }
    return iCnt;
}

int main(){

    char Arr[100];
    char cValue;
    int iRet = 0;

    printf("Enter String: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    printf("Enter the character that you want to search: \n");
    scanf(" %c", &cValue);           // Solution: put space before %c

    iRet = CountFreq(Arr, cValue);

    printf("Frequency: %d\n", iRet);

    return 0;
}