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

void PreOrderTraversal(struct node* root){
    if (root != NULL){
        printf(" %d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void InOrederTraversal(struct node* root){
    if (root != NULL){
        InOrederTraversal(root->left);
        printf(" %d ", root->data);
        InOrederTraversal(root->right);
    }
}

void PostOrderTraversal(struct node* root){
    if (root != NULL){
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf(" %d ", root->data);
    }
}


void Traversal(struct node* root){
    if (root != NULL){
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

void addBSTnode(struct node** root, int data){
    struct node* newNode = CreateNode(data);
    if (*root == NULL){
        *root = newNode;
        return;
    }

    struct node* ptr = *root;
    struct node* parent = NULL;

    while (ptr != NULL){
        parent = ptr;
        if (ptr->data > data){
            ptr = ptr->left;
        } else if (ptr->data == data){
            printf("It's a Duplicate Element\n");
            free(newNode); // Free the unused node
            return;
        } else {
            ptr = ptr->right;
        }
    }

    if (parent->data > data){
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

struct node* findMinNode(struct node** node){
    struct node* current = *node;
    struct node* parent = NULL;

    while (current && current->left != NULL){
        parent = current;
        current = current->left;
    }

    if (parent && current->right != NULL){
        parent->left = current->right; // Reconnect parent's left pointer
    }

    return current;
}

void deleteNode(struct node** root, int data){
    if (*root == NULL){
        return; // Base case: Tree is empty or node not found
    }

    if (data < (*root)->data){
        deleteNode(&((*root)->left), data);
    } 
    else if (data > (*root)->data){
        deleteNode(&((*root)->right), data); 
    } 
    else {// Node Found which we have to delete

        // Case 1: Node with no or one child
        if ((*root)->left == NULL){
            struct node* temp = *root;
            *root = (*root)->right; // Update root to the right child (or NULL if no child)
            free(temp); // Free memory of the node to be deleted
        } 
        else if ((*root)->right == NULL){
            struct node* temp = *root;
            *root = (*root)->left; // Update root to the left child
            free(temp); // Free memory of the node to be deleted
        } 
        else {
            // Case 2: Node with two children
            // Find the inorder successor (smallest node in the right subtree)
            struct node* temp = findMinNode(&((*root)->right));
            // Copy the inorder successor's data to the current node
            (*root)->data = temp->data;
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

    struct node *root = CreateNode(10);
    addBSTnode(&root , 5);
    addBSTnode(&root , 3);
    addBSTnode(&root , 2);
    addBSTnode(&root , 4);
    addBSTnode(&root , 7);
    addBSTnode(&root , 6);
    addBSTnode(&root , 8);
    addBSTnode(&root , 9);
    addBSTnode(&root , 15);
    addBSTnode(&root , 12);
    addBSTnode(&root , 11);
    addBSTnode(&root , 13);
    addBSTnode(&root , 14);
    addBSTnode(&root , 18);
    addBSTnode(&root , 17);
    addBSTnode(&root , 19);


    // printf("PreOrderTraversal: \n");
    // PreOrderTraversal(root);
    // printf("\nInOrderTraversal: \n");
    // InOrederTraversal(root);
    // printf("\nPostOrderTraversal: \n");
    // PostOrderTraversal(root);
    // InOrederTraversal(root);
    deleteNode(&root , 15);
    InOrederTraversal(root);


    return 0;
}