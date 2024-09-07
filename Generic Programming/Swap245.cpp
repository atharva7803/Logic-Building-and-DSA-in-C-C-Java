#include<iostream>
using namespace std;


void Swap(int &a, int &b){
    int temp;

    temp = a;
    a = b;
    b = temp;
}


int main(){
    int iVal1 = 10, iVal2 = 20;

    cout<<"Value of value-1 variable is: "<<iVal1<<endl;
    cout<<"Value of value-2 variable is: "<<iVal2<<endl;

    Swap(iVal1, iVal2);

    cout<<"Value of value-1 variable after swapping is: "<<iVal1<<endl;

    cout<<"Value of value-2 variable after swapping is: "<<iVal2<<endl;

    return 0;
}