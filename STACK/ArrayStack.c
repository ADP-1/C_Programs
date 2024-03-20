#include <stdio.h>
#include <stdlib.h>

int MAX;

void display(int *stack , int top){
    for(int i = top ; i >= 0 ; i--){
        printf("%d --> ",stack[i]);
    }
    printf("Null\n");
}

void push(int *stack , int *top , int item , int max){
    if(*top == max){
        printf("OverFlow\n");
        return ;
    }
    (*top)++; 
    stack[*top] = item;    
}

void pop(int *stack , int *top){
    if(*top == -1){
        printf("UnderFlow\n");
        return;
    }
    stack[*top] = -1;
    *top--;
}

void peek(int *stack , int top){
    if(top == -1){
        printf("UnderFlow\n");
        return;
    }
    int item = stack[top];
    printf("Top item is : %d\n" , item);
}

int isEmpty(int *stack , int top){
    return top == -1 ? 0 : 1;   
}

int isFull(int *stack , int top ){
    return top == MAX ? 0 : 1;
}

int main() {
    printf("Enter the size of the stack: ");
    scanf("%d", &MAX);
    int stack[MAX];
    int top = -1;
    int choice;
    int item, n = 0;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Display Stack\n");
        printf("2. Insert Element \n");
        printf("3. Delete Element\n");
        printf("4. Top Element\n");
        printf("5. To Check If Empty\n");
        printf("6. To Check If Full\n");
        printf("7. EXIT\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                display(stack, top);
                break;
            }

            case 2:
                printf("Enter the item to Insert : ");
                scanf("%d", &item);
                push(stack, &top, item, MAX);
                display(stack, top);
                break;

            case 3:
                printf("The Deleted item is : %d", top);
                pop(stack, &top);
                display(stack, top);
                break;

            case 4:
                peek(stack, top);
                break;

            case 5: {
                n = isEmpty(stack, top);
                if (n == 0) {
                    printf("UnderFlow");
                } else {
                    printf("Not empty");
                }
                break;
            }

            case 6:
                n = isFull(stack, top);
                if (n == 0) {
                    printf("Overflow");
                } else {
                    printf("Space is Available");
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
