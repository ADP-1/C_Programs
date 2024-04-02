#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* CreateNode(int data){
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void PreOrderTraversal(struct node* root) {
    if (root != NULL) {
        printf(" %d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void InOrederTraversal(struct node* root){
    if (root != NULL) {
        InOrederTraversal(root->left);
        printf(" %d ", root->data);
        InOrederTraversal(root->right);
    }
}

void PostOrderTraversal(struct node* root){
    if (root != NULL) {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf(" %d ", root->data);
    }
}

int main(){
    
    struct node* n0 = CreateNode(1);
        struct node* n11 = CreateNode(2);
            struct node* n21 = CreateNode(4);
            struct node* n22 = CreateNode(5);

        struct node* n12 = CreateNode(3);
            struct node* n23 = CreateNode(6);
            struct node* n24 = CreateNode(7);

    n0->left = n11;
        n11->left = n21;
        n11->right = n22;  
    n0->right = n12;
        n12->left = n23;
        n12->right = n24;
    
    printf("PreOrderTraversal: \n");
    PreOrderTraversal(n0);
    printf("\nInOrderTraversal: \n");
    InOrederTraversal(n0);
    printf("\nPostOrderTraversal: \n");
    PostOrderTraversal(n0);

    return 0;
}