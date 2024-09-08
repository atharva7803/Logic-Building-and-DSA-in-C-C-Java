// LL of Integer

#include<iostream>
using namespace std;

template <class T>
struct node{
    int data;
    struct node<T> *next;
};


template <class T>
class SinglyLL{
    private:
        struct node<T> * First;
        int iCnt;

    public:
        SinglyLL();     // Constructor

        void Display();
        int Count();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL(){                   // Constructor
    cout<<"Inside Constructor!\n";
    First = NULL;
    iCnt = 0;
}

// -------------------------------------------------------------

template <class T>
void SinglyLL<T>::Display(){
    struct node<T> * temp = First;         // Replace PNode with struct node *

    while(temp != NULL){
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

// -------------------------------------------------------------

template <class T>
int SinglyLL<T>::Count(){

    return iCnt;
} 

// -------------------------------------------------------------

template <class T>
void SinglyLL<T>::InsertFirst(T no){

    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(First == NULL){      // Or if(iCnt == 0)
        First = newn;
    }
    else{
        newn -> next = First;
        First = newn;
    }

    iCnt++;

}

// -------------------------------------------------------------

template <class T>
void SinglyLL<T>::InsertLast(T no){

    struct node<T>* newn = NULL;
    struct node<T>* temp = NULL;

    newn = new struct node<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(First == NULL){
        First = newn;
    }
    else{
        temp = First;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newn;
    }

    iCnt++;
}

// -------------------------------------------------------------

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos){
    struct node<T>* newn = NULL;
    struct node<T>* temp = NULL;


    if(iPos < 1 || iPos > iCnt+1){
        cout << "Invalid Position" << endl;
        return;
    }

    if(iPos == 1){
        InsertFirst(no);
    }
    else if(iPos == iCnt + 1){
        InsertLast(no);
    }
    else{
        newn = new struct node<T>;

        newn -> data = no;
        newn -> next = NULL;

        temp = First;
        for(int i = 1; i < iPos-1; i++){
            temp = temp -> next;
        }    
        newn -> next = temp -> next;
        temp -> next = newn;

        iCnt++;
    }

    
}

// -------------------------------------------------------------

template <class T>
void SinglyLL<T>::DeleteFirst(){
    struct node<T>* temp = NULL;

    if(First == NULL){      // Or if(iCnt == 0)
        cout<<"LL is empty!"<<endl;
        return;
    }
    else if(First -> next == NULL){     // Or if(iCnt == 1)
        delete First;
        First = NULL;
    }
    else{        
        temp = First;                      
        First = First -> next;
        delete temp;
    }
    iCnt--;
}

// -------------------------------------------------------------

template <class T>
void SinglyLL<T>::DeleteLast(){
    struct node<T>* temp = NULL;

    if(First == NULL){      // Or if(iCnt == 0)
        cout<<"LL is empty!"<<endl;
        return;
    }
    else if(First -> next == NULL){     // Or if(iCnt == 1)
        delete First;
        First = NULL;
    }
    else{        
        temp = First;  
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }                    
        delete(temp -> next);
        temp -> next = NULL;
    }

    iCnt--;
}

// -------------------------------------------------------------

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos){
    struct node<T>* newn = NULL;
    struct node<T>* temp1 = NULL;
    struct node<T>* temp2 = NULL;
    int iLen = 0;

    iLen = Count();

    
    if(iPos == 1){
        DeleteFirst();
    }
    else if(iPos < 1 || iPos > iLen){
        cout << "Invalid Position" << endl;
        return;
    }
    else if(iPos == iLen){
        DeleteLast();
    }
    else{

        temp1 = First;
        for(int i = 1; i < iPos-1; i++){
            temp1 = temp1 -> next;
        }    
        temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete(temp2);
    }

    iCnt--;
}




int main(){

    SinglyLL<int> *iObj = new SinglyLL<int>();
    int iRet = 0;

    iObj->InsertFirst(51);
    iObj->InsertFirst(21);
    iObj->InsertFirst(11);

    iObj->Display();

    iRet = iObj->Count();

    cout<<"Number of elements are: "<<iRet<<endl;

    // -------------------------------------------------------------

    
    iObj->InsertLast(101);
    iObj->InsertLast(201);
    iObj->InsertLast(301);

    iObj->Display();

    iRet = iObj->Count();

    cout<<"Number of elements are: "<<iRet<<endl;

    // -------------------------------------------------------------

    
    iObj->InsertAtPos(71, 4);

    iObj->Display();

    iRet = iObj->Count();

    cout<<"Number of elements are: "<<iRet<<endl;

    // -------------------------------------------------------------
    
    iObj->DeleteFirst();

    iObj->Display();

    iRet = iObj->Count();

    cout<<"Number of elements are: "<<iRet<<endl;

    // -------------------------------------------------------------
    
    iObj->DeleteLast();

    iObj->Display();

    iRet = iObj->Count();

    cout<<"Number of elements are: "<<iRet<<endl;

        // -------------------------------------------------------------
    
    iObj->DeleteAtPos(4);

    iObj->Display();

    iRet = iObj->Count();

    cout<<"Number of elements are: "<<iRet<<endl;


    return 0;
}