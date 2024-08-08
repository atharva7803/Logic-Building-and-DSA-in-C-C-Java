#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

typedef struct node Node;
typedef struct node * PNode;    // p - pointer node
typedef struct node ** PPNode;  // pp - pointer to pointer node

int main(){

    PNode head = NULL;
    Node obj1;
    Node obj2;
    Node obj3;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    head = &obj1;

    printf("Head: %d\n", head);
    printf("obj1: %d\n", &obj1);
    printf("obj2: %d\n", &obj2);
    printf("obj3: %d\n", &obj3);

    printf("Head -> data: %d\n", head->data);   // 11
    printf("Head -> next: %d\n", head->next);   // 200
    printf("Head -> next -> next: %d\n", head->next->next);   // 300
    printf("Head -> next -> next -> next: %d\n", head->next->next->next);   // null

    printf("Head -> next -> data: %d\n", head->next->data);     // 21
    printf("Head -> next -> next -> data: %d\n", head->next->next->data);       // 51

    return 0;
}