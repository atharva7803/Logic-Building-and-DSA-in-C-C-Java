#include<iostream>
using namespace std;


int CountCapital(char *str) {        // Using Recursion     
    static int iCnt = 0;
    if(*str != '\0'){
        if(*str >= 'A' && *str <= 'Z'){
            iCnt++;
        }
        str++;
        CountCapital(str);
    }
    return iCnt;
}

int main(){

    char arr[30];
    int iRet = 0; 

    cout<<"Enter string: "<<endl;

    cin.getline(arr,30);

    iRet = CountCapital(arr);

    cout<<"String length is: "<<iRet<<endl;

    return 0;
}