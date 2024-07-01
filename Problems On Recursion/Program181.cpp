#include<iostream>
using namespace std;

// Approach 3 : Using Recursion
void Display(){
    static int i = 0;             
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