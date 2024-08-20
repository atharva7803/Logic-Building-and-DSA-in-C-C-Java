// Userdefined code
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
    int iChoice = 0;
    int iNo = 0;

    cout<<"----------- Implementaion of Queue -----------\n";
    while(iChoice != 5)
    {
        cout<<"Please select your choice : \n";
        cout<<"1 : Insert new element in Queue\n";
        cout<<"2 : Remove the element from Queue\n";
        cout<<"3 : Display the elements form Queue\n";
        cout<<"4 : Count number of elements in Queue\n";
        cout<<"5 : Exit\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the element that you want to insert : \n";
                cin>>iNo;
                obj.Enqueue(iNo);
            break;

            case 2:
                iNo = obj.Dequeue();
                if(iNo != -1)
                {
                    cout<<"Removed element from Queue is : "<<iNo<<"\n";
                }
            break;

            case 3:
                obj.Display();
            break;

            case 4:
                iNo = obj.Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";
            break;

            case 5:
                cout<<"Thank you for using our application\n";
            break;
        }
    }

    return 0;
}