#include<iostream>
using namespace std;

// This program is generic program as it can work for any datatype

template <class T>

T Addition(T no1, T no2){
    T ans;

    ans = no1 + no2;

    return ans;
}

int main(){
    // here we can take any datatype
    double dValue1 = 10.78, dValue2 = 11.07;      
    double dRet = 0.0;

    int iValue1 = 10, iValue2 = 20;
    int iRet = 0;

    float fValue1 = 10.45f, fValue2 = 20.62f;
    float fRet = 0.0;


    iRet = Addition(iValue1, iValue2);
    cout<<"Addition of integer is: "<<iRet<<endl;

    fRet = Addition(fValue1, fValue2);
    cout<<"Addition of float is: "<<fRet<<endl;

    dRet = Addition(dValue1, dValue2);
    cout<<"Addition of double is: "<<dRet<<endl;

    return 0;
}