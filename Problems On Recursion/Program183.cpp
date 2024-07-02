#include<iostream>
using namespace std;

// Approach 3 : Using Recursion
void Display(int iNo){
    static int i = 0;            // this statement executes only once 
    if(i < iNo){
        cout <<"*"<<endl;
        i++;
        Display(iNo);
    }
    cout<<"End of Display!"<<endl;
}

int main(){

    int iValue = 0;

    cout<<"Enter number: "<<endl;
    cin>>iValue;

    Display(iValue);

    cout<<"End of application!"<<endl;

    return 0;
}