#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void traverse(int *Q, int rear, int front) {
    if (front == -1 && rear == -1  ) {
        printf("\n UnderFlow \n");
        return ;
    }
    printf("\nQueue : ");
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
    printf("  REAR\n");
}

void EnQueue(int *Q, int *rear, int *front, int data) {
    if ((*front == (*rear) + 1) || (*front == 0 && *rear == MAX - 1)) {
        printf("\n OverFlow \n");
        return;
    }
    
    if(*rear == -1 && *front == -1){
        (*front) = 0;
        (*rear)  = 0;
    }

    else if (*rear == MAX){
        *rear = 0;
    }
    
    else{
        (*rear)+=1;
    }
    
    Q[(*rear)] = data;
    printf("\n");
}


void DeQueue(int *Q, int *rear, int *front) {
    if ((*front) == -1 && (*rear) == -1  ) {
        printf("\n UnderFlow \n");
        return ;
    }
    int item = Q[*front]; 
    if (*front == MAX) {
        (*front) = 0;
    }

    else if (*front == *rear) {
        (*front) = -1;
        (*rear) = -1;
    }
    else {
        (*front) += 1;
    }
    
    printf("\n Deleted element -> %d \n", item);
}

int main() {
    int Q[MAX] ;
    int rear = -1, front = -1;

    int choice, item;

    while (1) {
        printf("\n1.Display Queue \n2.Enqueue \n3.DeQueue \n4.EXIT\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            traverse(Q, rear, front);
            break;

        case 2:
            printf("Enter the Number to Insert : ");
            scanf("%d", &item);
            EnQueue(Q, &rear, &front, item);
            printf("\n");
            break;

        case 3:
            DeQueue(Q, &rear, &front);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }
    return 0;
}
