#include<stdio.h>
#include<stdbool.h>

bool CheckCapital(char ch){
    if((ch >= '0') && (ch <= '9')){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char cValue;
    bool bRet = false;

    printf("Enter one character: \n");
    scanf("%c", &cValue);

    bRet = CheckCapital(cValue);
    if(bRet == true){
        printf("Its is a digit\n");
    }
    else{
        printf("Its not a digit\n");
    }

    return 0;
}