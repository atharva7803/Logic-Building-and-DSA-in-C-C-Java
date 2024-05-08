#include<stdio.h>
#include<stdbool.h>


bool displayResult(float fNo){
    if((fNo < 0.0f) || (fNo > 100.0f)){     // filter
        printf("Invalid Input\n");
        return false;
    }
    if((fNo >= 0.0f) && (fNo < 35.0f)){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    float fValue = 0;
    bool bRes = false;

    printf("Enter your percentage: ");
    scanf("%f", &fValue);

    bRes = displayResult(fValue);

    if(bRes == true){
        printf("Student is pass in the exam\n");
    }
    else{
        printf("Student is fail in the exam\n");
    }

    return 0;
}