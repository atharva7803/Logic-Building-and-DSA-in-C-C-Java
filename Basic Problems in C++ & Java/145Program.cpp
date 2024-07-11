// Accept n number from user and calculate no of digits of each numbers individually

#include<iostream>
using namespace std;

class ArrayX{
    private:        // changed to private
        int *Arr;
        int iSize;

    public:
        ArrayX(int no){
            cout<<"Inside Constructor"<<endl;
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX(){
            cout<<"Inside Destructor"<<endl;
            delete []Arr;
        }

        void Accept(){
            cout<<"Enter the elements: "<<endl;
            for(int i = 0; i < iSize; i++){
                cin>>Arr[i];
            }
        }

        int CountDigitsIndividually(int iNo) {
                int iCount = 0;
                while(iNo != 0){
                    iCount++;
                    iNo = iNo / 10;
                }
                return iCount;
        }

        void DisplayDigitCount(){       // heavy approach
            int iRet = 0;
            for(int i = 0; i < iSize; i++){
                iRet = CountDigitsIndividually(Arr[i]);
                cout<<Arr[i]<<" contains "<<iRet<<" digits in it! "<<endl;
            }
        }
};

int main(){
    
    int iLen = 0;

    cout<<"Enter the no of elements that you want to store: "<<endl;
    cin>>iLen;

    ArrayX *aobj = new ArrayX(iLen);        // Dynamic object creation

    aobj->Accept();

    aobj->DisplayDigitCount();


    delete aobj;

    return 0;
}