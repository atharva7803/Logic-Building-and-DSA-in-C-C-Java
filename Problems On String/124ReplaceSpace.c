// Replace space in string with _

#include<stdio.h>
#include<stdbool.h>

void UpdateString(char *str){
    while(*str != '\0'){
        if(*str == ' '){
            *str = '_';
        }
        str++;
    }
}

int main(){

    char Arr[100];

    printf("Enter String: \n");
    scanf("%[^'\n']s", Arr);        // regular expression

    UpdateString(Arr);

    printf("Updates string: %s\n", Arr);

    return 0;
}