#include<iostream>
using namespace std;

int CountDigit(int iNo){
    static int iCnt = 0;
    if(iNo != 0){
        iCnt++;
        iNo /= 10;
        CountDigit(iNo);
    }
    return iCnt;
}

int main(){

    int iValue = 0, iRet = 0;

    cout<<"Enter number: "<<endl;
    cin>>iValue;

    iRet = CountDigit(iValue);

    cout<<"Number of digits are: "<<iRet<<endl;

    return 0;
}