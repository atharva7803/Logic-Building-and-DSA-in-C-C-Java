#include<iostream>
using namespace std;

void strcpyX(char *Dest, char *Src){
    while(*Src != '\0'){
        *Dest = *Src;

        Src++;
        Dest++;
    }
    *Dest = '\0';
}

int main() {
    char arr[30] = "Hello";
    char brr[30];

    strcpyX(brr, arr);      

    cout<<"Copied String is: "<<brr<<endl;

    return 0;
}