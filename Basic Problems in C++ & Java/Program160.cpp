#include<iostream>
using namespace std;

void strcpySmallX(char *Dest, char *Src){
    while(*Src != '\0'){
        if(*Src >= 'a' && *Src <= 'z'){
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

    strcpySmallX(brr, arr);      

    cout<<"Destination String is: "<<brr<<endl;

    return 0;
}