#include<stdio.h>
#include<stdbool.h>


bool checkRange(int iNo){
    if((iNo >= 10) && (iNo <= 20)){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    int iValue = 0;
    bool bRes = false;

    printf("Enter number: ");
    scanf("%d", &iValue);

    bRes = checkRange(iValue);

    if(bRes == true){
        printf("%d is in the range 10 and 20\n", iValue);
    }
    else{
        printf("%d is not in the range 10 and 20\n", iValue);
    }

    return 0;
}