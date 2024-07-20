#include<iostream>
using namespace std;

void strcpyCapitalX(char *Dest, char *Src){     // Dont copy space
    while(*Src != '\0'){
        if(*Src != ' '){
            *Dest = *Src;
            Dest++;
        }
        Src++;
    }
    *Dest = '\0';
}

int main() {
    char arr[30];
    char brr[30];

    cout<<"Enter the source string: "<<endl;
    cin.getline(arr, 30);

    strcpyCapitalX(brr, arr);      

    cout<<"Destination String is: "<<brr<<endl;

    return 0;
}