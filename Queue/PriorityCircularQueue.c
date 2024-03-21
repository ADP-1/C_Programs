#include <stdio.h>
#define MAX 10

struct item {
    int Data;
    int Prior;
};

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

int main(){
    struct item Q[MAX];
    int front = -1;
    int rear = -1;
    traverse(Q, rear , front);
    Enqueue(Q , &rear ,&front , 5 , 1);
    traverse(Q, rear , front);
    Enqueue(Q , &rear ,&front , 99 , 5);
    traverse(Q, rear , front);
    Enqueue(Q , &rear ,&front , 67 , 2);

    traverse(Q, rear , front);
    return 0;
}