#include <stdio.h>
#include <stdlib.h>
#define MAX 10

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
    if (front == -1 && rear == -1  ) {
        printf("\n UnderFlow \n");
        return ;
    }
    printf("\nFRONT-->");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d-->", Q[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d-->", Q[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d-->", Q[i]);
        }
    }
    printf("<--REAR\n");
}

void EnQueueRear(int *Q, int *rear, int *front, int data) {
    if (isFull(*front, *rear) == 1) {
        printf("\n Overflow \n");
        return;
    }

    // If the rear pointer is at the end of the circular array, wrap around
    if (*rear == MAX - 1)
        *rear = 0;
    // If the queue is initially empty, set both front and rear pointers to 0
    else if (*rear == -1 && *front == -1)
        *front = *rear = 0;
    // Move rear pointer to the next position
    else
        (*rear)++;

    // Insert the data into the queue at the rear position
    Q[*rear] = data;
}

void EnQueueFront(int *Q, int *rear, int *front, int data) {
    if (isFull(*front, *rear) == 1) {
        printf("\n Overflow \n");
        return;
    }

    // If the front pointer is at the beginning of array and rear is not at the end.
    if (*front == 0 && *rear != MAX - 1)
        *front = MAX - 1;
    // If the queue is initially empty, set both front and rear pointers to 0
    else if (*rear == -1 && *front == -1)
        *front = *rear = 0;
    // Move front pointer to the previous position
    else
        (*front)--;

    // Insert the data into the queue at the front position
    Q[*front] = data;
}


void DeQueueFront(int *Q, int *rear, int *front) {
    int element;
    if (isEmpty(*front, *rear) == 1) {
        printf("\n UnderFlow \n");
        return ;
    }
    int item = Q[*front]; 
    if (*front == MAX) *front = 0;
    
    // if Front And Rear Having one node only 
    else if (*front == *rear) {
        *front = -1;
        *rear = -1;
    }
    else *front += 1;

    printf("\n Deleted element -> %d \n", item);
}

void DeQueueRear(int *Q, int *rear, int *front) {
    if (isEmpty(*front, *rear) == 1) {
        printf("\n UnderFlow \n");
        return ;
    }
    int item = Q[*rear]; 
    if (*rear == 0) *rear = MAX - 1;

    else if (*front == *rear) {
        *front = -1;
        *rear = -1;
    }
    else (*rear)--;

    printf("\n Deleted element -> %d \n", item);
}

int main() {
    int Q[MAX] = {0};
    int rear = -1, front = -1;

    int choice, item;

    while (1) {
        printf("\n1.Display Queue \n2.EnQueueRear \n3.EnQueueFront \n4.DeQueueFront \n5.DeQueueFront \n6.Exit\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            traverse(Q, rear, front);
            break;

        case 2:
            printf("Enter the Number to Insert At rear: ");
            scanf("%d", &item);
            EnQueueRear(Q, &rear, &front, item);
            printf("\nAfter EnQueueRear :\n");
            traverse(Q, rear, front);
            break;

        case 3:
            printf("Enter the Number to Insert At Front : ");
            scanf("%d", &item);
            EnQueueFront(Q, &rear, &front, item);
            printf("\nAfter EnQueueFront :\n");
            traverse(Q, rear, front);
            break;

        case 4:
            DeQueueFront(Q, &rear, &front);
            printf("\nAfter DnQueueFront :\n");
            traverse(Q, rear, front);
            break;
        
        case 5:
            DeQueueRear(Q, &rear, &front);
            printf("\nAfter DeQueueRear :\n");
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
