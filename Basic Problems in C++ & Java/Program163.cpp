#include<iostream>
#include<string.h>
using namespace std;


int main() {
    char arr[30] = "Hello World";
    char brr[30] = "India";

    strcat(brr, arr);      

    cout<<"Destination String is: "<<brr<<endl;

    return 0;
}