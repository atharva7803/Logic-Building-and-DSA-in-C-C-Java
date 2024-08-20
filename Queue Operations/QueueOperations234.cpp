#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;
typedef struct node* PNode;

class Queue{
    private:
        PNode First;
        int iCnt;
    public:
        Queue();
        void Display();
        int Count();
        void Enqueue(int no);      // Same as InsertLast()
        int Dequeue();             // Same as DeleteFirst()
};


Queue::Queue(){
    cout<<"Inside Constructor!"<<endl;
    First = NULL;
    iCnt = 0;
}


void Queue:: Display(){
    PNode temp = First;

    cout<<"Elements of Queue are: "<<endl;
    while(temp != NULL){
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;

}


int Queue:: Count(){
    return iCnt;
}


void Queue:: Enqueue(int no){
    PNode newn = NULL;
    PNode temp = NULL;

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


int Queue::Dequeue(){
    
    PNode temp = NULL;
    int iValue = 0;

    if(First == NULL){
        cout<<"Unable to pop element as Queue is empty!"<<endl;
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

    Queue obj;
    int iRet = 0;

    obj.Enqueue(10);
    obj.Enqueue(20);
    obj.Enqueue(30);
    obj.Enqueue(40);
    obj.Enqueue(50);
    obj.Enqueue(60);
    obj.Enqueue(70);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the Queue are: "<<iRet<<endl;


    // -------------------------------------------------------------------------------

    iRet = obj.Dequeue();

    cout<<"Removed element is: "<<iRet<<endl;

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the Queue are: "<<iRet<<endl;


    // -------------------------------------------------------------------------------

    iRet = obj.Dequeue();

    cout<<"Removed element is: "<<iRet<<endl;

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the Queue are: "<<iRet<<endl;


    // -------------------------------------------------------------------------------

    obj.Enqueue(100);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the Queue are: "<<iRet<<endl;

    return 0;
}