#include<iostream>
using namespace std;

template <class T>

T Maximum(T arr[], int iSize){
    T iMax = arr[0];
    for(int i = 0; i < iSize; i++){
        if(iMax < arr[i]){
            iMax = arr[i];
        }
    }
    return iMax;
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

    fRet = Maximum(ptr, iLen);
    cout<<"Addition of elements is: "<<fRet<<"\n";

    delete []ptr;

    return 0;
}