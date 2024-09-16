// Generic Doubly Circular LL Code

#include<iostream>
using namespace std;

template <class T>
struct nodeDC{
    T data;
    struct nodeDC<T> *next;
    struct nodeDC<T> *prev;
};

template <class T>
class DoublyCL{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCnt;
    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};


// ----------------------------------------------------------------------
template <class T>
DoublyCL<T>::DoublyCL(){
    cout<<"Inside Counstructor"<<endl;
    First = NULL;
    Last = NULL;
    iCnt = 0;
}


// ----------------------------------------------------------------------
template <class T>
int DoublyCL<T>::Count(){
    return iCnt;
}


// ----------------------------------------------------------------------
template <class T>
void DoublyCL<T>::Display(){
    if (First == NULL && Last == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    
    cout<<"<->";
    do{
        cout<<"| "<<First->data<<" | <-> ";
        First = First->next;
    } while(First != Last -> next);

    cout<<endl;
}


// ------------------------------------------------------------------------
template <class T>
void DoublyCL<T>::InsertFirst(T no){
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL && Last == NULL){
        First = newn;
        Last = newn;   
    }
    else{
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }

    Last -> next = First;
    First -> prev = Last;

    iCnt++;
}


// ------------------------------------------------------------------------
template <class T>
void DoublyCL<T>::InsertLast(T no){
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL && Last == NULL){
        First = newn;
        Last = newn;   
    }
    else{
        Last -> next = newn;
        newn -> prev = Last;
        Last = newn;
    }

    Last -> next = First;
    First -> prev = Last;

    iCnt++;
}


// ********************************************************************

// Insert At Position
template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos){     
    struct nodeDC<T> * newn = NULL;
    struct nodeDC<T> * temp = NULL;

    if(iPos < 1 || iPos > iCnt + 1){
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
        newn = new nodeDC<T> ;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = First;

        for(int i = 1; i < iPos-1; i++){
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;      
        newn -> prev = temp;
    }

    iCnt++;
}


// ------------------------------------------------------------------------
template <class T>
void DoublyCL<T>::DeleteFirst(){

    if(First == NULL && Last == NULL){
        printf("Unable to delete as Linked List is Empty!\n");
        return;  
    }
    else if(First == Last){
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else{
        First = First -> next;
        delete First -> prev;       // Or delete Last -> next 

        Last -> next = First;
        First -> prev = Last; 
    }

    iCnt--;
}



// ------------------------------------------------------------------------
template <class T>
void DoublyCL<T>::DeleteLast(){

    if(First == NULL && Last == NULL){
        printf("Unable to delete as Linked List is Empty!\n");
        return;  
    }
    else if(First == Last){
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else{
        Last = Last -> prev;
        delete First -> prev;       // Or delete Last -> next 

        Last -> next = First;
        First -> prev = Last; 
    }

    iCnt--;
}



// ------------------------------------------------------------------------
template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos){

    struct nodeDC<T> * temp = NULL;

    if(iPos < 1 || iPos > iCnt){
        cout << "Invalid Position" << endl;
        return;
    }

    if(iPos == 1){
        DeleteFirst();
    }
    else if(iPos == iCnt){
        DeleteLast();
    }

    else{
        temp = First;

        for(int i = 1; i < iPos-1; i++){
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = temp -> next -> next;
        temp -> next -> prev = temp;
    }

    iCnt--;
}



int main(){

    //-------------------Linked List of Integer---------------------------
    DoublyCL<int> *iObj = new DoublyCL<int>();
    int iRet = 0;

    cout << "-----------------Linked List of Integer------------------" << endl;
    iObj->InsertFirst(51);
    iObj->InsertFirst(21);
    iObj->InsertFirst(11);

    iObj->Display();

    iRet = iObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    iObj->InsertLast(101);
    iObj->InsertLast(201);
    iObj->InsertLast(301);

    iObj->Display();
    iRet = iObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    iObj->InsertAtPos(71, 4);
    iObj->Display();
    iRet = iObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    iObj->DeleteFirst();
    iObj->Display();
    iRet = iObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    iObj->DeleteLast();
    iObj->Display();
    iRet = iObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    iObj->DeleteAtPos(4);
    iObj->Display();
    iRet = iObj->Count();
    cout << "Number of elements are: " << iRet << endl;


    // ------------------------Linked List of Character-----------------------------
    cout << "-----------------Linked List of Character------------------" << endl;
    DoublyCL<char> *cObj = new DoublyCL<char>();

    cObj->InsertFirst('C');
    cObj->InsertFirst('B');
    cObj->InsertFirst('A');

    cObj->Display();
    iRet = cObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    cObj->InsertLast('d');
    cObj->InsertLast('e');
    cObj->InsertLast('f');

    cObj->Display();
    iRet = cObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    cObj->InsertAtPos('z', 4);
    cObj->Display();
    iRet = cObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    cObj->DeleteFirst();
    cObj->Display();
    iRet = cObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    cObj->DeleteLast();
    cObj->Display();
    iRet = cObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    cObj->DeleteAtPos(4);
    cObj->Display();
    iRet = cObj->Count();
    cout << "Number of elements are: " << iRet << endl;


    //-------------------Linked List of float---------------------------
    DoublyCL<float> *fObj = new DoublyCL<float>();

    cout << "-----------------Linked List of Float------------------" << endl;
    fObj->InsertFirst(51.54f);
    fObj->InsertFirst(21.54f);
    fObj->InsertFirst(11.54f);

    fObj->Display();

    iRet = fObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    fObj->InsertLast(101.51f);
    fObj->InsertLast(201.56f);
    fObj->InsertLast(301.53f);

    fObj->Display();
    iRet = fObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    fObj->InsertAtPos(45.54f, 4);
    fObj->Display();
    iRet = fObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    fObj->DeleteFirst();
    fObj->Display();
    iRet = fObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    fObj->DeleteLast();
    fObj->Display();
    iRet = fObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    fObj->DeleteAtPos(4);
    fObj->Display();
    iRet = fObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    

    //-------------------Linked List of Double---------------------------
    DoublyCL<float> *dObj = new DoublyCL<float>();

    cout << "-----------------Linked List of Double------------------" << endl;
    dObj->InsertFirst(51.85551);
    dObj->InsertFirst(2651.065165);
    dObj->InsertFirst(65.6516);

    dObj->Display();

    iRet = dObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    dObj->InsertLast(894.6515);
    dObj->InsertLast(32156.651);
    dObj->InsertLast(8962.51);

    dObj->Display();
    iRet = dObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    dObj->InsertAtPos(984.651, 4);
    dObj->Display();
    iRet = dObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    dObj->DeleteFirst();
    dObj->Display();
    iRet = dObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    dObj->DeleteLast();
    dObj->Display();
    iRet = dObj->Count();
    cout << "Number of elements are: " << iRet << endl;

    dObj->DeleteAtPos(4);
    dObj->Display();
    iRet = dObj->Count();
    cout << "Number of elements are: " << iRet << endl;



    return 0;
}