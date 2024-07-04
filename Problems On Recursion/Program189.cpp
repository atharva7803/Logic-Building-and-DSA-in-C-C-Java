#include<iostream>
using namespace std;

void DisplayReverse(int iNo){
    int iDigit = 0;
    if(iNo != 0){
        iDigit = iNo % 10;
        cout<<iDigit<<endl;
        iNo /= 10;
        DisplayReverse(iNo);
    }
}

int main(){

    int iValue = 0, iRet = 0;

    cout<<"Enter number: "<<endl;
    cin>>iValue;

    DisplayReverse(iValue);

    return 0;
}