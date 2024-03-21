#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct item {
    int Data;
    int Prior;
};

void traverse(struct item *Q, int rear, int front);
void Enqueue(struct item *Q, int *rear, int *front ,int data , int priority);
void DeQueue(struct item *Q, int *rear, int *front);

int main() {
    struct item Q[MAX];
    int front = -1;
    int rear = -1;
    int choice;
    int data, priority;

    while(1){
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority to enqueue: ");
                scanf("%d %d", &data, &priority);
                Enqueue(Q, &rear, &front, data, priority);
                break;
            case 2:
                DeQueue(Q, &rear, &front);
                break;
            case 3:
                traverse(Q, rear, front);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}

void traverse(struct item *Q, int rear, int front) {
    if (front == -1 && rear == -1  ) {
        printf("\n UnderFlow \n");
        return ;
    }
    printf("\nQueue : \n Front :");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d<%d>-->", Q[i].Data, Q[i].Prior);
        }
    } 
    else {
        for (int i = front; i < MAX; i++) {
            printf("%d<%d>-->", Q[i].Data, Q[i].Prior);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d<%d>-->", Q[i].Data, Q[i].Prior);
        }
    }
    printf("  REAR\n");
}

void Enqueue(struct item *Q, int *rear, int *front ,int data , int priority){
    if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1)) {
        printf("\n OverFlow \n");
        return;
    }
    
    if (*rear == MAX - 1){
        *rear = 0;
    }
    else if(*rear == -1 && *front == -1){
        *front = 0;
        *rear = 0;
    }
    else{
        (*rear)++;  // Increased the rear position
    }
    
    // locating position of insertion

    int idx = *rear;
    while(idx > *front && priority < Q[(idx - 1 + MAX) % MAX].Prior){
        Q[idx] = Q[(idx - 1 + MAX) % MAX];
        idx = (idx - 1 + MAX) % MAX;
    }

    Q[idx].Data = data;
    Q[idx].Prior = priority;
    printf("\n");
}

void DeQueue(struct item *Q, int *rear, int *front){
    if ((*front) == -1 && (*rear) == -1  ) {
        printf("\n UnderFlow \n");
        return ;
    }
    int item = Q[*front].Data; 
    if (*front == MAX - 1) {
        (*front) = 0;
    }

    else if (*front == *rear) {
        (*front) = -1;
        (*rear) = -1;
    }
    else {
        (*front)++;
    }
    
    printf("\n Deleted element -> %d \n", item);
}
