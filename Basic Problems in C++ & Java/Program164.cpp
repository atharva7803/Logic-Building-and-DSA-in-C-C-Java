#include<iostream>
using namespace std;

void strcatX(char *Dest, char *Src){     // Concatenate string
    
    while(*Dest != '\0'){
        Dest++;
    }

    while(*Src != '\0'){
        *Dest = *Src;
        Dest++;
        Src++;
    }
    *Dest = '\0';
}

int main() {
    char arr[30];
    char brr[30] = "Hello ";

    cout<<"Enter the source string: "<<endl;
    cin.getline(arr, 30);

    strcatX(brr, arr);      

    cout<<"Destination String is: "<<brr<<endl;

    return 0;
}