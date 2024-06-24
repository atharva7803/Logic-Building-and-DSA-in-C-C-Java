// Count the no of vowel characters

#include<stdio.h>

int CountVowel(char *str){       // Case Sensitive
    int iCount = 0;
    while(*str != '\0'){
        if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o'|| *str == 'u' ){
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

    iRet = CountVowel(Arr);

    printf("Vowel Count: %d\n", iRet);

    return 0;
}