// Take character form user and check if that character is present in string or not

#include<stdio.h>
#include<stdbool.h>

bool CheckOccurence(char *str, char ch){
    bool bFlag = false;
    while(*str != '\0'){
        if(*str == ch) {
            bFlag = true;
            break;
        }
        str++;
    }
    return bFlag;
}

int main(){

    char Arr[100];
    char cValue;
    int bRet = false;

    printf("Enter String: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    printf("Enter the character that you want to search: \n");
    scanf("%c", &cValue);           // problem: not taking character (bcz after giving string we press enter and input buffer takes that enter as the input)

    bRet = CheckOccurence(Arr, cValue);

    if(bRet == true){
        printf("Character is present in string!\n");
    } else{
        printf("Character is not present in string!\n");
    }

    return 0;
}