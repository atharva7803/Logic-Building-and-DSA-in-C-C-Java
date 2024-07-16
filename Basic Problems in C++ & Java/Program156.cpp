#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char arr[30] = "Hello World";
    char brr[30];

    strcpy(brr,arr);
    
    cout<<"Destination string is: "<<brr<<endl;

    return 0;

}