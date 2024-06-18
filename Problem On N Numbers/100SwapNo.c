#include<stdio.h>


void Swap(int *p, int * q){
    int temp = 0;

    temp = *p;
    *p = * q;
    *q = temp;
}

int main(){

    int a = 0, b = 0;

    printf("Enter first number: \n");
    scanf("%d", &a);

    printf("Enter first number: \n");
    scanf("%d", &b);

    Swap(&a, &b);

    printf("Value of a after swapping: %d\n", a);
    printf("Value of b after swapping: %d\n", b);

    return 0;
}