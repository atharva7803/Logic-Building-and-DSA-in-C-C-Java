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

        void Display(){
            cout<<"Elements are: "<<endl;
            for(int i = 0; i < iSize; i++){
                cout<<Arr[i]<<endl;
            }
        }

        float Average(){
            int iSum = 0;
            float fAns = 0.0f;
            for(int i = 0; i < iSize; i++){
                iSum = iSum + Arr[i];
            }
            fAns = (float)iSum/ (float)iSize;
            return fAns;
        }
};

int main(){
    
    int iLen = 0;
    float fRet = 0;

    cout<<"Enter the no of elements that you want to store: "<<endl;
    cin>>iLen;

    ArrayX aobj(iLen);

    aobj.Accept();
    aobj.Display();

    fRet = aobj.Average();

    cout<<"Average is: "<<fRet<<endl;

    return 0;
}