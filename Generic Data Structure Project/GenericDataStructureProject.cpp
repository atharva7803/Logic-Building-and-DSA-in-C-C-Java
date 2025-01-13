#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Code of Singly Linear Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSL {
    T data;
    struct nodeSL *next;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: SinglyLL
//  Description: Constructor for the SinglyLL class. Initializes the linked list.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<T>::SinglyLL() { // Constructor
    First = NULL;
    iCnt = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: Display
//  Description: Displays the elements of the Singly Linked List from start to end.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Display() {
    struct nodeSL<T> * temp = First;

    while (temp != NULL) {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: Count
//  Description: Returns the number of elements in the Singly Linked List.
//  Input: None
//  Output: int - The count of nodes in the list.
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::Count() {
    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertFirst
//  Description: Inserts a new element at the beginning of the Singly Linked List.
//  Input: T no - The data to be inserted.
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertFirst(T No) {
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // Memory allocation

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) { // if(iCnt == 0)
        First = newn;
    }
    else {
        newn->next = First;
        First = newn;
    }
    iCnt++;
}

//////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertLast
//  Description: Inserts a new element at the end of the Singly Linked List.
//  Input: T no - The data to be inserted.
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertLast(T No) {
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // Memory allocation

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) { // if(iCnt == 0)
        First = newn;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCnt++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertAtPos
//  Description: Inserts a new element at the specified position in the Singly Linked List.
//  Input: T no - The data to be inserted.
//         int iPos - The position at which the element should be inserted (1-based index).
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos) {
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if ((iPos < 1) || (iPos > iCnt + 1)) {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) {
        InsertFirst(No);
    }
    else if (iPos == iCnt + 1) {
        InsertLast(No);
    }
    else {
        temp = First;

        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for (i = 1; i < iPos - 1; i++) {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCnt++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteFirst
//  Description: Deletes the first element from the Singly Linked List.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteFirst() {
    struct nodeSL<T> * temp = First;

    if (First == NULL) {
        cout << "LL is empty\n";
        return;
    }
    else if (First->next == NULL) {
        delete First;
        First = NULL;
    }
    else {
        First = First->next;
        delete temp;
    }
    iCnt--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteLast
//  Description: Deletes the last element from the Singly Linked List.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteLast() {
    struct nodeSL<T> * temp = First;

    if (First == NULL) {
        cout << "LL is empty\n";
        return;
    }
    else if (First->next == NULL) {
        delete First;
        First = NULL;
    }
    else {
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCnt--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteAtPos
//  Description: Deletes the element at the specified position in the Singly Linked List.
//  Input: int iPos - The position of the element to be deleted (1-based index).
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos) {
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if ((iPos < 1) || (iPos > iCnt)) {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) {
        DeleteFirst();
    }
    else if (iPos == iCnt) {
        DeleteLast();
    }
    else {
        temp1 = First;

        for (i = 1; i < iPos - 1; i++) {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCnt--;
    }
}




////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Code of Singly Circular Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSC {
    T data;
    struct nodeSC *next;
};

template <class T>
class SinglyCL {

    private:
        struct nodeSC<T> *First;
        struct nodeSC<T> *Last;
        int iCnt;

    public:
        SinglyCL(); // Constructor

        void Display();
        int Count();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: SinglyCL
//  Description: Constructor for the SinglyCL class. Initializes the linked list.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::SinglyCL() { // Constructor
    First = NULL;
    iCnt = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: Display
//  Description: Displays the elements of the Singly Circular Linked List from start to end.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::Display() {
    if (First == NULL && Last == NULL) {
        cout << "Linked List is empty" << endl;
        return;
    }

    do {
        cout << "| " << First->data << " | -> ";
        First = First->next;
    } while(First != Last -> next);

    cout << "(back to first node)" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: Count
//  Description: Returns the number of elements in the Singly Circular Linked List.
//  Input: None
//  Output: int - The count of nodes in the list.
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::Count() {
    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertFirst
//  Description: Inserts a new element at the beginning of the Singly Circular Linked List.
//  Input: T no - The data to be inserted.
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertFirst(T No) {
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;    // Memory allocation

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) {    // if(iCnt == 0)
        First = newn;
        Last = newn;
    }
    else {
        newn->next = First;
        First = newn;
    }

    Last -> next = First;

    iCnt++;
}

//////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertLast
//  Description: Inserts a new element at the end of the Singly Circular Linked List.
//  Input: T no - The data to be inserted.
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertLast(T No) {
    struct nodeSC<T> * newn = NULL;
    struct nodeSC<T> * temp = First;

    newn = new nodeSC<T>;    // Memory allocation

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) { // if(iCnt == 0)
        First = newn;
        Last = newn;
    }
    else {
        Last -> next = newn;
        Last = newn;     
    }
    Last -> next = First;

    iCnt++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertAtPos
//  Description: Inserts a new element at the specified position in the Singly Circular Linked List.
//  Input: T no - The data to be inserted.
//         int iPos - The position at which the element should be inserted (1-based index).
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos) {
    struct nodeSC<T> * newn = NULL;
    struct nodeSC<T> * temp;

    if ((iPos < 1) || (iPos > iCnt + 1)) {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) {
        InsertFirst(No);
    }
    else if (iPos == iCnt + 1) {
        InsertLast(No);
    }
    else {
        temp = First;

        newn = new nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        for (int i = 1; i < iPos - 1; i++) {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCnt++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteFirst
//  Description: Deletes the first element from the Singly Circular Linked List.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteFirst() {

    if (First == NULL && Last == NULL) {
        cout << "Unable to delete as LL is empty\n";
        return;
    }
    else if (First == Last) {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else {
        First = First->next;
        delete (Last -> next);
        Last -> next = First;
    }
    iCnt--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteLast
//  Description: Deletes the last element from the Singly Circular Linked List.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteLast() {
    struct nodeSC<T> * temp = First;

    if (First == NULL && Last == NULL) {
        cout << "Unable to delete as LL is empty\n";
        return;
    }
    else if (First == Last) {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else {
        while(temp -> next != Last){
            temp = temp -> next;
        }
        delete(Last);
        Last = temp;
        Last -> next = First;
    }
    iCnt--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteAtPos
//  Description: Deletes the element at the specified position in the Singly Circular Linked List.
//  Input: int iPos - The position of the element to be deleted (1-based index).
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos) {

    struct nodeSC<T> * temp1;
    struct nodeSC<T> * temp2;

    if ((iPos < 1) || (iPos > iCnt)) {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) {
        DeleteFirst();
    }
    else if (iPos == iCnt) {
        DeleteLast();
    }
    else {
        temp1 = First;

        for (int i = 1; i < iPos - 1; i++) {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCnt--;
    }
}






////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Code of Doubly Linear Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeDL {
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL {
private:
    struct nodeDL<T> *First;
    int iCnt;

public:
    DoublyLL(); // Constructor

    void Display();
    int Count();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DoublyLL
//  Description: Constructor for the DoublyLL class. Initializes the linked list.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLL<T>::DoublyLL() { // Constructor
    First = NULL;
    iCnt = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: Display
//  Description: Displays the elements of the Doubly Linear Linked List from start to end.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::Display() {
    struct nodeDL<T> * temp = First;

    cout<<"NULL <->";
    while (temp != NULL) {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: Count
//  Description: Returns the number of elements in the Doubly Linear Linked List.
//  Input: None
//  Output: int - The count of nodes in the list.
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::Count() {
    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertFirst
//  Description: Inserts a new element at the beginning of the Doubly Linear Linked List.
//  Input: T no - The data to be inserted.
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertFirst(T No) {
    struct nodeDL<T> * newn = NULL;

    newn = new nodeDL<T>;   

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL) { // if(iCnt == 0)
        First = newn;
    }
    else {
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }
    iCnt++;
}

//////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertLast
//  Description: Inserts a new element at the end of the Doubly Linear Linked List.
//  Input: T no - The data to be inserted.
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
//////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertLast(T No) {
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = First;

    newn = new nodeDL<T>;    

    newn -> data = No;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertAtPos
//  Description: Inserts a new element at the specified position in the Doubly Linear Linked List.
//  Input: T no - The data to be inserted.
//         int iPos - The position at which the element should be inserted (1-based index).
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos) {
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;

    if ((iPos < 1) || (iPos > iCnt + 1)) {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) {
        InsertFirst(No);
    }
    else if (iPos == iCnt + 1) {
        InsertLast(No);
    }
    else {
        temp = First;

        newn = new nodeDL<T>;
        newn -> data = No;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteFirst
//  Description: Deletes the first element from the Doubly Linear Linked List.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteFirst() {
    struct nodeDL<T> * temp = First;

    if(First == NULL){      
        cout<<"LL is empty!"<<endl;
        return;
    }
    else if(First -> next == NULL){     
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteLast
//  Description: Deletes the last element from the Doubly Linear Linked List.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteLast() {
    struct nodeDL<T> * temp = First;

    if (First == NULL) {
        cout << "LL is empty\n";
        return;
    }
    else if (First->next == NULL) {
        delete First;
        First = NULL;
    }
    else {
        temp = First;  
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }                    
        delete(temp -> next);
        temp -> next = NULL;
    }
    iCnt--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteAtPos
//  Description: Deletes the element at the specified position in the Doubly Linear Linked List.
//  Input: int iPos - The position of the element to be deleted (1-based index).
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos) {

    struct nodeDL<T> * temp1;
    struct nodeDL<T> * temp2;

    if ((iPos < 1) || (iPos > iCnt)) {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) {
        DeleteFirst();
    }
    else if (iPos == iCnt) {
        DeleteLast();
    }
    else {
        temp1 = First;

        for(int i = 1; i < iPos-1; i++){
            temp1 = temp1 -> next;
        }    

        temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        temp2 -> next -> prev = temp1;

        delete(temp2);

        iCnt--;
    }
}






/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeDC {
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL {
private:
    struct nodeDC<T> * First;
    struct nodeDC<T> * Last;
    int iCnt;

public:
    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DoublyCL
//  Description: Constructor for the DoublyCL class. Initializes the doubly circular linked list.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyCL<T>::DoublyCL() {
    First = NULL;
    Last = NULL;
    iCnt = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: Count
//  Description: Returns the number of elements in the Doubly Circular Linked List.
//  Input: None
//  Output: int - The count of nodes in the list.
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::Count() {
    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: Display
//  Description: Displays the elements of the Doubly Circular Linked List from start to end.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::Display() {
    struct nodeDC<T> * temp = First;

    if ((First == NULL) && (Last == NULL)) {
        return;
    }

    do {
        cout << "| " << temp->data << " |<=> ";
        temp = temp->next;
    } while (temp != Last->next);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertFirst
//  Description: Inserts a new element at the beginning of the Doubly Circular Linked List.
//  Input: T no - The data to be inserted.
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertFirst(T No) {
    struct nodeDC<T> * newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL)) { // LL is empty
        First = Last = newn;
        First->next = Last->next = First;
        First->prev = Last->prev = Last;
    }
    else { // LL contains one or more nodes
        newn->next = First;
        First->prev = newn;
        First = newn;

        First->prev = Last;
        Last->next = First;
    }
    iCnt++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertLast
//  Description: Inserts a new element at the end of the Doubly Circular Linked List.
//  Input: T no - The data to be inserted.
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertLast(T No) {
    struct nodeDC<T> * newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL)) { // LL is empty
        First = Last = newn;
        First->next = Last->next = First;
        First->prev = Last->prev = Last;
    }
    else { // LL contains one or more nodes
        Last->next = newn;
        newn->prev = Last;
        Last = newn;

        Last->next = First;
        First->prev = Last;
    }
    iCnt++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: InsertAtPos
//  Description: Inserts a new element at the specified position in the Doubly Circular Linked List.
//  Input: T no - The data to be inserted.
//         int iPos - The position at which the element should be inserted (1-based index).
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos) {
    if ((iPos < 1) || (iPos > iCnt + 1)) {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) {
        InsertFirst(No);
    }
    else if (iPos == iCnt + 1) {
        InsertLast(No);
    }
    else {
        struct nodeDC<T> * temp = First;
        struct nodeDC<T> * newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < iPos - 1; i++) {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCnt++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteFirst
//  Description: Deletes the first element from the Doubly Circular Linked List.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteFirst() {
    if ((First == NULL) && (Last == NULL)) { // LL is empty
        return;
    }
    else if (First == Last) { // LL contains 1 node
        delete First;
        First = Last = NULL;
    }
    else { // LL contains more than 1 node
        First = First->next;
        delete Last->next; // delete First->prev;

        First->prev = Last;
        Last->next = First;
    }
    iCnt--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteLast
//  Description: Deletes the last element from the Doubly Circular Linked List.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteLast() {
    if ((First == NULL) && (Last == NULL)) { // LL is empty
        return;
    }
    else if (First == Last) { // LL contains 1 node
        delete First;
        First = Last = NULL;
    }
    else { // LL contains more than 1 node
        Last = Last->prev;
        delete First->prev; // delete Last->next

        First->prev = Last;
        Last->next = First;
    }
    iCnt--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: DeleteAtPos
//  Description: Deletes the element at the specified position in the Doubly Circular Linked List.
//  Input: int iPos - The position of the element to be deleted (1-based index).
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 05/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos) {
    if ((iPos < 1) || (iPos > iCnt)) {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1) {
        DeleteFirst();
    }
    else if (iPos == iCnt) {
        DeleteLast();
    }
    else {
        struct nodeDC<T> * temp = First;

        for (int i = 1; i < iPos - 1; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCnt--;
    }
}




/////////////////////////////////////////////////////////////
//
// Code of Stack Operations
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeST{
    T data;
    struct nodeST<T> *next;
};


template <class T>
class Stack{
    
    private:
        struct nodeST<T> * First;
        int iCnt;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T no);      // Same as InsertFirst()
        int Pop();            // Same as DeleteFirst()

};


/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Stack
//  Description: This constructor initializes the stack by setting the 'First' pointer 
//               to NULL and the counter 'iCnt' to 0, indicating an empty stack.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Stack<T>::Stack() {
    First = NULL;
    iCnt = 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Display
//  Description: This function traverses through the stack and displays each element.
//  Input: None
//  Output: Displays all elements in the stack
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Display() {
    struct nodeST<T> *temp = First;

    cout << "Elements of Stack are: " << endl;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Count
//  Description: This function returns the number of elements currently in the stack.
//  Input: None
//  Output: Returns the integer count of elements in the stack
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T>::Count() {
    return iCnt;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Push
//  Description: This function inserts a new element onto the stack. It creates a new 
//               node and places it at the top of the stack (First).
//  Input: T no - The element to be pushed onto the stack
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Push(T no) {
    struct nodeST<T> *newn = new nodeST<T>;

    newn->data = no;
    newn->next = NULL;

    if (First == NULL) {
        First = newn;
    } 
    
    else {
        newn->next = First;
        First = newn;
    }

    iCnt++;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Pop
//  Description: This function removes the top element from the stack and returns its 
//               value. It deletes the node at the top (First) and adjusts the pointer.
//  Input: None
//  Output: Returns the value of the popped element, or -1 if the stack is empty
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T>::Pop() {
    struct nodeST<T> *temp = NULL;
    int iValue = 0;

    if (First == NULL) {
        cout << "Unable to pop element as Stack is empty!" << endl;
        return -1;

    } 
    else {

        temp = First;
        iValue = First->data;
        First = First->next;
        delete temp;

        iCnt--;
    }

    return iValue;
}






/////////////////////////////////////////////////////////////
//
// Code of Queue Operations
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeQ{
    T data;
    struct nodeQ<T> *next;
};


template <class T>
class Queue{
    
    private:
        struct nodeQ<T> * First;
        int iCnt;

    public:
        Queue();
        void Display();
        int Count();
        void Enqueue(T no);      // Same as InsertLast()
        int Dequeue();            // Same as DeleteFirst()

};


/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Queue
//  Description: This constructor initializes the Queue by setting the 'First' pointer 
//               to NULL and the counter 'iCnt' to 0, indicating an empty Queue.
//  Input: None
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Queue<T>::Queue() {
    First = NULL;
    iCnt = 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Display
//  Description: This function traverses through the Queue and displays each element.
//  Input: None
//  Output: Displays all elements in the Queue
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Display() {
    struct nodeQ<T> *temp = First;

    cout << "Elements of Queue are: " << endl;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Count
//  Description: This function returns the number of elements currently in the Queue.
//  Input: None
//  Output: Returns the integer count of elements in the Queue
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T>::Count() {
    return iCnt;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Enqueue
//  Description: This function inserts a new element at the end of the queue. It creates 
//               a new node with the given data and places it at the rear of the queue.
//  Input: T no - The element to be added to the queue
//  Output: None
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void Queue<T>::Enqueue(T no) {
    struct nodeQ<T> *newn = new nodeQ<T>;
    struct nodeQ<T> *temp = First;

    newn->data = no;
    newn->next = NULL;

    if (First == NULL) {
        First = newn;
    } 
    
    else {
        temp = First;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newn;
    }

    iCnt++;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
//  Function Name: Dequeue
//  Description: This function removes the front element from the queue and returns its 
//               value. It deletes the node at the front (First) and adjusts the pointer 
//               to the next node.
//  Input: None
//  Output: Returns the value of the dequeued element, or -1 if the queue is empty
//  Author: Atharva Vilas Bhoite
//  Date: 06/07/2024
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T>::Dequeue() {
    struct nodeQ<T> *temp = NULL;
    int iValue = 0;

    if (First == NULL) {
        cout << "Unable to pop element as Queue is empty!" << endl;
        return -1;

    } 
    else {

        temp = First;
        iValue = First->data;
        First = First->next;
        delete temp;

        iCnt--;
    }

    return iValue;
}









/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name: main
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


int main(){

    // ---------------------------------------------------Singly Linear LL-------------------------------------------------------------
    //---------------------------------------------------Linked List of Integer------------------------------------------------

    SinglyLL<int> *iObj = new SinglyLL<int>();
    int iRet = 0;

    cout << "------------------------------------------- Singly Linear Linked List -----------------------------------------------\n" << endl;
    cout << "--------------------------------------------- Linked List of Integer -----------------------------------------------\n" << endl;
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


    // --------------------------------------------------Linked List of Character---------------------------------------------------
    cout << "------------------------------------------- Linked List of Character -----------------------------------------------\n" << endl;
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
    


    //---------------------------------------------------Linked List of float----------------------------------------------------
    SinglyLL<float> *fObj = new SinglyLL<float>();

    cout << "------------------------------------------- Linked List of Float -----------------------------------------------\n" << endl;

    fObj->InsertFirst(51.54f);
    fObj->InsertFirst(21.87f);
    fObj->InsertFirst(11.28f);

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

    

    //----------------------------------------------------Linked List of Double----------------------------------------------------
    SinglyLL<double> *dObj = new SinglyLL<double>();

    cout << "------------------------------------------- Linked List of Double -----------------------------------------------\n" << endl;

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





    // ---------------------------------------------------Singly Circular LL-------------------------------------------------------------
    //---------------------------------------------------Linked List of Integer------------------------------------------------

    SinglyCL<int> *i2Obj = new SinglyCL<int>();

    cout << "------------------------------------------- Singly Circular Linked List -----------------------------------------------\n" << endl;
    cout << "--------------------------------------------- Linked List of Integer -----------------------------------------------\n" << endl;
    i2Obj->InsertFirst(51);
    i2Obj->InsertFirst(21);
    i2Obj->InsertFirst(11);

    i2Obj->Display();

    iRet = i2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i2Obj->InsertLast(101);
    i2Obj->InsertLast(201);
    i2Obj->InsertLast(301);

    i2Obj->Display();
    iRet = i2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i2Obj->InsertAtPos(71, 4);
    i2Obj->Display();
    iRet = i2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i2Obj->DeleteFirst();
    i2Obj->Display();
    iRet = i2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i2Obj->DeleteLast();
    i2Obj->Display();
    iRet = i2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i2Obj->DeleteAtPos(4);
    i2Obj->Display();
    iRet = i2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;


    // --------------------------------------------------Linked List of Character---------------------------------------------------
    cout << "------------------------------------------- Linked List of Character -----------------------------------------------\n" << endl;
    SinglyCL<char> *c2Obj = new SinglyCL<char>();

    c2Obj->InsertFirst('C');
    c2Obj->InsertFirst('B');
    c2Obj->InsertFirst('A');

    c2Obj->Display();
    iRet = c2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c2Obj->InsertLast('d');
    c2Obj->InsertLast('e');
    c2Obj->InsertLast('f');

    c2Obj->Display();
    iRet = c2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c2Obj->InsertAtPos('z', 4);
    c2Obj->Display();
    iRet = c2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c2Obj->DeleteFirst();
    c2Obj->Display();
    iRet = c2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c2Obj->DeleteLast();
    c2Obj->Display();
    iRet = c2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c2Obj->DeleteAtPos(4);
    c2Obj->Display();
    iRet = c2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;
    


    //---------------------------------------------------Linked List of float----------------------------------------------------
    SinglyCL<float> *f2Obj = new SinglyCL<float>();

    cout << "------------------------------------------- Linked List of Float -----------------------------------------------\n" << endl;

    f2Obj->InsertFirst(51.54f);
    f2Obj->InsertFirst(21.87f);
    f2Obj->InsertFirst(11.28f);

    f2Obj->Display();

    iRet = f2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f2Obj->InsertLast(101.51f);
    f2Obj->InsertLast(201.56f);
    f2Obj->InsertLast(301.53f);

    f2Obj->Display();
    iRet = f2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f2Obj->InsertAtPos(45.54f, 4);
    f2Obj->Display();
    iRet = f2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f2Obj->DeleteFirst();
    f2Obj->Display();
    iRet = f2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f2Obj->DeleteLast();
    f2Obj->Display();
    iRet = f2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f2Obj->DeleteAtPos(4);
    f2Obj->Display();
    iRet = f2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    

    //----------------------------------------------------Linked List of Double----------------------------------------------------
    SinglyCL<double> *d2Obj = new SinglyCL<double>();

    cout << "------------------------------------------- Linked List of Double -----------------------------------------------\n" << endl;

    d2Obj->InsertFirst(51.85551);
    d2Obj->InsertFirst(2651.065165);
    d2Obj->InsertFirst(65.6516);

    d2Obj->Display();

    iRet = d2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d2Obj->InsertLast(894.6515);
    d2Obj->InsertLast(32156.651);
    d2Obj->InsertLast(8962.51);

    d2Obj->Display();
    iRet = d2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d2Obj->InsertAtPos(984.651, 4);
    d2Obj->Display();
    iRet = d2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d2Obj->DeleteFirst();
    d2Obj->Display();
    iRet = d2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d2Obj->DeleteLast();
    d2Obj->Display();
    iRet = d2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d2Obj->DeleteAtPos(4);
    d2Obj->Display();
    iRet = d2Obj->Count();
    cout << "Number of elements are: " << iRet << endl;





    // --------------------------------------------------- Doubly Linear LL -------------------------------------------------------------
    //---------------------------------------------------Linked List of Integer--------------------------------------------------

    DoublyLL<int> *i3Obj = new DoublyLL<int>();

    cout << "------------------------------------------- Doubly Linear Linked List -----------------------------------------------\n" << endl;
    cout << "--------------------------------------------- Linked List of Integer -----------------------------------------------\n" << endl;
    i3Obj->InsertFirst(51);
    i3Obj->InsertFirst(21);
    i3Obj->InsertFirst(11);

    i3Obj->Display();

    iRet = i3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i3Obj->InsertLast(101);
    i3Obj->InsertLast(201);
    i3Obj->InsertLast(301);

    i3Obj->Display();
    iRet = i3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i3Obj->InsertAtPos(71, 4);
    i3Obj->Display();
    iRet = i3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i3Obj->DeleteFirst();
    i3Obj->Display();
    iRet = i3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i3Obj->DeleteLast();
    i3Obj->Display();
    iRet = i3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i3Obj->DeleteAtPos(4);
    i3Obj->Display();
    iRet = i3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;


    // --------------------------------------------------Linked List of Character---------------------------------------------------
    cout << "------------------------------------------- Linked List of Character -----------------------------------------------\n" << endl;
    DoublyLL<char> *c3Obj = new DoublyLL<char>();

    c3Obj->InsertFirst('C');
    c3Obj->InsertFirst('B');
    c3Obj->InsertFirst('A');

    c3Obj->Display();
    iRet = c3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c3Obj->InsertLast('d');
    c3Obj->InsertLast('e');
    c3Obj->InsertLast('f');

    c3Obj->Display();
    iRet = c3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c3Obj->InsertAtPos('z', 4);
    c3Obj->Display();
    iRet = c3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c3Obj->DeleteFirst();
    c3Obj->Display();
    iRet = c3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c3Obj->DeleteLast();
    c3Obj->Display();
    iRet = c3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c3Obj->DeleteAtPos(4);
    c3Obj->Display();
    iRet = c3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;
    


    //---------------------------------------------------Linked List of float----------------------------------------------------
    DoublyLL<float> *f3Obj = new DoublyLL<float>();

    cout << "------------------------------------------- Linked List of Float -----------------------------------------------\n" << endl;

    f3Obj->InsertFirst(51.54f);
    f3Obj->InsertFirst(21.87f);
    f3Obj->InsertFirst(11.28f);

    f3Obj->Display();

    iRet = f3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f3Obj->InsertLast(101.51f);
    f3Obj->InsertLast(201.56f);
    f3Obj->InsertLast(301.53f);

    f3Obj->Display();
    iRet = f3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f3Obj->InsertAtPos(45.54f, 4);
    f3Obj->Display();
    iRet = f3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f3Obj->DeleteFirst();
    f3Obj->Display();
    iRet = f3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f3Obj->DeleteLast();
    f3Obj->Display();
    iRet = f3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f3Obj->DeleteAtPos(4);
    f3Obj->Display();
    iRet = f3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    

    //----------------------------------------------------Linked List of Double----------------------------------------------------
    DoublyLL<double> *d3Obj = new DoublyLL<double>();

    cout << "------------------------------------------- Linked List of Double -----------------------------------------------\n" << endl;

    d3Obj->InsertFirst(51.85551);
    d3Obj->InsertFirst(2651.065165);
    d3Obj->InsertFirst(65.6516);

    d3Obj->Display();

    iRet = d3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d3Obj->InsertLast(894.6515);
    d3Obj->InsertLast(32156.651);
    d3Obj->InsertLast(8962.51);

    d3Obj->Display();
    iRet = d3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d3Obj->InsertAtPos(984.651, 4);
    d3Obj->Display();
    iRet = d3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d3Obj->DeleteFirst();
    d3Obj->Display();
    iRet = d3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d3Obj->DeleteLast();
    d3Obj->Display();
    iRet = d3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d3Obj->DeleteAtPos(4);
    d3Obj->Display();
    iRet = d3Obj->Count();
    cout << "Number of elements are: " << iRet << endl;






    // ----------------------------------------------Doubly Circular LL----------------------------------------------------------
    //---------------------------------------------Linked List of Integer------------------------------------------------------
    cout<<"\n\n";
    DoublyCL<int> *i4Obj = new DoublyCL<int>();

    cout << "-------------------------------------------- Doubly Circular LL --------------------------------------------------\n" << endl;
    cout << "------------------------------------------- Linked List of Integer -----------------------------------------------\n" << endl;
    i4Obj->InsertFirst(51);
    i4Obj->InsertFirst(21);
    i4Obj->InsertFirst(11);

    i4Obj->Display();

    iRet = i4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i4Obj->InsertLast(101);
    i4Obj->InsertLast(201);
    i4Obj->InsertLast(301);

    i4Obj->Display();
    iRet = i4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i4Obj->InsertAtPos(71, 4);
    i4Obj->Display();
    iRet = i4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i4Obj->DeleteFirst();
    i4Obj->Display();
    iRet = i4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i4Obj->DeleteLast();
    i4Obj->Display();
    iRet = i4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    i4Obj->DeleteAtPos(4);
    i4Obj->Display();
    iRet = i4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;


    // --------------------------------------------------Linked List of Character-------------------------------------------------
    cout << "------------------------------------------- Linked List of Character -----------------------------------------------\n" << endl;
    DoublyCL<char> *c4Obj = new DoublyCL<char>();

    c4Obj->InsertFirst('C');
    c4Obj->InsertFirst('B');
    c4Obj->InsertFirst('A');

    c4Obj->Display();
    iRet = c4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c4Obj->InsertLast('d');
    c4Obj->InsertLast('e');
    c4Obj->InsertLast('f');

    c4Obj->Display();
    iRet = c4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c4Obj->InsertAtPos('z', 4);
    c4Obj->Display();
    iRet = c4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c4Obj->DeleteFirst();
    c4Obj->Display();
    iRet = c4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c4Obj->DeleteLast();
    c4Obj->Display();
    iRet = c4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    c4Obj->DeleteAtPos(4);
    c4Obj->Display();
    iRet = c4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;


    //---------------------------------------------------Linked List of float---------------------------------------------------------------
    DoublyCL<float> *f4Obj = new DoublyCL<float>();

    cout << "------------------------------------------- Linked List of Float -----------------------------------------------\n" << endl;
    f4Obj->InsertFirst(51.54f);
    f4Obj->InsertFirst(21.54f);
    f4Obj->InsertFirst(11.54f);

    f4Obj->Display();

    iRet = f4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f4Obj->InsertLast(101.51f);
    f4Obj->InsertLast(201.56f);
    f4Obj->InsertLast(301.53f);

    f4Obj->Display();
    iRet = f4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f4Obj->InsertAtPos(45.54f, 4);
    f4Obj->Display();
    iRet = f4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f4Obj->DeleteFirst();
    f4Obj->Display();
    iRet = f4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f4Obj->DeleteLast();
    f4Obj->Display();
    iRet = f4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    f4Obj->DeleteAtPos(4);
    f4Obj->Display();
    iRet = f4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    

    //---------------------------------------------------Linked List of Double---------------------------------------------------------
    DoublyCL<double> *d4Obj = new DoublyCL<double>();

    cout << "------------------------------------------- Linked List of Double -----------------------------------------------\n" << endl;
    d4Obj->InsertFirst(51.85551);
    d4Obj->InsertFirst(2651.065165);
    d4Obj->InsertFirst(65.6516);

    d4Obj->Display();

    iRet = d4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d4Obj->InsertLast(894.6515);
    d4Obj->InsertLast(32156.651);
    d4Obj->InsertLast(8962.51);

    d4Obj->Display();
    iRet = d4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d4Obj->InsertAtPos(984.651, 4);
    d4Obj->Display();
    iRet = d4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d4Obj->DeleteFirst();
    d4Obj->Display();
    iRet = d4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d4Obj->DeleteLast();
    d4Obj->Display();
    iRet = d4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    d4Obj->DeleteAtPos(4);
    d4Obj->Display();
    iRet = d4Obj->Count();
    cout << "Number of elements are: " << iRet << endl;




    cout << "--------------------------------------------- Stack Operations --------------------------------------------------\n" << endl;
    cout << "--------------------------------------------- Stack of Integer --------------------------------------------------\n" << endl;

    Stack<int> *i5Obj = new Stack<int>();

    cout<<"After performing PUSH operations:- "<<endl;
    i5Obj->Push(10);
    i5Obj->Push(20);
    i5Obj->Push(30);
    i5Obj->Push(40);
    i5Obj->Push(50);
    i5Obj->Push(60);
    i5Obj->Push(70);

    i5Obj->Display();

    iRet = i5Obj->Count();

    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing POP operation:- "<<endl;
    iRet = i5Obj->Pop();
    cout<<"Poped element is: "<<iRet<<endl;
    i5Obj->Display();
    iRet = i5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing POP operation:- "<<endl;
    iRet = i5Obj->Pop();
    cout<<"Poped element is: "<<iRet<<endl;
    i5Obj->Display();
    iRet = i5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing PUSH operation:- "<<endl;
    i5Obj->Push(100);
    i5Obj->Display();
    iRet = i5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;



    cout << "--------------------------------------------- Stack of Characters ----------------------------------------------------\n" << endl;

    Stack<char> *c5Obj = new Stack<char>();

    cout<<"After performing PUSH operations:- "<<endl;
    c5Obj->Push('G');
    c5Obj->Push('f');
    c5Obj->Push('e');
    c5Obj->Push('d');
    c5Obj->Push('C');
    c5Obj->Push('B');
    c5Obj->Push('A');

    c5Obj->Display();

    iRet = c5Obj->Count();

    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing POP operation:- "<<endl;
    iRet = c5Obj->Pop();
    cout<<"Poped element is: "<<iRet<<endl;
    c5Obj->Display();
    iRet = c5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing POP operation:- "<<endl;
    iRet = c5Obj->Pop();
    cout<<"Poped element is: "<<iRet<<endl;
    c5Obj->Display();
    iRet = c5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing PUSH operation:- "<<endl;
    c5Obj->Push('Z');
    c5Obj->Display();
    iRet = c5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;



    cout << "--------------------------------------------- Stack of Float ----------------------------------------------------\n" << endl;

    Stack<float> *f5Obj = new Stack<float>();

    cout<<"After performing PUSH operations:- "<<endl;
    f5Obj->Push(10.54);
    f5Obj->Push(24.14);
    f5Obj->Push(48.52);
    f5Obj->Push(984.25);
    f5Obj->Push(98.515);
    f5Obj->Push(102.51);
    f5Obj->Push(70.548);

    f5Obj->Display();

    iRet = f5Obj->Count();

    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing POP operation:- "<<endl;
    iRet = f5Obj->Pop();
    cout<<"Poped element is: "<<iRet<<endl;
    f5Obj->Display();
    iRet = f5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing POP operation:- "<<endl;
    iRet = f5Obj->Pop();
    cout<<"Poped element is: "<<iRet<<endl;
    f5Obj->Display();
    iRet = f5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing PUSH operation:- "<<endl;
    f5Obj->Push(1008.626);
    f5Obj->Display();
    iRet = f5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;



    cout << "--------------------------------------------- Stack of Double ---------------------------------------------------\n" << endl;

    Stack<double> *d5Obj = new Stack<double>();

    cout<<"After performing PUSH operations:- "<<endl;
    d5Obj->Push(1084.5624);
    d5Obj->Push(24.146515);
    d5Obj->Push(48651.52);
    d5Obj->Push(984.2625);
    d5Obj->Push(789.515);
    d5Obj->Push(102.51);
    d5Obj->Push(1650.548651);

    d5Obj->Display();

    iRet = d5Obj->Count();

    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing POP operation:- "<<endl;
    iRet = d5Obj->Pop();
    cout<<"Poped element is: "<<iRet<<endl;
    d5Obj->Display();
    iRet = d5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing POP operation:- "<<endl;
    iRet = d5Obj->Pop();
    cout<<"Poped element is: "<<iRet<<endl;
    d5Obj->Display();
    iRet = d5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing PUSH operation:- "<<endl;
    d5Obj->Push(10798.66526);
    d5Obj->Display();
    iRet = d5Obj->Count();
    cout<<"Number of elements in the stack are: "<<iRet<<endl;
    cout<<endl;




    cout << "--------------------------------------------- Queue Operations --------------------------------------------------\n" << endl;
    cout << "--------------------------------------------- Queue of Integer --------------------------------------------------\n" << endl;

    Queue<int> *i6Obj = new Queue<int>();

    cout<<"After performing ENQUEUE operations:- "<<endl;
    i6Obj->Enqueue(10);
    i6Obj->Enqueue(20);
    i6Obj->Enqueue(30);
    i6Obj->Enqueue(40);
    i6Obj->Enqueue(50);
    i6Obj->Enqueue(60);
    i6Obj->Enqueue(70);

    i6Obj->Display();

    iRet = i6Obj->Count();

    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing DEQUEUE operation:- "<<endl;
    iRet = i6Obj->Dequeue();
    cout<<"Removed element is: "<<iRet<<endl;
    i6Obj->Display();
    iRet = i6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing DEQUEUE operation:- "<<endl;
    iRet = i6Obj->Dequeue();
    cout<<"Removed element is: "<<iRet<<endl;
    i6Obj->Display();
    iRet = i6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing Enqueue operation:- "<<endl;
    i6Obj->Enqueue(100);
    i6Obj->Display();
    iRet = i6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;



    cout << "--------------------------------------------- Queue of Characters ----------------------------------------------------\n" << endl;

    Queue<char> *c6Obj = new Queue<char>();

    cout<<"After performing Enqueue operations:- "<<endl;
    c6Obj->Enqueue('G');
    c6Obj->Enqueue('f');
    c6Obj->Enqueue('e');
    c6Obj->Enqueue('d');
    c6Obj->Enqueue('C');
    c6Obj->Enqueue('B');
    c6Obj->Enqueue('A');

    c6Obj->Display();

    iRet = c6Obj->Count();

    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing DEQUEUE operation:- "<<endl;
    iRet = c6Obj->Dequeue();
    cout<<"Removed element is: "<<iRet<<endl;
    c6Obj->Display();
    iRet = c6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing DEQUEUE operation:- "<<endl;
    iRet = c6Obj->Dequeue();
    cout<<"Removed element is: "<<iRet<<endl;
    c6Obj->Display();
    iRet = c6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing Enqueue operation:- "<<endl;
    c6Obj->Enqueue('Z');
    c6Obj->Display();
    iRet = c6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;



    cout << "--------------------------------------------- Queue of Float ----------------------------------------------------\n" << endl;

    Queue<float> *f6Obj = new Queue<float>();

    cout<<"After performing Enqueue operations:- "<<endl;
    f6Obj->Enqueue(10.54);
    f6Obj->Enqueue(24.14);
    f6Obj->Enqueue(48.52);
    f6Obj->Enqueue(984.25);
    f6Obj->Enqueue(98.515);
    f6Obj->Enqueue(102.51);
    f6Obj->Enqueue(70.548);

    f6Obj->Display();

    iRet = f6Obj->Count();

    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing DEQUEUE operation:- "<<endl;
    iRet = f6Obj->Dequeue();
    cout<<"Removed element is: "<<iRet<<endl;
    f6Obj->Display();
    iRet = f6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing DEQUEUE operation:- "<<endl;
    iRet = f6Obj->Dequeue();
    cout<<"Removed element is: "<<iRet<<endl;
    f6Obj->Display();
    iRet = f6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing Enqueue operation:- "<<endl;
    f6Obj->Enqueue(1008.626);
    f6Obj->Display();
    iRet = f6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;



    cout << "--------------------------------------------- Queue of Double ---------------------------------------------------\n" << endl;

    Queue<double> *d6Obj = new Queue<double>();

    cout<<"After performing Enqueue operations:- "<<endl;
    d6Obj->Enqueue(1084.5624);
    d6Obj->Enqueue(24.146515);
    d6Obj->Enqueue(48651.52);
    d6Obj->Enqueue(984.2625);
    d6Obj->Enqueue(789.515);
    d6Obj->Enqueue(102.51);
    d6Obj->Enqueue(1650.548651);

    d6Obj->Display();

    iRet = d6Obj->Count();

    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing DEQUEUE operation:- "<<endl;
    iRet = d6Obj->Dequeue();
    cout<<"Removed element is: "<<iRet<<endl;
    d6Obj->Display();
    iRet = d6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing DEQUEUE operation:- "<<endl;
    iRet = d6Obj->Dequeue();
    cout<<"Removed element is: "<<iRet<<endl;
    d6Obj->Display();
    iRet = d6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    // -------------------------------------------------------------------------------

    cout<<"After performing Enqueue operation:- "<<endl;
    d6Obj->Enqueue(10798.66526);
    d6Obj->Display();
    iRet = d6Obj->Count();
    cout<<"Number of elements in the Queue are: "<<iRet<<endl;
    cout<<endl;


    return 0;
}







///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Output
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

/*


------------------------------------------- Singly Linear Linked List -----------------------------------------------

--------------------------------------------- Linked List of Integer -----------------------------------------------

| 11 |-> | 21 |-> | 51 |-> NULL
Number of elements are: 3
| 11 |-> | 21 |-> | 51 |-> | 101 |-> | 201 |-> | 301 |-> NULL
Number of elements are: 6
| 11 |-> | 21 |-> | 51 |-> | 71 |-> | 101 |-> | 201 |-> | 301 |-> NULL
Number of elements are: 7
| 21 |-> | 51 |-> | 71 |-> | 101 |-> | 201 |-> | 301 |-> NULL
Number of elements are: 6
| 21 |-> | 51 |-> | 71 |-> | 101 |-> | 201 |-> NULL
Number of elements are: 5
| 21 |-> | 51 |-> | 71 |-> | 201 |-> NULL
Number of elements are: 4
------------------------------------------- Linked List of Character -----------------------------------------------

| A |-> | B |-> | C |-> NULL
Number of elements are: 3
| A |-> | B |-> | C |-> | d |-> | e |-> | f |-> NULL
Number of elements are: 6
| A |-> | B |-> | C |-> | z |-> | d |-> | e |-> | f |-> NULL
Number of elements are: 7
| B |-> | C |-> | z |-> | d |-> | e |-> | f |-> NULL
Number of elements are: 6
| B |-> | C |-> | z |-> | d |-> | e |-> NULL
Number of elements are: 5
| B |-> | C |-> | z |-> | e |-> NULL
Number of elements are: 4
------------------------------------------- Linked List of Float -----------------------------------------------

| 11.28 |-> | 21.87 |-> | 51.54 |-> NULL
Number of elements are: 3
| 11.28 |-> | 21.87 |-> | 51.54 |-> | 101.51 |-> | 201.56 |-> | 301.53 |-> NULL
Number of elements are: 6
| 11.28 |-> | 21.87 |-> | 51.54 |-> | 45.54 |-> | 101.51 |-> | 201.56 |-> | 301.53 |-> NULL
Number of elements are: 7
| 21.87 |-> | 51.54 |-> | 45.54 |-> | 101.51 |-> | 201.56 |-> | 301.53 |-> NULL
Number of elements are: 6
| 21.87 |-> | 51.54 |-> | 45.54 |-> | 101.51 |-> | 201.56 |-> NULL
Number of elements are: 5
| 21.87 |-> | 51.54 |-> | 45.54 |-> | 201.56 |-> NULL
Number of elements are: 4
------------------------------------------- Linked List of Double -----------------------------------------------

| 65.6516 |-> | 2651.07 |-> | 51.8555 |-> NULL
Number of elements are: 3
| 65.6516 |-> | 2651.07 |-> | 51.8555 |-> | 894.652 |-> | 32156.7 |-> | 8962.51 |-> NULL
Number of elements are: 6
| 65.6516 |-> | 2651.07 |-> | 51.8555 |-> | 984.651 |-> | 894.652 |-> | 32156.7 |-> | 8962.51 |-> NULL
Number of elements are: 7
| 2651.07 |-> | 51.8555 |-> | 984.651 |-> | 894.652 |-> | 32156.7 |-> | 8962.51 |-> NULL
Number of elements are: 6
| 2651.07 |-> | 51.8555 |-> | 984.651 |-> | 894.652 |-> | 32156.7 |-> NULL
Number of elements are: 5
| 2651.07 |-> | 51.8555 |-> | 984.651 |-> | 32156.7 |-> NULL
Number of elements are: 4
------------------------------------------- Singly Circular Linked List -----------------------------------------------

--------------------------------------------- Linked List of Integer -----------------------------------------------

| 11 | -> | 21 | -> | 51 | -> (back to first node)
Number of elements are: 3
| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 201 | -> | 301 | -> (back to first node)
Number of elements are: 6
| 11 | -> | 21 | -> | 51 | -> | 71 | -> | 101 | -> | 201 | -> | 301 | -> (back to first node)
Number of elements are: 7
| 21 | -> | 51 | -> | 71 | -> | 101 | -> | 201 | -> | 301 | -> (back to first node)
Number of elements are: 6
| 21 | -> | 51 | -> | 71 | -> | 101 | -> | 201 | -> (back to first node)
Number of elements are: 5
| 21 | -> | 51 | -> | 71 | -> | 201 | -> (back to first node)
Number of elements are: 4
------------------------------------------- Linked List of Character -----------------------------------------------

| A | -> | B | -> | C | -> (back to first node)
Number of elements are: 3
| A | -> | B | -> | C | -> | d | -> | e | -> | f | -> (back to first node)
Number of elements are: 6
| A | -> | B | -> | C | -> | z | -> | d | -> | e | -> | f | -> (back to first node)
Number of elements are: 7
| B | -> | C | -> | z | -> | d | -> | e | -> | f | -> (back to first node)
Number of elements are: 6
| B | -> | C | -> | z | -> | d | -> | e | -> (back to first node)
Number of elements are: 5
| B | -> | C | -> | z | -> | e | -> (back to first node)
Number of elements are: 4
------------------------------------------- Linked List of Float -----------------------------------------------

| 11.28 | -> | 21.87 | -> | 51.54 | -> (back to first node)
Number of elements are: 3
| 11.28 | -> | 21.87 | -> | 51.54 | -> | 101.51 | -> | 201.56 | -> | 301.53 | -> (back to first node)
Number of elements are: 6
| 11.28 | -> | 21.87 | -> | 51.54 | -> | 45.54 | -> | 101.51 | -> | 201.56 | -> | 301.53 | -> (back to first node)
Number of elements are: 7
| 21.87 | -> | 51.54 | -> | 45.54 | -> | 101.51 | -> | 201.56 | -> | 301.53 | -> (back to first node)
Number of elements are: 6
| 21.87 | -> | 51.54 | -> | 45.54 | -> | 101.51 | -> | 201.56 | -> (back to first node)
Number of elements are: 5
| 21.87 | -> | 51.54 | -> | 45.54 | -> | 201.56 | -> (back to first node)
Number of elements are: 4
------------------------------------------- Linked List of Double -----------------------------------------------

| 65.6516 | -> | 2651.07 | -> | 51.8555 | -> (back to first node)
Number of elements are: 3
| 65.6516 | -> | 2651.07 | -> | 51.8555 | -> | 894.652 | -> | 32156.7 | -> | 8962.51 | -> (back to first node)
Number of elements are: 6
| 65.6516 | -> | 2651.07 | -> | 51.8555 | -> | 984.651 | -> | 894.652 | -> | 32156.7 | -> | 8962.51 | -> (back to first node)
Number of elements are: 7
| 2651.07 | -> | 51.8555 | -> | 984.651 | -> | 894.652 | -> | 32156.7 | -> | 8962.51 | -> (back to first node)
Number of elements are: 6
| 2651.07 | -> | 51.8555 | -> | 984.651 | -> | 894.652 | -> | 32156.7 | -> (back to first node)
Number of elements are: 5
| 2651.07 | -> | 51.8555 | -> | 984.651 | -> | 32156.7 | -> (back to first node)
Number of elements are: 4
------------------------------------------- Doubly Linear Linked List -----------------------------------------------

--------------------------------------------- Linked List of Integer -----------------------------------------------

NULL <->| 11 |-> | 21 |-> | 51 |-> NULL
Number of elements are: 3
NULL <->| 11 |-> | 21 |-> | 51 |-> | 101 |-> | 201 |-> | 301 |-> NULL
Number of elements are: 6
NULL <->| 11 |-> | 21 |-> | 51 |-> | 71 |-> | 101 |-> | 201 |-> | 301 |-> NULL
Number of elements are: 7
NULL <->| 21 |-> | 51 |-> | 71 |-> | 101 |-> | 201 |-> | 301 |-> NULL
Number of elements are: 6
NULL <->| 21 |-> | 51 |-> | 71 |-> | 101 |-> | 201 |-> NULL
Number of elements are: 5
NULL <->| 21 |-> | 51 |-> | 71 |-> | 201 |-> NULL
Number of elements are: 4
------------------------------------------- Linked List of Character -----------------------------------------------

NULL <->| A |-> | B |-> | C |-> NULL
Number of elements are: 3
NULL <->| A |-> | B |-> | C |-> | d |-> | e |-> | f |-> NULL
Number of elements are: 6
NULL <->| A |-> | B |-> | C |-> | z |-> | d |-> | e |-> | f |-> NULL
Number of elements are: 7
NULL <->| B |-> | C |-> | z |-> | d |-> | e |-> | f |-> NULL
Number of elements are: 6
NULL <->| B |-> | C |-> | z |-> | d |-> | e |-> NULL
Number of elements are: 5
NULL <->| B |-> | C |-> | z |-> | e |-> NULL
Number of elements are: 4
------------------------------------------- Linked List of Float -----------------------------------------------

NULL <->| 11.28 |-> | 21.87 |-> | 51.54 |-> NULL
Number of elements are: 3
NULL <->| 11.28 |-> | 21.87 |-> | 51.54 |-> | 101.51 |-> | 201.56 |-> | 301.53 |-> NULL
Number of elements are: 6
NULL <->| 11.28 |-> | 21.87 |-> | 51.54 |-> | 45.54 |-> | 101.51 |-> | 201.56 |-> | 301.53 |-> NULL
Number of elements are: 7
NULL <->| 21.87 |-> | 51.54 |-> | 45.54 |-> | 101.51 |-> | 201.56 |-> | 301.53 |-> NULL
Number of elements are: 6
NULL <->| 21.87 |-> | 51.54 |-> | 45.54 |-> | 101.51 |-> | 201.56 |-> NULL
Number of elements are: 5
NULL <->| 21.87 |-> | 51.54 |-> | 45.54 |-> | 201.56 |-> NULL
Number of elements are: 4
------------------------------------------- Linked List of Double -----------------------------------------------

NULL <->| 65.6516 |-> | 2651.07 |-> | 51.8555 |-> NULL
Number of elements are: 3
NULL <->| 65.6516 |-> | 2651.07 |-> | 51.8555 |-> | 894.652 |-> | 32156.7 |-> | 8962.51 |-> NULL
Number of elements are: 6
NULL <->| 65.6516 |-> | 2651.07 |-> | 51.8555 |-> | 984.651 |-> | 894.652 |-> | 32156.7 |-> | 8962.51 |-> NULL
Number of elements are: 7
NULL <->| 2651.07 |-> | 51.8555 |-> | 984.651 |-> | 894.652 |-> | 32156.7 |-> | 8962.51 |-> NULL
Number of elements are: 6
NULL <->| 2651.07 |-> | 51.8555 |-> | 984.651 |-> | 894.652 |-> | 32156.7 |-> NULL
Number of elements are: 5
NULL <->| 2651.07 |-> | 51.8555 |-> | 984.651 |-> | 32156.7 |-> NULL
Number of elements are: 4


-------------------------------------------- Doubly Circular LL --------------------------------------------------

------------------------------------------- Linked List of Integer -----------------------------------------------

| 11 |<=> | 21 |<=> | 51 |<=> NULL
Number of elements are: 3
| 11 |<=> | 21 |<=> | 51 |<=> | 101 |<=> | 201 |<=> | 301 |<=> NULL
Number of elements are: 6
| 11 |<=> | 21 |<=> | 51 |<=> | 71 |<=> | 101 |<=> | 201 |<=> | 301 |<=> NULL
Number of elements are: 7
| 21 |<=> | 51 |<=> | 71 |<=> | 101 |<=> | 201 |<=> | 301 |<=> NULL
Number of elements are: 6
| 21 |<=> | 51 |<=> | 71 |<=> | 101 |<=> | 201 |<=> NULL
Number of elements are: 5
| 21 |<=> | 51 |<=> | 71 |<=> | 201 |<=> NULL
Number of elements are: 4
------------------------------------------- Linked List of Character -----------------------------------------------

| A |<=> | B |<=> | C |<=> NULL
Number of elements are: 3
| A |<=> | B |<=> | C |<=> | d |<=> | e |<=> | f |<=> NULL
Number of elements are: 6
| A |<=> | B |<=> | C |<=> | z |<=> | d |<=> | e |<=> | f |<=> NULL
Number of elements are: 7
| B |<=> | C |<=> | z |<=> | d |<=> | e |<=> | f |<=> NULL
Number of elements are: 6
| B |<=> | C |<=> | z |<=> | d |<=> | e |<=> NULL
Number of elements are: 5
| B |<=> | C |<=> | z |<=> | e |<=> NULL
Number of elements are: 4
------------------------------------------- Linked List of Float -----------------------------------------------

| 11.54 |<=> | 21.54 |<=> | 51.54 |<=> NULL
Number of elements are: 3
| 11.54 |<=> | 21.54 |<=> | 51.54 |<=> | 101.51 |<=> | 201.56 |<=> | 301.53 |<=> NULL
Number of elements are: 6
| 11.54 |<=> | 21.54 |<=> | 51.54 |<=> | 45.54 |<=> | 101.51 |<=> | 201.56 |<=> | 301.53 |<=> NULL
Number of elements are: 7
| 21.54 |<=> | 51.54 |<=> | 45.54 |<=> | 101.51 |<=> | 201.56 |<=> | 301.53 |<=> NULL
Number of elements are: 6
| 21.54 |<=> | 51.54 |<=> | 45.54 |<=> | 101.51 |<=> | 201.56 |<=> NULL
Number of elements are: 5
| 21.54 |<=> | 51.54 |<=> | 45.54 |<=> | 201.56 |<=> NULL
Number of elements are: 4
------------------------------------------- Linked List of Double -----------------------------------------------

| 65.6516 |<=> | 2651.07 |<=> | 51.8555 |<=> NULL
Number of elements are: 3
| 65.6516 |<=> | 2651.07 |<=> | 51.8555 |<=> | 894.652 |<=> | 32156.7 |<=> | 8962.51 |<=> NULL
Number of elements are: 6
| 65.6516 |<=> | 2651.07 |<=> | 51.8555 |<=> | 984.651 |<=> | 894.652 |<=> | 32156.7 |<=> | 8962.51 |<=> NULL
Number of elements are: 7
| 2651.07 |<=> | 51.8555 |<=> | 984.651 |<=> | 894.652 |<=> | 32156.7 |<=> | 8962.51 |<=> NULL
Number of elements are: 6
| 2651.07 |<=> | 51.8555 |<=> | 984.651 |<=> | 894.652 |<=> | 32156.7 |<=> NULL
Number of elements are: 5
| 2651.07 |<=> | 51.8555 |<=> | 984.651 |<=> | 32156.7 |<=> NULL
Number of elements are: 4
--------------------------------------------- Stack Operations --------------------------------------------------

--------------------------------------------- Stack of Integer --------------------------------------------------

After performing PUSH operations:- 
Elements of Stack are: 
70
60
50
40
30
20
10
Number of elements in the stack are: 7

After performing POP operation:- 
Poped element is: 70
Elements of Stack are: 
60
50
40
30
20
10
Number of elements in the stack are: 6

After performing POP operation:- 
Poped element is: 60
Elements of Stack are: 
50
40
30
20
10
Number of elements in the stack are: 5

After performing PUSH operation:- 
Elements of Stack are: 
100
50
40
30
20
10
Number of elements in the stack are: 6

--------------------------------------------- Stack of Characters ----------------------------------------------------

After performing PUSH operations:- 
Elements of Stack are: 
A
B
C
d
e
f
G
Number of elements in the stack are: 7

After performing POP operation:- 
Poped element is: 65
Elements of Stack are: 
B
C
d
e
f
G
Number of elements in the stack are: 6

After performing POP operation:- 
Poped element is: 66
Elements of Stack are: 
C
d
e
f
G
Number of elements in the stack are: 5

After performing PUSH operation:- 
Elements of Stack are: 
Z
C
d
e
f
G
Number of elements in the stack are: 6

--------------------------------------------- Stack of Float ----------------------------------------------------

After performing PUSH operations:- 
Elements of Stack are: 
70.548
102.51
98.515
984.25
48.52
24.14
10.54
Number of elements in the stack are: 7

After performing POP operation:- 
Poped element is: 70
Elements of Stack are: 
102.51
98.515
984.25
48.52
24.14
10.54
Number of elements in the stack are: 6

After performing POP operation:- 
Poped element is: 102
Elements of Stack are: 
98.515
984.25
48.52
24.14
10.54
Number of elements in the stack are: 5

After performing PUSH operation:- 
Elements of Stack are: 
1008.63
98.515
984.25
48.52
24.14
10.54
Number of elements in the stack are: 6

--------------------------------------------- Stack of Double ---------------------------------------------------

After performing PUSH operations:- 
Elements of Stack are: 
1650.55
102.51
789.515
984.263
48651.5
24.1465
1084.56
Number of elements in the stack are: 7

After performing POP operation:- 
Poped element is: 1650
Elements of Stack are: 
102.51
789.515
984.263
48651.5
24.1465
1084.56
Number of elements in the stack are: 6

After performing POP operation:- 
Poped element is: 102
Elements of Stack are: 
789.515
984.263
48651.5
24.1465
1084.56
Number of elements in the stack are: 5

After performing PUSH operation:- 
Elements of Stack are: 
10798.7
789.515
984.263
48651.5
24.1465
1084.56
Number of elements in the stack are: 6

--------------------------------------------- Queue Operations --------------------------------------------------

--------------------------------------------- Queue of Integer --------------------------------------------------

After performing ENQUEUE operations:- 
Elements of Queue are: 
10
20
30
40
50
60
70
Number of elements in the Queue are: 7

After performing DEQUEUE operation:- 
Removed element is: 10
Elements of Queue are: 
20
30
40
50
60
70
Number of elements in the Queue are: 6

After performing DEQUEUE operation:- 
Removed element is: 20
Elements of Queue are: 
30
40
50
60
70
Number of elements in the Queue are: 5

After performing Enqueue operation:- 
Elements of Queue are: 
30
40
50
60
70
100
Number of elements in the Queue are: 6

--------------------------------------------- Queue of Characters ----------------------------------------------------

After performing Enqueue operations:- 
Elements of Queue are: 
G
f
e
d
C
B
A
Number of elements in the Queue are: 7

After performing DEQUEUE operation:- 
Removed element is: 71
Elements of Queue are: 
f
e
d
C
B
A
Number of elements in the Queue are: 6

After performing DEQUEUE operation:- 
Removed element is: 102
Elements of Queue are: 
e
d
C
B
A
Number of elements in the Queue are: 5

After performing Enqueue operation:- 
Elements of Queue are: 
e
d
C
B
A
Z
Number of elements in the Queue are: 6

--------------------------------------------- Queue of Float ----------------------------------------------------

After performing Enqueue operations:- 
Elements of Queue are: 
10.54
24.14
48.52
984.25
98.515
102.51
70.548
Number of elements in the Queue are: 7

After performing DEQUEUE operation:- 
Removed element is: 10
Elements of Queue are: 
24.14
48.52
984.25
98.515
102.51
70.548
Number of elements in the Queue are: 6

After performing DEQUEUE operation:- 
Removed element is: 24
Elements of Queue are: 
48.52
984.25
98.515
102.51
70.548
Number of elements in the Queue are: 5

After performing Enqueue operation:- 
Elements of Queue are: 
48.52
984.25
98.515
102.51
70.548
1008.63
Number of elements in the Queue are: 6

--------------------------------------------- Queue of Double ---------------------------------------------------

After performing Enqueue operations:- 
Elements of Queue are: 
1084.56
24.1465
48651.5
984.263
789.515
102.51
1650.55
Number of elements in the Queue are: 7

After performing DEQUEUE operation:- 
Removed element is: 1084
Elements of Queue are: 
24.1465
48651.5
984.263
789.515
102.51
1650.55
Number of elements in the Queue are: 6

After performing DEQUEUE operation:- 
Removed element is: 24
Elements of Queue are: 
48651.5
984.263
789.515
102.51
1650.55
Number of elements in the Queue are: 5

After performing Enqueue operation:- 
Elements of Queue are: 
48651.5
984.263
789.515
102.51
1650.55
10798.7
Number of elements in the Queue are: 6



*/