// Generic Singly Linear LL Code

#include <iostream>
using namespace std;

template <class T>
struct nodeSL {
    T data;
    struct nodeSL<T> *next;
};

template <class T>
class SinglyLL {
private:
    struct nodeSL<T> *First;
    int iCnt;

public:
    SinglyLL(); // Constructor

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
SinglyLL<T>::SinglyLL() { // Constructor
    cout << "Inside Constructor!\n";
    First = NULL;
    iCnt = 0;
}

template <class T>
void SinglyLL<T>::Display() {
    struct nodeSL<T> *temp = First;

    while (temp != NULL) {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T>
int SinglyLL<T>::Count() {
    return iCnt;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no) {
    struct nodeSL<T> *newn = new struct nodeSL<T>;

    newn->data = no;
    newn->next = NULL;

    if (First == NULL) { // Or if(iCnt == 0)
        First = newn;
    } else {
        newn->next = First;
        First = newn;
    }

    iCnt++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no) {
    struct nodeSL<T> *newn = new struct nodeSL<T>;

    newn->data = no;
    newn->next = NULL;

    if (First == NULL) {
        First = newn;
    } else {
        struct nodeSL<T> *temp = First;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCnt++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos) {
    if (iPos < 1 || iPos > iCnt + 1) {
        cout << "Invalid Position" << endl;
        return;
    }

    if (iPos == 1) {
        InsertFirst(no);
    } else if (iPos == iCnt + 1) {
        InsertLast(no);
    } else {
        struct nodeSL<T> *newn = new struct nodeSL<T>;

        newn->data = no;
        newn->next = NULL;

        struct nodeSL<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++) {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCnt++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst() {
    if (First == NULL) { // Or if(iCnt == 0)
        cout << "LL is empty!" << endl;
        return;
    } else if (First->next == NULL) { // Or if(iCnt == 1)
        delete First;
        First = NULL;
    } else {
        struct nodeSL<T> *temp = First;
        First = First->next;
        delete temp;
    }
    iCnt--;
}

template <class T>
void SinglyLL<T>::DeleteLast() {
    if (First == NULL) { // Or if(iCnt == 0)
        cout << "LL is empty!" << endl;
        return;
    } else if (First->next == NULL) { // Or if(iCnt == 1)
        delete First;
        First = NULL;
    } else {
        struct nodeSL<T> *temp = First;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCnt--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos) {
    int iLen = Count();

    if (iPos < 1 || iPos > iLen) {
        cout << "Invalid Position" << endl;
        return;
    } else if (iPos == 1) {
        DeleteFirst();
    } else if (iPos == iLen) {
        DeleteLast();
    } else {
        struct nodeSL<T> *temp1 = First;
        for (int i = 1; i < iPos - 1; i++) {
            temp1 = temp1->next;
        }
        struct nodeSL<T> *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCnt--;
    }
}

int main() {
    //-------------------Linked List of Integer---------------------------
    SinglyLL<int> *iObj = new SinglyLL<int>();
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
    SinglyLL<char> *cObj = new SinglyLL<char>();

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
    SinglyLL<float> *fObj = new SinglyLL<float>();

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
    SinglyLL<double> *dObj = new SinglyLL<double>();

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

