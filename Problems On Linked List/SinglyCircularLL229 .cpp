#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;
typedef struct node* PNode;

class SinglyCL
{
    private:
        PNode First;
        PNode Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyCL::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void SinglyCL::Display()
{
    if (First == NULL && Last == NULL) {
        cout<<"Linked List is empty\n";
        return;
    }
    
    do{
        cout<<"| %d | -> ", First->data;
        First = First->next;
    } while(First != Last -> next);

    cout<<"\n";
}

int SinglyCL::Count(){
    return iCount;
} 

void SinglyCL::InsertFirst(int no)
{
    PNode newn = NULL;

    newn = new Node;

    newn -> data = no;
    newn -> next = NULL;

    if(First == NULL && Last == NULL){
        First = newn;
        Last = newn;   
    }
    else{
        newn -> next = First;
        First = newn;
    }

    (Last) -> next = First;
}

void SinglyCL::InsertLast(int no)
{
    PNode newn = NULL;      
     
    newn = new Node;

    newn -> data = no;                      
    newn -> next = NULL;

    if(First == NULL && Last == NULL){
        First = newn;
        Last = newn;   
    }
    else{       
        (Last) -> next = newn;
        Last = newn;     
    }

    (Last) -> next = First;
}

void SinglyCL::InsertAtPos(int no, int iPos)
{
    int iLen = 0;
    PNode newn = NULL;
    PNode temp = NULL;


    if(iPos < 1 || iPos > iCount+1){      
        printf("Invalid Position\n");
        return;
    }    

    if(iPos == 1){
        InsertFirst(no);
    }

    else if(iPos == iCount + 1){
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
        
    }
}

void SinglyCL::DeleteFirst()
{
    
}

void SinglyCL::DeleteLast()
{}

void SinglyCL::DeleteAtPos(int iPos)
{}

int main()
{
    SinglyCL obj;



    return 0;
}
