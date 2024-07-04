#include<iostream>
using namespace std;

int SumDigit(int iNo) {
    static int iSum = 0;
    if (iNo != 0) {
        iSum = iSum + (iNo % 10); 
        SumDigit(iNo / 10);
    }
    return iSum;
}

int main(){

    int iValue = 0, iRet = 0;

    cout<<"Enter number: "<<endl;
    cin>>iValue;

    iRet = SumDigit(iValue);

    cout<<"Sum of digits are: "<<iRet<<endl;

    return 0;
}