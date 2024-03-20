#include <stdio.h>
#include <stdlib.h>

// Structure for Node
struct node{
    struct node*prev;
    int Data;
    struct node*next;
};

// Structure For DMA of node
struct node *Create_Node(){
    return (struct node*)malloc(sizeof(struct node));
}

void travese(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr!=NULL){
        printf("%d -> ",ptr->Data);
        ptr = ptr -> next ;
    }
    printf("NULL\n");
}

void travese_using_End(struct node *end){

    struct node *ptr = end;
    while(ptr!=NULL){
        printf("%d -> ",ptr->Data);
        ptr = ptr -> prev ;
    }
    printf("NULL\n");
}

int countNodes(struct node *start) {
  int count = 0;
  struct node *ptr;
  ptr = start;
  while (ptr != NULL) {
    count++;
    ptr = ptr->next;
  }
  printf("No of Nodes are : %d\n", count);
  return count;
}

void insert_begining(struct node **start ,struct node **end, int item){
    struct node *n1 = Create_Node();
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n1->Data = item;
    n1->prev = NULL;

    if(*start != NULL){
        n1->next = *start;
        (*start)->prev = n1;
        *start = n1;
    }
    else{
        // If the list is empty
        *start = *end = n1;
        n1->next = NULL;
    }
}

void insert_at_End(struct node **start ,struct node **end, int item){
    struct node *n1 = Create_Node();
    
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n1->Data = item;
    n1->prev = NULL;
    n1->next = NULL;


    if(*start == NULL) *start = *end = n1;
    else{
        n1->prev = *end;
        (*end)->next = n1;
        *end = n1;
    }
}

void insertSpecific(struct node **start, struct node **end, int item, int pos) {
    struct node *n1 = Create_Node();
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n1->Data = item;
    n1->next = NULL;
    n1->prev = NULL;

    if (*start == NULL) *start = *end = n1;
    
    else if (pos == 0) {
        n1->next = *start;
        (*start)->prev = n1;
        *start = n1;
    } 
    else{
        struct node *ptr = *start;
        int currentPos = 0;

        while (ptr->next != NULL && currentPos != pos - 1) {
            ptr = ptr->next;
            currentPos++;
        }

        n1->next = ptr->next;
        
        if (ptr->next != NULL) ptr->next->prev = n1;
        else *end = n1;

        n1->prev = ptr;
        ptr->next = n1;
    }
}

void del_first(struct node **start,struct node **end){
    if(*start == NULL){
        printf("UnderFlow");
        return;
    }
    
    struct node *ptr;
    ptr = *start;

    *start = (*start)->next;
    
    if(*start == NULL) *end = NULL;
    
    else{
        (*start)->prev = NULL;
    }
    free(ptr);
}

void del_end(struct node **start,struct node **end){
    if(*start == NULL){
        printf("UnderFlow");
        return;
    }
    
    if(*start == *end){
        *start = *end = NULL;
        return;
    }

    struct node *ptr = *end;
    *end = ptr->prev;
    (*end)->next = NULL;
    free(ptr);
}

void del_specific(struct node **start, struct node **end, int pos){
    if (*start == NULL){
        printf("UnderFlow");
        return;
    }

    struct node *ptr = *start;
    int currentPos = 0;

    while (ptr != NULL && currentPos != pos){
        ptr = ptr->next;
        currentPos++;
    }

    if (ptr == NULL){
        printf("Invalid Position");
        return;
    }

    if (ptr == *start){
        // Case: Deleting the first node
        *start = ptr->next;
        
        if (*start != NULL) (*start)->prev = NULL;
        
        else *end = NULL; // Case: List becomes empty after deletion
    }

    else if (ptr == *end){
        // Case: Deleting the last node
        *end = ptr->prev;
        (*end)->next = NULL;
    }

    else{
        // Case: Deleting a node from somewhere in between
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    free(ptr);
}

int main() {
    struct node *n1, *start = NULL , *end = NULL; 
    int item, pos;

    // Insert at the beginning
    insert_begining(&start, &end, 10);
    insert_begining(&start, &end, 20);
    insert_begining(&start, &end, 30);

    printf("List after insert at the beginning: ");
    travese(start);

    // Insert at the end
    insert_at_End(&start, &end, 40);
    insert_at_End(&start, &end, 50);
    printf("List after insert at the end: ");
    travese(start);

    // Insert at a specific position
    insertSpecific(&start, &end, 25, 2);
    insertSpecific(&start, &end, 35, 4);
    printf("List after insert at specific positions: ");
    travese(start);

    // Delete the first node
    del_first(&start, &end);
    printf("List after deleting the first node: ");
    travese(start);

    // Delete the last node
    del_end(&start, &end);
    printf("List after deleting the last node: ");
    travese(start);

    // Delete a node at a specific position
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    del_specific(&start, &end, pos);
    printf("List after deleting a node at a specific position: ");
    travese(start);

    // Count the number of nodes
    countNodes(start);

    return 0;
}


void travese(struct node *start);
int countNodes(struct node *start);
void insert_begining(struct node **start ,struct node **end, int item);