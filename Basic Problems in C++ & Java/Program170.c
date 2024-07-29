#include<stdio.h>

void toLowerCase(char *str){
    while(*str != '\0'){
        if(*str >= 'A' && (*str <= 'Z')){
            (*str) = (*str) + 32;
        }
        str++;
    }
}

int main(){

    char arr[30];

    printf("Enter String: \n");
    scanf("%[^'\n']s", arr);

    toLowerCase(arr);

    printf("Updated string is: %s\n", arr);

    return 0;
}