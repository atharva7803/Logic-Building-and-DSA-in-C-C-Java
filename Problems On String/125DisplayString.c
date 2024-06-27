// Display String using for loop

#include<stdio.h>

void Display(char str[]){
    int iCnt = 0;

    for(iCnt = 0; str[iCnt] != '\0'; iCnt++){
        printf("%c\n", str[iCnt]);
    }
}

int main(){

    char Arr[100];

    printf("Enter String: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    Display(Arr);

    return 0;
}