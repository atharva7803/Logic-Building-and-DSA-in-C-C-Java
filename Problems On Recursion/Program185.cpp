#include<iostream>
using namespace std;

void DisplayRev(int iNo){
    if(iNo > 0){
        cout<<iNo<<endl;
        iNo--;
        DisplayRev(iNo);
    }
}

int main(){

    int iValue = 0;

    cout<<"Enter number: "<<endl;
    cin>>iValue;

    DisplayRev(iValue);

    cout<<"End of application!"<<endl;

    return 0;
}