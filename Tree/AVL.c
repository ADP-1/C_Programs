#include <stdio.h>

struct node{
    int height;
    int data;
    struct node *left,*right;
};

struct node* CreateNode(int data){
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1 ;
    return newNode;
}

struct node* RotateFromRight(struct node *alpha){
    struct node* p = alpha->right ;
    alpha->right = p->left ;
    alpha->height = 1 + max(alpha->left->height , alpha->right->height);
    p->left = alpha ;
    p->height = 1 + max(p->left->height , p->right->height);
    return p;
}

struct node* RotateFromLeft(struct node *alpha){
    struct node* p = alpha->left ;
    alpha->left = p->right ;
    alpha->height = 1 + max(alpha->left->height , alpha->right->height);
    p->right = alpha ;
    p->height = 1 + max(p->left->height , p->right->height);
    return p;
}

struct node* DoubleRotateRightLeft(struct node *alpha) {
    alpha->right = RotateFromRight(alpha->right); // Rotate Right
    return RotateFromLeft(alpha); // Rotate Left
}

struct node* DoubleRotateLeftRight(struct node *alpha) {
    alpha->left = RotateFromLeft(alpha->left); // Rotate Left
    return RotateFromRight(alpha); // Rotate Right
}

