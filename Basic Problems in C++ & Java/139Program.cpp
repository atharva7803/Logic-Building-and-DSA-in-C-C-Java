#include<iostream>
using namespace std;

float Average(int Arr[], int iSize){
    int iSum = 0;
    for(int i = 0; i < iSize; i++){
        iSum = iSum + Arr[i];
    }
    return ((float)iSum/ (float)iSize);
}

int main(){
    int iLen = 0, i =0;
    float fRet = 0;
    int *ptr = NULL;

    cout<<"Enter no of elements that you want to store: "<<endl;
    cin>>iLen;

    ptr = new int[iLen];

    cout<<"Enter the elements: "<<endl;
    for(i  = 0; i < iLen; i++){
        cin>>ptr[i];
    }

    fRet = Average(ptr, iLen);

    cout<<"Average is: "<<fRet<<endl;

    delete []ptr;

    return 0;
}