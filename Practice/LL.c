#include <stdio.h>
#include <stdlib.h>

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

struct Node
{
    int data;
    struct Node *link;
};

void printLinkedList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}

// Function to reverse the linked list
struct Node *reverseLinkedList(struct Node *head)
{
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *linkNode = NULL;

    while (current != NULL)
    {
        linkNode = current->link;
        current->link = prev;
        prev = current;
        current = linkNode;
    }

    head = prev;
    return head;
}

// Function to swap data between two nodes
void swapData(struct Node *node1, struct Node *node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

struct Node* sortingLL(struct Node *head) {
    struct Node *current = head;
    struct Node *iterator;

    while (current != NULL) {
        iterator = current;
        while (iterator->link != NULL) {
            if (iterator->data > iterator->link->data) {
                swapData(&iterator->data, &iterator->link->data);
            }
            iterator = iterator->link;
        }
        current = current->link;
    }
    return head;
}

int main()
{
    // Create a linked list: 1 -> 3 -> 2 -> 5 -> 4
    struct Node *head = createNode(9);
    head->link = createNode(8);
    head->link->link = createNode(7);
    head->link->link->link = createNode(9);
    head->link->link->link->link = createNode(4);

    printf("Original Linked List:\n");
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);
    printf("\nReversed Linked List:\n");
    printLinkedList(head);

    // Sort the linked list using bubble sort
    head = sortingLL(head);
    printf("\nSorted Linked List:\n");
    printLinkedList(head);

    return 0;
}
