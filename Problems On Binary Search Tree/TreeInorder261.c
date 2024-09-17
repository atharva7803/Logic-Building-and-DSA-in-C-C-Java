#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * lchild;       // left child
    struct node * rchild;       // right child
};

typedef struct node Node;
typedef struct node* PNode;
typedef struct node** PPNode;

void Insert(PPNode root, int no){
    PNode newn = NULL;
    PNode temp = NULL;

    newn = (PNode)malloc(sizeof(Node));

    newn -> data = no;
    newn -> lchild = NULL;
    newn -> rchild = NULL;

    if(*root == NULL){      // Tree is empty
        *root = newn;
    }
    else{                   //  Tree contains at least one node
        temp = *root;
        while(1){
            if(no == temp -> data){
                printf("Unable to insert as element is already present(Duplicate value)\n");
                free(newn);
                break;
            }

            else if(no > temp -> data){
                if(temp -> rchild == NULL){
                    temp -> rchild = newn;
                    break;
                }
                temp = temp -> rchild;
            }

            else if(no < temp -> data){
                if(temp -> lchild == NULL){
                    temp -> lchild = newn;
                    break;
                }
                temp = temp -> lchild;
            }
        }
    }
}



void Inorder(PNode root){
    if(root != NULL) {
        Inorder(root->lchild);
        printf("%d ", root->data);
        Inorder(root->rchild);
    }
}




int main(){


    PNode head = NULL;

    Insert(&head, 21);
    Insert(&head, 11);
    Insert(&head, 51);


    Inorder(head);
    

    return 0;
}