// 4. Accept one character from user and convert case of that character.

// Input: a
// Output: A

// Input: D
// Output: d

#include<stdio.h>
#include<ctype.h>

void DisplayConvert (char CValue){
    if(islower(CValue)){
        printf("%c\n", toupper(CValue));
    }
    else if(isupper(CValue)){
        printf("%c\n", tolower(CValue));
    }
    else {
        printf("Character is not a letter.\n");
    }
}

int main(){
    char cValue = '\0';

    printf("Enter character: \n");
    scanf("%c",&cValue);

    DisplayConvert(cValue);

    return 0;
}