#include<iostream>
using namespace std;

// Approach 2

int Addition(int iNo1, int iNo2){
    int iAns = 0;
    iAns = iNo1 + iNo2;
    return iAns;
}

int main(){
    int iValue1 = 0, iValue2 = 0;
    int iAns = 0;

    cout<<"Enter first no: "<<endl;
    cin>>iValue1;

    cout<<"Enter second no: "<<endl;
    cin>>iValue2;

    iAns = Addition(iValue1, iValue2);

    cout<<"Addition is: "<<iAns<<endl;

    return 0;
}