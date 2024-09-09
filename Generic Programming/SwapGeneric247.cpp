#include<iostream>
using namespace std;

template <class T>
void Swap(T &a, T &b){
    T temp;

    temp = a;
    a = b;
    b = temp;
}


int main(){
    char iVal1 = 'a', iVal2 = 'b';
    int iVal3 = 10, iVal4 = 20;

    cout<<"Value of value-1 variable is: "<<iVal1<<endl;
    cout<<"Value of value-2 variable is: "<<iVal2<<endl;

    Swap(iVal1, iVal2);

    cout<<"Value of value-1 variable after swapping is: "<<iVal1<<endl;
    cout<<"Value of value-2 variable after swapping is: "<<iVal2<<endl;



    cout<<"Value of value-3 variable is: "<<iVal3<<endl;
    cout<<"Value of value-4 variable is: "<<iVal4<<endl;

    Swap(iVal3, iVal4);

    cout<<"Value of value-3 variable after swapping is: "<<iVal3<<endl;
    cout<<"Value of value-4 variable after swapping is: "<<iVal4<<endl;
    return 0;
}