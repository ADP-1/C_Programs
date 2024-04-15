    #include <stdio.h>
    #include <stdlib.h>


    struct Node {
        int data;
        struct Node* next;
    };


    struct Node* Create_Node(int data) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed. Unable to create node.\n");
            return NULL;
        }
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }


    struct Node* getLastNode(struct Node* head) {
        struct Node* lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }
        return lastNode;
    }


    void insertAtBeginning(struct Node** headRef, int newData) {
        struct Node* newNode = Create_Node(newData);
        if (newNode == NULL) {
            return; // Memory allocation failed
        }

        if (*headRef == NULL) {
            newNode->next = newNode; // Circular link for single node
        } else {
            struct Node* lastNode = getLastNode(*headRef);
            newNode->next = *headRef;
            lastNode->next = newNode;
        }
        *headRef = newNode;
    }


    void insertAtEnd(struct Node** headRef, int newData) {
        struct Node* newNode = Create_Node(newData);
        if (newNode == NULL) {
            return; // Memory allocation failed
        }

        if (*headRef == NULL) {
            newNode->next = newNode; // Circular link for single node
            *headRef = newNode;
        } else {
            struct Node* lastNode = getLastNode(*headRef);
            newNode->next = *headRef;
            lastNode->next = newNode;
        }
    }


    void insertAtNthPosition(struct Node** headRef, int newData, int position) {
        if (position < 1) {
            printf("Invalid position. Position should be >= 1.\n");
            return;
        }

        if (position == 1) {
            insertAtBeginning(headRef, newData);
            return;
        }

        struct Node* newNode = Create_Node(newData);
        if (newNode == NULL) {
            return; // Memory allocation failed
        }

        struct Node* currentNode = *headRef;
        for (int i = 1; i < position - 1 && currentNode != NULL; i++) {
            currentNode = currentNode->next;
        }

        if (currentNode == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            free(newNode);
            return;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }


    void deleteFromBeginning(struct Node** headRef) {
        if (*headRef == NULL) {
            printf("List is empty. Nothing to delete.\n");
            return;
        }

        if ((*headRef)->next == *headRef) {
            // Single node in the list
            free(*headRef);
            *headRef = NULL;
            return;
        }

        struct Node* lastNode = getLastNode(*headRef);
        struct Node* temp = *headRef;
        *headRef = (*headRef)->next;
        lastNode->next = *headRef;
        free(temp);
    }


    void deleteFromEnd(struct Node** headRef) {
        if (*headRef == NULL) {
            printf("List is empty. Nothing to delete.\n");
            return;
        }

        if ((*headRef)->next == *headRef) {
            // Single node in the list
            free(*headRef);
            *headRef = NULL;
            return;
        }

        struct Node* secondLastNode = *headRef;
        while (secondLastNode->next->next != *headRef) {
            secondLastNode = secondLastNode->next;
        }

        struct Node* lastNode = secondLastNode->next;
        secondLastNode->next = *headRef;
        free(lastNode);
    }


    void deleteFromNthPosition(struct Node** headRef, int position) {
        if (position < 1 || *headRef == NULL) {
            printf("Invalid position or empty list. Nothing to delete.\n");
            return;
        }

        if (position == 1) {
            deleteFromBeginning(headRef);
            return;
        }

        struct Node* currentNode = *headRef;
        struct Node* prevNode = NULL;
        for (int i = 1; i < position && currentNode != NULL; i++) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        if (currentNode == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            return;
        }

        prevNode->next = currentNode->next;
        free(currentNode);
    }

    void displayList(struct Node* head) {
        if (head == NULL) {
            printf("List is empty.\n");
            return;
        }

        struct Node* currentNode = head;
        printf("Circular Linked List: ");
        do {
            printf("%d -> ", currentNode->data);
            currentNode = currentNode->next;
        } while (currentNode != head);
        printf("(head)\n");
    }

    int main() {
        struct Node* head = NULL;

        // Test insertion operations
        insertAtEnd(&head, 10);
        displayList(head);
        insertAtEnd(&head, 20);
        displayList(head);
        insertAtBeginning(&head, 5);
        displayList(head);
        insertAtNthPosition(&head, 15, 3);
        displayList(head);

        // Test deletion operations
        deleteFromEnd(&head);
        displayList(head);
        deleteFromBeginning(&head);
        displayList(head);
        deleteFromNthPosition(&head, 2);
        displayList(head);

        return 0;
    }
