#include<iostream>
using namespace std;

// This program is only int data type specific or if we write for any other data like float, double type it will only work for that specific data type.

int Addition(int no1, int no2){
    int ans;

    ans = no1 + no2;

    return ans;
}

int main(){
    int value1 = 10, value2 = 20;
    int ret = 0;

    ret = Addition(value1, value2);

    cout<<"Addition is: "<<ret<<endl;

    return 0;
}