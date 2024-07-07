#include<iostream>
using namespace std;

// Approach 3

class Arithmetic{
    public:
        int iNo1;
        int iNo2;

        Arithmetic(int a = 0, int b = 0){
            iNo1 = a;
            iNo2 = b;
        }
        int Addition(){
            int iAns = 0;
            iAns = iNo1 + iNo2;
            return iAns;
        }
};

int main(){
    int iValue1 = 0, iValue2 = 0;
    int iAns = 0;

    cout<<"Enter first no: "<<endl;
    cin>>iValue1;

    cout<<"Enter second no: "<<endl;
    cin>>iValue2;

    Arithmetic aobj(iValue1, iValue2);

    iAns = aobj.Addition();

    cout<<"Addition is: "<<iAns<<endl;

    return 0;
}