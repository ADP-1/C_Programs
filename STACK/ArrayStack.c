#include <stdio.h>
#include <stdlib.h>

int MAX_SIZE;  // Global variable to store the size of the stack

void display(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d --> ", stack[i]);
    }
    printf("Null\n");
}

void push(int *stack, int *top, int item, int max) {
    if (*top == max - 1) {
        printf("Stack Overflow. Cannot push item.\n");
        return;
    }
    (*top)++;
    stack[*top] = item;
}

void pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack Underflow. Cannot pop item.\n");
        return;
    }
    printf("Deleted item: %d\n", stack[*top]);
    (*top)--;
}

void peek(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top item is: %d\n", stack[top]);
}

int isEmpty(int *stack, int top) {
    return (top == -1) ? 1 : 0;
}

int isFull(int *stack, int top, int max) {
    return (top == max - 1) ? 1 : 0;
}

int main() {
    int top = -1;  // Initialize stack top
    int choice, item;

    printf("Enter the size of the stack: ");
    scanf("%d", &MAX_SIZE);  // Read the size of the stack from user input

    int stack[MAX_SIZE];  // Declare stack array based on user input size

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Display Stack\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Top Element\n");
        printf("5. Check If Empty\n");
        printf("6. Check If Full\n");
        printf("7. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(stack, top);
                break;

            case 2:
                printf("Enter the item to Insert: ");
                scanf("%d", &item);
                push(stack, &top, item, MAX_SIZE);
                display(stack, top);
                break;

            case 3:
                pop(stack, &top);
                display(stack, top);
                break;

            case 4:
                peek(stack, top);
                break;

            case 5:
                if (isEmpty(stack, top)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 6:
                if (isFull(stack, top, MAX_SIZE)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
