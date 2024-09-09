#include<iostream>
using namespace std;

template <class T>

T Addition(T arr[], int iSize){
    T iSum = 0;
    for(int i = 0; i < iSize; i++){
        iSum = iSum + arr[i];
    }
    return iSum;
}


int main(){
    int iLen = 0;
    float fRet = 0.0f;
    float *ptr = NULL;

    cout<<"Enter no of elements: "<<endl;
    cin>>iLen;

    ptr = new float[iLen];
    
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<iLen; i++){
        cin>>ptr[i];
    }

    cout<<"Entered elements are: "<<endl;
    for(int i=0; i<iLen; i++){
        cout<<ptr[i]<<"\n";
    }

    fRet = Addition(ptr, iLen);
    cout<<"Addition of elements is: "<<fRet<<"\n";

    delete []ptr;

    return 0;
}