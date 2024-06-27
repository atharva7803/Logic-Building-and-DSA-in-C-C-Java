// Take character form user and return its last occurence position

#include<stdio.h>
#include<stdbool.h>

int CheckOccurence(char *str, char ch){
    int iCnt = 1, iPosition = -1;

    while(*str != '\0'){
        if(*str == ch){
            iPosition = iCnt;
        }
        iCnt++;
        str++;
    }

    return iPosition;
}

int main(){

    char Arr[100];
    char cValue;
    int iRet = 0;

    printf("Enter String: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    printf("Enter the character that you want to search: \n");
    scanf(" %c", &cValue);           // Solution: put space before %c

    iRet = CheckOccurence(Arr, cValue);

    if(iRet != -1){
        printf("Last Occurence of letter is: %d\n", iRet);
    } else{
        printf("There is no such letter!\n");
    }

    return 0;
}