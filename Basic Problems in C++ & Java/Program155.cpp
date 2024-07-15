#include<iostream>
using namespace std;

int strLenX( char *str) {
    int iLen = 0;
    while (str[iLen] != '\0') {
        iLen++;
    }
    return iLen;
}

int main(){
    char arr[30];
    int iRet = 0;

    cout<<"Enter your name: "<<endl;
    cin.getline(arr, 30);           // to accept multiple words or lines
    
    iRet = strLenX(arr);

    cout<<"Lenght of string is: "<<iRet<<endl;
    
    return 0;

}