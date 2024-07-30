#include<stdio.h>

void strToggleX(char *str){
    while(*str != '\0'){
        if((*str >= 'a') && (*str <= 'z')){
            (*str) = (*str) - 32;
        }
        else if((*str >= 'A') && (*str <= 'Z')){
            (*str) = (*str) + 32;
        }
        str++;
    }
}

int main(){

    char arr[30];

    printf("Enter String: \n");
    scanf("%[^'\n']s", arr);

    strToggleX(arr);

    printf("Updated string is: %s\n", arr);

    return 0;
}