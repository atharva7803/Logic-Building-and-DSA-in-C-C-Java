#include<stdio.h>

int main(){
    char ch;

    printf("Enter one character: \n");
    scanf("%c", &ch);

    printf("Entered character is: %c\n", ch);

    printf("ASCII value of that character is: %d\n", ch);

    return 0;
}