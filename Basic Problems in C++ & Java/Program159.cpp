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
    char arr[30];
    char brr[30];

    cout<<"Enter the source string: "<<endl;
    cin.getline(arr, 30);

    strcpyX(brr, arr);      

    cout<<"Destination String is: "<<brr<<endl;

    return 0;
}