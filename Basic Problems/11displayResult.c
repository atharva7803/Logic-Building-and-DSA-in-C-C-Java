#include<stdio.h>

#define RET_INVALID 1
#define RET_PASS 2
#define RET_FAIL 3

int displayResult(float fNo){
    if((fNo < 0.0f) || (fNo > 100.0f)){     // filter
        return RET_INVALID;
    }
    if((fNo >= 0.0f) && (fNo < 35.0f)){
        return RET_FAIL;
    }
    else{
        return RET_PASS;
    }
}

int main(){
    float fValue = 0;
    int iRes = 0;

    printf("Enter your percentage: ");
    scanf("%f", &fValue);

    iRes = displayResult(fValue);

    if(iRes == RET_INVALID){
        printf("Your Input is Invalid\n");
    }
    else if(iRes == RET_FAIL){
        printf("Student is fail in the exam\n");
    }
    else if(iRes == RET_PASS){
        printf("Student is pass in the exam\n");
    }

    return 0;
}