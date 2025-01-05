// 2. Accept one number from user and print that number of * on screen.

void Display(int iNo)
{   
    int iCnt = 0;
    while(iNo > iCnt){
        printf(" * "); 
        iNo --;
    }
}

int main(){
    int iValue = 0;

    printf("Enter number: "); 
    scanf("%d", &iValue );

    Display (iValue);

    return 0;
}