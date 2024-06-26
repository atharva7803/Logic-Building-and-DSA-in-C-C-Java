// Chechk whether 'l' is present in string or not

#include<stdio.h>
#include<stdbool.h>

bool CheckOccurence(char *str){
    bool bFlag = false;
    while(*str != '\0'){
        if(*str == 'l' || *str == 'L') {
            bFlag = true;
            break;
        }
        str++;
    }
    return bFlag;
}

int main(){

    char Arr[10];
    int iRet = 0;

    printf("Enter String: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    iRet = CheckOccurence(Arr);

    if(iRet == true){
        printf("l is present in string\n");
    } else{
        printf("l is not present in string\n");
    }

    return 0;
}