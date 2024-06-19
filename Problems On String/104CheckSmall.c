#include<stdio.h>
#include<stdbool.h>

bool CheckCapital(char ch){
    if((ch >= 'a') && (ch <= 'b')){
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
        printf("Its is a small letter\n");
    }
    else{
        printf("Its not a small letter\n");
    }

    return 0;
}