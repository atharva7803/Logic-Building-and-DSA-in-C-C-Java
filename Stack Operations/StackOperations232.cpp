#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;
typedef struct node* PNode;

class Stack{
    
    private:
        PNode First;
        int iCnt;

    public:
        Stack();
        void Display();
        int Count();
        void Push(int no);      // Same as InsertFirst()
        int Pop();             // Same as DeleteFirst()
};


Stack::Stack(){
    cout<<"Inside Constructor!"<<endl;
    First = NULL;
    iCnt = 0;
}


void Stack:: Display(){
    PNode temp = First;

    cout<<"Elements of Stack are: "<<endl;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;

}


int Stack:: Count(){
    return iCnt;
}


void Stack:: Push(int no){
    PNode newn = NULL;

    newn = new Node;

    newn -> data = no;
    newn -> next = NULL;

    if(First == NULL){
        First = newn;
    }
    else{
        newn -> next = First;
        First = newn;
    }

    iCnt++;
}    


int Stack::Pop(){
    
    PNode temp = NULL;
    int iValue = 0;

    if(First == NULL){
        cout<<"Unable to pop element as Stack is empty!"<<endl;
        return -1;
    }
    else{
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;

        iCnt--;
    }

    return iValue;
}



int main(){

    Stack obj;
    int iRet = 0;

    obj.Push(10);
    obj.Push(20);
    obj.Push(30);
    obj.Push(40);
    obj.Push(50);
    obj.Push(60);
    obj.Push(70);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the stack are: "<<iRet<<endl;


    // -------------------------------------------------------------------------------

    iRet = obj.Pop();

    cout<<"Poped element is: "<<iRet<<endl;

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the stack are: "<<iRet<<endl;


    // -------------------------------------------------------------------------------

    iRet = obj.Pop();

    cout<<"Poped element is: "<<iRet<<endl;

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the stack are: "<<iRet<<endl;


    // -------------------------------------------------------------------------------

    obj.Push(100);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the stack are: "<<iRet<<endl;

    return 0;
}