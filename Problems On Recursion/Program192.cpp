#include<iostream>
using namespace std;

void FactorsI(int iNo) {        // Iterative approach
    int i = 1;
    // for(i = 1; i <= iNo/2; i++){
    //     if(iNo % i == 0){
    //         cout<<i<<endl;
    //     }
    // }

    while(i <= iNo/2){
        if(iNo % i == 0){
            cout<<i<<endl;
        }
        i++;
    }
}

void FactorsR(int iNo) {        // Recursive approach
    static int i = 1;
    while(i <= iNo/2){
        if(iNo % i == 0){
            cout<<i<<endl;
        }
        i++;
        FactorsR(iNo);
    }
}

int main(){

    int iValue = 0, iRet = 0;

    cout<<"Enter number: "<<endl;
    cin>>iValue;

    FactorsR(iValue);

    return 0;
}