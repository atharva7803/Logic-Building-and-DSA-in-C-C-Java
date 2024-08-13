#include<iostream>
using namespace std;


struct node{
    int data;
    struct node *next;
    struct node *prev;
};
 
typedef struct node Node;
typedef struct node* Pnode;


class DoublyLL{
    private:
        Pnode First;
        int iCnt;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        
};

DoublyLL::DoublyLL(){                   // Constructor
    cout<<"Inside Constructor!\n";
    First = NULL;
    iCnt = 0;
}

// -------------------------------------------------------------


void DoublyLL::Display(){
    Pnode temp = First;

    cout<<"NULL <->";
    while(temp != NULL){
        cout<<"| "<<temp->data<<" | <-> ";
        temp = temp -> next;
    }
    cout<<" NULL"<<endl;
}

// -------------------------------------------------------------


int DoublyLL::Count(){

    return iCnt;
} 

// -------------------------------------------------------------


void DoublyLL::InsertFirst(int no){

    Pnode newn = NULL;

    newn = new Node;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL){      // Or if(iCnt == 0)
        First = newn;
    }
    else{
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }

    iCnt++;

}

// -------------------------------------------------------------


void DoublyLL::InsertLast(int no){

    Pnode newn = NULL;
    Pnode temp = NULL;

    newn = new Node;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL){
        First = newn;
    }
    else{
        temp = First;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
    }

    iCnt++;
}

// -------------------------------------------------------------


void DoublyLL::InsertAtPos(int no, int iPos){
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
        newn -> prev = NULL;

        temp = First;
        for(int i = 1; i < iPos-1; i++){
            temp = temp -> next;
        }    
        newn -> next = temp -> next;
        newn -> prev = temp;
        temp -> next = newn;

        iCnt++;
    }
}



// -------------------------------------------------------------


void DoublyLL::DeleteFirst(){
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
        First -> prev = NULL;
        delete temp;
    }
    iCnt--;
}

// -------------------------------------------------------------

void DoublyLL::DeleteLast(){
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


void DoublyLL::DeleteAtPos(int iPos){
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
        temp2 -> next -> prev = temp1;
        delete(temp2);
    }

    iCnt--;
}


int main(){

    DoublyLL obj;
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