#include<iostream>
using namespace std;

class ArrayX{
    public:
        int *Arr;
        int iSize;

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

        void Display(){
            cout<<"Elements are: "<<endl;
            for(int i = 0; i < iSize; i++){
                cout<<Arr[i]<<endl;
            }
        }
};

int main(){
    
    int iLen = 0;

    cout<<"Enter the no of elem that you want to store: "<<endl;
    cin>>iLen;

    ArrayX aobj(iLen);

    aobj.Accept();
    aobj.Display();

    return 0;
}