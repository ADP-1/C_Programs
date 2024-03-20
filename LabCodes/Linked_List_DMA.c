#include <stdio.h>
#include <stdlib.h>

// Structure for Node
struct node{
    int Data;
    struct node*Link;
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
        ptr = ptr -> Link ;
    }
    printf("NULL\n");
}

void countNodes(struct node *start) {
  int count = 0;
  struct node *ptr;
  ptr = start;
  while (ptr != NULL) {
    count++;
    ptr = ptr->Link;
  }
  printf("No of Nodes are : %d\n", count);
}

void Search(struct node *start, int Item){
    int count = 1;
    struct node *ptr;
    ptr = start;
    while (ptr != NULL && ptr->Data != Item){
        count++;
        ptr = ptr->Link;
    }

    if (ptr == NULL){
        printf("Element Not found");
    }
    else{
        printf("%d found at %dth node.\n", Item, count);
    }
}

void insert_begining(struct node **start , int item){
    struct node *n1 = Create_Node();
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n1->Data = item;
    n1->Link = *start;
    *start = n1;
}

void insert_at_End(struct node **start, int item){
    struct node *n1 = Create_Node();
    
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n1->Data = item;
    n1->Link = NULL;

    if(*start == NULL) *start = n1;
    else{
        struct node *ptr;
        ptr = *start;

        while(ptr->Link != NULL){
            ptr = ptr->Link;
        }
        ptr->Link = n1;
    }
}

void insertSpecific(struct node **start , int item , int pos){
    struct node *n1 = Create_Node();
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    n1->Data = item;
    n1->Link = NULL;
    
    if(pos == 0){
        n1->Link = *start;
        *start = n1;
    }
    else{
        struct node *ptr;
        ptr = *start;
        int currentPos = 0;

        while(ptr!= NULL && currentPos != pos-2){
            ptr = ptr->Link;
            currentPos++;
        }
        if (ptr == NULL) {
            printf("Invalid position for insertion.\n");
            free(n1);                                    // Release the allocated memory
            return;
        }
        n1->Link = ptr->Link;
        ptr->Link = n1;
    }
}

void del_begining(struct node **start){
    if(*start == NULL){
        printf("UnderFlow");
        return;
    }

    struct node *ptr;
    ptr = *start;
    *start = (*start)->Link;
    free(ptr);
}

void del_end(struct node **start){
    
    if(*start == NULL){
        printf("UnderFlow");
        return;
    }
    
    struct node *ptr = *start;
    struct node *pptr = NULL;

    while (ptr->Link != NULL){
        pptr = ptr;
        ptr = ptr->Link;
    }

    if(ptr == *start) *start = NULL;

//  Remove the last node from the list
    else pptr->Link = NULL;
    
//  Free the memory of deleted node.
    free(ptr);
}

void del_specific(struct node **start , int pos){
    if(*start == NULL){
        printf("UnderFlow");
        return;
    }
    int counter = 0;
    struct node *ptr = *start;
    struct node *prev = NULL;

    while(ptr != NULL && counter != pos - 1){
        counter++;
        prev = ptr;
        ptr = ptr->Link;
    }
    if(ptr == NULL){
        printf("Invalid Position");
        free(ptr);
        return;
    }

    if(ptr == *start) *start = ptr->Link;
    else prev->Link = ptr->Link;
    
    free(ptr);
}

void del_item(struct node **start , int item){
    if(*start == NULL){
        printf("UnderFlow");
        return;
    }

    struct node *ptr = *start;
    struct node *prev = NULL;

    while(ptr != NULL && ptr->Data != item){
        prev = ptr;
        ptr = ptr->Link;
    }

    if(ptr == NULL){
        printf("Invalid item (%d not present in the List).\n",item);
        return;
    }
    
    if(prev == NULL) *start = ptr->Link;
    else prev->Link = ptr->Link;
    free(ptr);
}


int main(){
    struct node *n1, *start = NULL, *ptr;
    int choice, item, pos;
    while (1){
        printf("\n\n1.Display \n2.Count Nodes \n3.Search \n4.Insert At Begining \n5.Inser At Last \n6.Insert At Specific. \n7.Delete the First Node \n8.Delete the End Node \n9.Delete Specific Node \n10.Delete Node By its Data\n11.EXIT\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            travese(start);
            printf("\n");
            break;

        case 2:
            countNodes(start);
            printf("\n");
            break;

        case 3:
            printf("Enetr the value to be Searched : ");
            scanf("%d", &item);
            Search(start, item);
            printf("\n");
            break;

        case 4:
            printf("Enetr the value to Insert at Start : ");
            scanf("%d", &item);
            insert_begining(&start, item);
            printf("\n");
            break;

        case 5:
            printf("Enetr the value to Insert at End : ");
            scanf("%d", &item);
            insert_at_End(&start, item);
            printf("\n");
            break;

        case 6:
            printf("Enetr the position of node to insert : ");
            scanf("%d", &pos);
            printf("\n");
            printf("Enetr the Data to insert in node : ");
            scanf("%d", &item);
            insertSpecific(&start, item, pos);
            printf("\n");
            break;

        case 7:
            del_begining(&start);
            printf("\n");
            break;

        case 8:
            del_end(&start);
            printf("\n");
            break;

        case 9:
            printf("Enetr the position of node : ");
            scanf("%d", &pos);
            del_specific(&start, pos);
            printf("\n");
            break;

        case 10:
            printf("Enetr the Node's Item : ");
            scanf("%d", &item);
            del_item(&start, item);
            printf("\n");
            break;

        case 11:
            exit(0);
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }

    return 0;
}