#include<stdio.h>


int displayResult(float fNo){
    if((fNo < 0.0f) || (fNo > 100.0f)){     // filter
        return 0;
    }
    if((fNo >= 0.0f) && (fNo < 35.0f)){
        return 1;
    }
    else{
        return 2;
    }
}

int main(){
    float fValue = 0;
    int iRes = 0;

    printf("Enter your percentage: ");
    scanf("%f", &fValue);

    iRes = displayResult(fValue);

    if(iRes == 0){
        printf("Your Input is Invalid\n");
    }
    else if(iRes == 1){
        printf("Student is fail in the exam\n");
    }
    else if(iRes == 2){
        printf("Student is pass in the exam\n");
    }

    return 0;
}