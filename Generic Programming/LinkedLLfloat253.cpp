// LL of Float

#include<iostream>
using namespace std;


struct node{
    float data;
    struct node *next;
};

typedef struct node Node;
typedef struct node* Pnode;


class SinglyLL{
    private:
        Pnode First;
        int iCnt;

    public:
        SinglyLL();     // Constructor

        void Display();
        int Count();

        void InsertFirst(float no);
        void InsertLast(float no);
        void InsertAtPos(float no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyLL::SinglyLL(){                   // Constructor
    cout<<"Inside Constructor!\n";
    First = NULL;
    iCnt = 0;
}

// -------------------------------------------------------------


void SinglyLL::Display(){
    Pnode temp = First;

    while(temp != NULL){
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

// -------------------------------------------------------------


int SinglyLL::Count(){

    return iCnt;
} 

// -------------------------------------------------------------


void SinglyLL::InsertFirst(float no){

    Pnode newn = NULL;

    newn = new Node;

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


void SinglyLL::InsertLast(float no){

    Pnode newn = NULL;
    Pnode temp = NULL;

    newn = new Node;

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


void SinglyLL::InsertAtPos(float no, int iPos){
    Pnode newn = NULL;
    Pnode temp = NULL;


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
        newn = new Node;

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


void SinglyLL::DeleteFirst(){
    Pnode temp = NULL;

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

void SinglyLL::DeleteLast(){
    Pnode temp = NULL;

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


void SinglyLL::DeleteAtPos(int iPos){
    Pnode newn = NULL;
    Pnode temp1 = NULL;
    Pnode temp2 = NULL;
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

    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51.94f);
    obj.InsertFirst(21.90f);
    obj.InsertFirst(11.95f);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements are: "<<iRet<<endl;

    // -------------------------------------------------------------

    
    obj.InsertLast(101.90f);
    obj.InsertLast(201.90f);
    obj.InsertLast(301.90f);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements are: "<<iRet<<endl;

    // -------------------------------------------------------------

    
    obj.InsertAtPos(71.90f, 4);

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