#include<iostream>
using namespace std;

int DisplaySum(int iNo){      // Using Recursion
    static int iSum = 0;
    static int i = 1;
    if(i <= iNo){
        iSum += i;
        i++;
        DisplaySum(iNo);
    }
    return iSum;
}

int main(){

    int iValue = 0, iRet = 0;

    cout<<"Enter number: "<<endl;
    cin>>iValue;

    iRet = DisplaySum(iValue);

    cout<<"Addition is: "<<iRet<<endl;

    return 0;
}