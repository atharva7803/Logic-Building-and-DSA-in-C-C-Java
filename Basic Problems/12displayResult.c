/*

    0 to 35 : Fail 
    35 to 100 : Pass class
    50 to 60 : Second class
    60 to 75 : First class
    75 to 100 : Distinction class

*/

#include<stdio.h>

#define RET_INVALID -1

#define RET_FAIL 1
#define RET_PASS 2
#define RET_SECOND 3
#define RET_FIRST 4
#define RET_DISTINCTION 5

int displayResult(float fNo){
    if((fNo < 0.0f) || (fNo > 100.0f)){     // filter
        return RET_INVALID;
    }

    if((fNo >= 0.0f) && (fNo < 35.0f)){
        return RET_FAIL;
    }
    else if((fNo >= 35.0f) && (fNo < 50.0f)){
        return RET_PASS;
    }
    else if((fNo >= 50.0f) && (fNo < 60.0f)){
        return RET_SECOND;
    }
    else if((fNo >= 60.0f) && (fNo < 75.0f)){
        return RET_FIRST;
    }
    else if((fNo >= 75.0f) && (fNo <= 100.0f)){
        return RET_DISTINCTION;
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
    else if(iRes == RET_SECOND){
        printf("Student is pass in the exam with Second class\n");
    }
    else if(iRes == RET_FIRST){
        printf("Student is pass in the exam with First class\n");
    }
    else if(iRes == RET_DISTINCTION){
        printf("Student is having first class with Distinction class\n");
    }

    return 0;
}