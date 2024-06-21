#include<stdio.h>

void Display(char *str){
    while(*str != '\0'){
        printf("%c\n", *str);
        str++;
    }
}

int main(){

    char Arr[50];

    printf("Enter your full name: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    Display(Arr);

    return 0;
}