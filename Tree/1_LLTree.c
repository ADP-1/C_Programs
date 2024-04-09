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


void Traversal(struct node* root){
    if (root != NULL) {
        printf(" %d ", root->data);
        Traversal(root->left);
        printf(" %d ", root->data);
        Traversal(root->right);
        printf(" %d ", root->data);
    }
}

void addNode(struct node **root , int data){
    struct node *ptr = *root;
    if(*root == NULL){
        *root = ptr;
        ptr = CreateNode(data);
        return;
    }

}

struct node *Search(struct node *root , int data){
    if (root == NULL) return NULL;
    if(root->data == data) return root;
    else if(root->data > data ) return Search(root->left , data);
    else return Search(root->right , data); 
}

void addBSTnode(struct node** root, int data) {
    struct node* newNode = CreateNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct node* ptr = *root;
    struct node* parent = NULL;

    while (ptr != NULL) {
        parent = ptr;
        if (ptr->data > data) {
            ptr = ptr->left;
        } else if (ptr->data == data) {
            printf("It's a Duplicate Element\n");
            free(newNode); // Free the unused node
            return;
        } else {
            ptr = ptr->right;
        }
    }

    if (parent->data > data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

struct node* findMinNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void deleteNode(struct node** root, int data) {
    if (*root == NULL) {
        return;
    }

    if (data < (*root)->data){
        deleteNode(&((*root)->left), data);
    } 
    else if (data > (*root)->data) {
        deleteNode(&((*root)->right), data);
    } 
    else {
        // Case1: with no node or one node
        if ((*root)->left == NULL){
            struct node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            struct node* temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        // Case 2:Node with two child
        else {
            // Find smallest node in the right subtree
            struct node* temp = findMinNode((*root)->right);
            //Copy the inorder successor data.
            (*root)->data = temp->data;
            // Delete the inorder successor
            deleteNode(&((*root)->right), temp->data);
        }
    }
}


int main(){
    
    // struct node* n0 = CreateNode(55);
    //     struct node* n11 = CreateNode(25);
    //         struct node* n21 = CreateNode(20);
    //         struct node* n22 = CreateNode(30);

    //     struct node* n12 = CreateNode(75);
    //         struct node* n23 = CreateNode(70);
    //         struct node* n24 = CreateNode(80);

    // n0->left = n11;
    //     n11->left = n21;
    //     n11->right = n22;  
    // n0->right = n12;
    //     n12->left = n23;
    //     n12->right = n24;

    struct node *root = CreateNode(55);
    addBSTnode(&root , 25);
    addBSTnode(&root , 20);
    addBSTnode(&root , 75);
    addBSTnode(&root , 80);
    addBSTnode(&root , 30);
    addBSTnode(&root , 70);


    // printf("PreOrderTraversal: \n");
    // PreOrderTraversal(root);
    // printf("\nInOrderTraversal: \n");
    // InOrederTraversal(root);
    // printf("\nPostOrderTraversal: \n");
    // PostOrderTraversal(root);
    deleteNode(&root , 80);
    InOrederTraversal(root);


    return 0;
}