#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int iRet = 0;
    char arr[30] = "Hello World";

    iRet = strlen(arr);
    
    cout<<"Length of string is: "<<iRet<<endl;

    return 0;

}