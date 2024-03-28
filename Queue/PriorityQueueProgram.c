#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* CreateNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void traverse(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insert(struct node** head, int data) {
    struct node* n1 = CreateNode(data);
    if (*head == NULL || data >= (*head)->data) {
        n1->next = *head;
        *head = n1;
    } else {
        struct node* ptr = *head;
        while (ptr->next != NULL && data < ptr->next->data) {
            ptr = ptr->next;
        }
        n1->next = ptr->next;
        ptr->next = n1;
    }
}

void delLargest(struct node** head) {
    if (*head == NULL) {
        printf("Underflow: List is empty\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    struct node* head = NULL;

    insert(&head, 23);
    insert(&head, 99);
    insert(&head, 1);

    printf("Linked list after insertions:\n");
    traverse(head);

    delLargest(&head);
    printf("Linked list after deleting the largest element:\n");
    traverse(head);

    return 0;
}