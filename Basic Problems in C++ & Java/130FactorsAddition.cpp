#include<iostream>
using namespace std;

int SumFactors(int iNo){
    int iSum = 0;
    for(int i = 1; i <= iNo/2; i++){
        if(iNo % i == 0){
            iSum = iSum + i;
        }
    }
    return iSum;
}

int main(){

    int iValue = 0;
    int iRet = 0;

    cout<<"Enter no: "<<endl;
    cin>>iValue;

    iRet = SumFactors(iValue);

    cout<<"Summation of factors is: "<<iRet<<endl;

    return 0;
}