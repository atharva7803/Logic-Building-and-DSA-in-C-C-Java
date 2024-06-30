#include<iostream>
using namespace std;

// Approach 3 : Using Recursion
void Display(){
    auto i = 0;             // infinite 
    if(i < 4){
        cout <<"*"<<endl;
        i++;
        Display();
    }
}

int main(){

    Display();

    return 0;
}