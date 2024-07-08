#include<iostream>
using namespace std;

int main(){
    int iLen = 0, i =0;
    int *ptr = NULL;

    cout<<"Enter no of elements that you want to store: "<<endl;
    cin>>iLen;

    ptr = new int[iLen];

    cout<<"Enter the elements: "<<endl;
    for(i  = 0; i < iLen; i++){
        cin>>ptr[i];
    }

    cout<<"Entered elements are: "<<endl;
    for(i  = 0; i < iLen; i++){
        cout<<ptr[i]<<endl;
    }

    delete []ptr;

    return 0;
}