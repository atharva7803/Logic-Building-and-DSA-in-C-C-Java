#include<stdio.h>

void toUpperCase(char *str){
    while(*str != '\0'){
        if((*str >= 'a') && (*str <= 'z')){
            (*str) = (*str) - 32;
        }
        str++;
    }
}

int main(){

    char arr[30];

    printf("Enter String: \n");
    scanf("%[^'\n']s", arr);

    toUpperCase(arr);

    printf("Updated string is: %s\n", arr);

    return 0;
}