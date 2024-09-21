#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node * lchild;       // left child
    struct node * rchild;       // right child
};

typedef struct node Node;
typedef struct node* PNode;
typedef struct node** PPNode;


// -------------------------------------------------------------------------------

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
                printf("Unable to insert %d as element is already present (Duplicate value)\n", no);
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


// -------------------------------------------------------------------------------

void Inorder(PNode root){
    if(root != NULL) {
        Inorder(root->lchild);
        printf("%d ", root->data);
        Inorder(root->rchild);
    }
    
}


// -------------------------------------------------------------------------------

void Preorder(PNode root){
    if(root != NULL) {
        printf("%d ", root->data);
        Inorder(root->lchild);
        Inorder(root->rchild);
    }
}


// -------------------------------------------------------------------------------

void Postorder(PNode root){
    if(root != NULL) {
        Inorder(root->lchild);
        Inorder(root->rchild);
        printf("%d ", root->data);
    }
}


// -------------------------------------------------------------------------------

bool Search(PNode root, int no){
    bool flag = false;

    if(root == NULL) {
        printf("Tree is empty!\n");
        return false;
    }

    while(root != NULL){
        if(root->data == no) {
            flag = true;
            break;
        }
        else if(no > root -> data) {
            root = root -> rchild;
        }
        else if(no < root -> data) {
            root = root -> lchild;
        }
    }
    return flag;
}


// -------------------------------------------------------------------------------

int CountLeaf(PNode root){
    static int iCnt = 0;
    if(root != NULL){
        if(root -> rchild == NULL && root -> lchild == NULL){
            iCnt++;
        }
        CountLeaf(root -> lchild);
        CountLeaf(root -> rchild);
    }
    return iCnt;
}



// -------------------------------------------------------------------------------

int CountParent(PNode root){
    static int iCnt = 0;
    if(root != NULL){
        if(root -> rchild != NULL || root -> lchild != NULL){
            iCnt++;
        }
        CountParent(root -> lchild);
        CountParent(root -> rchild);
    }
    return iCnt;
}


// -------------------------------------------------------------------------------
int main(){

    bool bRet = false;
    PNode head = NULL;

    Insert(&head, 21);
    Insert(&head, 34);
    Insert(&head, 11);
    Insert(&head, 98);
    Insert(&head, 44);
    Insert(&head, 28);
    Insert(&head, 11);
    Insert(&head, 7);
    Insert(&head, 17);


    printf("\n");

    printf("Number of Leaf nodes are: %d\n", CountLeaf(head));
    printf("Number of Parent nodes are: %d\n", CountParent(head));

    return 0;
}