#include <stdio.h>
#include <stdlib.h>

int MAX;

struct node{
    int data;
    struct node *link;
};

struct node *createNode();
void push(struct node **top, int item);
int pop(struct node **top);
int peek(struct node **top);
void display(struct node *top);
int isEmpty(struct node *top);
int isFull(struct node *top);
void printMenu();


int main(){
    printf("Enter the size of the stack: ");
    scanf("%d", &MAX);
    struct node *top = createNode();
    top->data = 0;
    top->link = NULL;

    int choice;
    int item;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(&top, item);
                break;

            case 2:
                item = pop(&top);
                if (item != -1) printf("Popped item: %d\n", item);
                break;

            case 3:
                item = peek(&top);
                if (item != -1) printf("Peeked item: %d\n", item);
                break;

            case 4:
                display(top);
                break;

            case 5:
                printf("Is Empty: %s\n", isEmpty(top) ? "Yes" : "No");
                break;

            case 6:
                printf("Is Full: %s\n", isFull(top) ? "Yes" : "No");
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}


struct node *createNode(){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->link = NULL;
    return newNode;
};

void push(struct node **top, int item){
    if (isFull(*top) == 1)
    {
        printf("Overflow\n");
        return;
    }
    struct node *newNode = createNode();
    newNode->data = item;
    newNode->link = *top;
    *top = newNode;
}

int pop(struct node **top){

    if (isEmpty(*top) == 1){
        printf("UnderFlow\n");
        return -1;
    }

    struct node *ptr = *top;
    *top = (*top)->link;
    int item = ptr->data;
    free(ptr);
    return item;
}

int peek(struct node **top){
    if (isEmpty(*top) == 1){
        printf("UnderFlow\n");
        return -1;
    }
    return (*top)->data;
}

void display(struct node *top) {
    if (isEmpty(top) == 1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    struct node *current = top;
    while (current != NULL) {
        printf("%d --> ", current->data);
        current = current->link;
    }
    printf("Null\n");
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Is Empty\n");
    printf("6. Is Full\n");
    printf("7. EXIT\n");
}

int isEmpty(struct node *top){
    return top == NULL ? 1 : 0;
}

int isFull(struct node *top){
    int count = 0;
    struct node* current = top;

    while (current != NULL) {
        count++;
        current = current->link;
    }

    // Compare the count with MAX
    return count == MAX ? 1 : 0;
}
