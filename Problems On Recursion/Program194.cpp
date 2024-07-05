#include<iostream>
using namespace std;


int strLenX(char *str) {        
    int iLen = 0;
    while(*str != '\0'){
        iLen++;
        str++;
    }
    return iLen;
}

int main(){

    char arr[30];
    int iRet = 0; 

    cout<<"Enter string: "<<endl;

    cin.getline(arr,30);

    iRet = strLenX(arr);

    cout<<"String length is: "<<iRet<<endl;

    return 0;
}