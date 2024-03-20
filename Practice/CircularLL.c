#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *createNode(){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 0;
    newNode->link = NULL;
    return newNode;
}

void display(struct node *last){
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current = last->link;

    do
    {
        printf("%d -> ", current->data);
        current = current->link;
    } while (current != last->link);

    printf("(back to the start)\n");
}

void insertFirst(struct node **last, int value){
    struct node *n1 = createNode();
    n1->data = value;
    if (*last == NULL){
        *last = n1;
        n1->link = n1;
    }
    else
    {
        n1->link = (*last)->link;
        (*last)->link = n1;
    }
}

void insertEnd(struct node **last, int value){
    struct node *n1 = createNode();
    n1->data = value;
    if (*last == NULL)
    {
        *last = n1;
        n1->link = n1;
    }
    else
    {
        n1->link = (*last)->link;
        (*last)->link = n1;
        *last = n1;
    }
}

void insertSpecific(struct node **last, int value, int pos){
    if (pos == 1 || *last == NULL)
    {
        insertFirst(last, value);
        return;
    }

    struct node *ptr = *last;
    int count = 1;  // Start from 1 since the list already has at least one element

    while (ptr->link != *last && count < pos - 1)
    {
        ptr = ptr->link;
        count += 1;
    }

    struct node *n1 = createNode();
    n1->data = value;
    n1->link = ptr->link;
    ptr->link = n1;

    // If the position is greater than the current size, insert at the end
    if (n1->link == *last || count == pos - 1)
    {
        *last = n1;
        printf("Position %d is greater than the current size. Node inserted at the end.\n", pos);
    }
}

void delFirst(struct node **last){
    if (*last == NULL){
        printf("Underflow: List is empty. Cannot delete.\n");
        return;
    }

    struct node *ptr = (*last)->link;

    if (ptr == *last){
        free(ptr);
        *last = NULL;
    }
    else{
        (*last)->link = ptr->link;
        free(ptr);
    }
}

void delEnd(struct node **last)
{
    if (*last == NULL)
    {
        printf("Underflow: List is empty. Cannot delete.\n");
        return;
    }

    struct node *ptr = (*last)->link;

    if (ptr == *last)
    {
        // Only one node in the list
        free(ptr);
        *last = NULL;
        return;
    }

    while (ptr->link != *last)
    {
        ptr = ptr->link;
    }

    ptr->link = (*last)->link;
    free(*last);
    *last = ptr;
}


int main()
{
    struct node *last = NULL;
    
    insertFirst(&last, 10);
    display(last);
    
    insertFirst(&last, 20);
    display(last);
    
    insertEnd(&last, 30);
    display(last);

    insertSpecific(&last , 99 ,7);
    display(last);

    delFirst(&last);
    display(last);
    
    delEnd(&last);
    display(last);

    return 0;
}
