#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Static size of the queue

int isFull(int front, int rear) {
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
        return 1;
    return 0;
}

int isEmpty(int front, int rear) {
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

void traverse(int *Q, int rear, int front) {
    if (front == -1 && rear == -1) {
        printf("\nUnderFlow\n");
        return;
    }
    printf("\nFRONT --> ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d --> ", Q[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d --> ", Q[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d --> ", Q[i]);
        }
    }
    printf("<-- REAR\n");
}

void EnQueueRear(int *Q, int *rear, int *front, int data) {
    if (isFull(*front, *rear) == 1) {
        printf("\nOverflow\n");
        return;
    }

    if (*rear == MAX - 1)
        *rear = 0;
    else if (*rear == -1 && *front == -1)
        *front = *rear = 0;
    else
        (*rear)++;

    Q[*rear] = data;
}

void EnQueueFront(int *Q, int *rear, int *front, int data) {
    if (isFull(*front, *rear) == 1) {
        printf("\nOverflow\n");
        return;
    }

    if (*front == 0 && *rear != MAX - 1)
        *front = MAX - 1;
    else if (*rear == -1 && *front == -1)
        *front = *rear = 0;
    else
        (*front)--;

    Q[*front] = data;
}

void DeQueueFront(int *Q, int *rear, int *front) {
    if (isEmpty(*front, *rear) == 1) {
        printf("\nUnderFlow\n");
        return;
    }

    int item = Q[*front];
    if (*front == MAX)
        *front = 0;
    else if (*front == *rear)
        *front = *rear = -1;
    else
        (*front)++;

    printf("\nDeleted element: %d\n", item);
}

void DeQueueRear(int *Q, int *rear, int *front) {
    if (isEmpty(*front, *rear) == 1) {
        printf("\nUnderFlow\n");
        return;
    }

    int item = Q[*rear];
    if (*rear == 0)
        *rear = MAX - 1;
    else if (*front == *rear)
        *front = *rear = -1;
    else
        (*rear)--;

    printf("\nDeleted element: %d\n", item);
}

int main() {
    int rear = -1, front = -1;
    int choice, item;
    int Q[MAX] = {0};  // Static declaration of the queue array

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Display Queue\n");
        printf("2. EnQueueRear\n");
        printf("3. EnQueueFront\n");
        printf("4. DeQueueFront\n");
        printf("5. DeQueueRear\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(Q, rear, front);
                break;

            case 2:
                printf("Enter the number to insert at rear: ");
                scanf("%d", &item);
                EnQueueRear(Q, &rear, &front, item);
                traverse(Q, rear, front);
                break;

            case 3:
                printf("Enter the number to insert at front: ");
                scanf("%d", &item);
                EnQueueFront(Q, &rear, &front, item);
                traverse(Q, rear, front);
                break;

            case 4:
                DeQueueFront(Q, &rear, &front);
                traverse(Q, rear, front);
                break;

            case 5:
                DeQueueRear(Q, &rear, &front);
                traverse(Q, rear, front);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
