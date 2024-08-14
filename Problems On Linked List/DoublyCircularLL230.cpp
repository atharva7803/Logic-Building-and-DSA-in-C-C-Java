#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;
typedef struct node* PNode;


class DoublyCL{
    private:
        PNode First;
        PNode Last;
        int iCnt;
    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};


// ----------------------------------------------------------------------

DoublyCL::DoublyCL(){
    cout<<"Inside Counstructor"<<endl;
    First = NULL;
    Last = NULL;
    iCnt = 0;
}


// ----------------------------------------------------------------------

int DoublyCL::Count(){
    return iCnt;
}


// ----------------------------------------------------------------------

void DoublyCL::Display(){
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

void DoublyCL::InsertFirst(int no){
    PNode newn = NULL;

    newn = new Node;

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

void DoublyCL::InsertLast(int no){
    PNode newn = NULL;

    newn = new Node;

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
void DoublyCL::InsertAtPos(int no, int iPos){     
    PNode newn = NULL;
    PNode temp = NULL;

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
        newn = new Node;

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

void DoublyCL::DeleteFirst(){

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

void DoublyCL::DeleteLast(){

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

void DoublyCL::DeleteAtPos(int iPos){

    PNode temp = NULL;

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

    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements are: "<<iRet<<endl;


    // -------------------------------------------------------------

    
    obj.InsertLast(101);
    obj.InsertLast(201);
    obj.InsertLast(301);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements are: "<<iRet<<endl;

    // -------------------------------------------------------------

    obj.InsertAtPos(71, 4);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements are: "<<iRet<<endl;


    // -------------------------------------------------------------
    
    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements are: "<<iRet<<endl;

    // -------------------------------------------------------------
    
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements are: "<<iRet<<endl;

    // -------------------------------------------------------------
    
    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements are: "<<iRet<<endl;



    return 0;
}