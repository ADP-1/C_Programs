// this is Header Liked list program in which Header contains [data | link] , where Data = No. of Nodes Present and link As next Node.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int Data;
    struct node *Link;
};

struct node *Create_Node(){
    return (struct node*)malloc(sizeof(struct node));
}

void traverse(struct node *Header) {

  struct node *ptr;
  ptr = Header;
  while (ptr != NULL) {
    printf("%d -> ", ptr->Data);
    ptr = ptr->Link;
  }
  printf("NULL\n");
}

void countNodes(struct node *Header) {
  int count = 0;
  struct node *ptr;
  ptr = Header;
  while (ptr != NULL) {
    count++;
    ptr = ptr->Link;
  }
  printf("The no of Nodes : %d",count-1);
}

void Search(struct node *Header, int Item){
    int count = 1;
    struct node *ptr;
    ptr = Header;
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

void insert_begining(struct node **Header, int value){
    struct node *newNode = Create_Node();
    newNode->Data = value;
    newNode->Link = (*Header)->Link;
    (*Header)->Link = newNode;
    (*Header)->Data++;
}

void insert_at_End(struct node **Header, int item){
    struct node *n1 = Create_Node();
    
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n1->Data = item;
    n1->Link = NULL;

    if((*Header)->Data == 0){
        (*Header)->Link = n1;
        (*Header)->Data++;
    }
    else{
        struct node *ptr;
        ptr = *Header;

        while(ptr->Link != NULL){
            ptr = ptr->Link;
        }
        ptr->Link = n1;
    }
}

void insertSpecific(struct node **Header , int item , int pos){
    struct node *n1 = Create_Node();
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    n1->Data = item;
    n1->Link = NULL;
    
    if(pos == 0){
        n1->Link = (*Header)->Link;
        (*Header)->Link = n1;
        (*Header)->Data++;
    }
    else{
        struct node *ptr;
        ptr = *Header;
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

void del_begining(struct node **Header){
    if((*Header)->Link == NULL){
        printf("UnderFlow");
        return;
    }

    struct node *ptr;
    ptr = *Header;
    *Header = (*Header)->Link;
    free(ptr);
}

void del_end(struct node **Header){
    
    if(*Header == NULL){
        printf("UnderFlow");
        return;
    }
    
    struct node *ptr = *Header;
    struct node *pptr = NULL;

    while (ptr->Link != NULL){
        pptr = ptr;
        ptr = ptr->Link;
    }

    if(ptr == *Header){
        (*Header)->Link = NULL;
    }

//  Remove the last node from the list
    else{
        pptr->Link = NULL;
    }
    
//  Free the memory of deleted node.
    free(ptr);
}

void del_specific(struct node **Header , int pos){
    if(*Header == NULL){
        printf("UnderFlow");
        return;
    }
    int counter = 0;
    struct node *ptr = *Header;
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

    if(ptr == *Header) *Header = ptr->Link;
    else prev->Link = ptr->Link;
    
    free(ptr);
}

void del_item(struct node **Header , int item){
    if(*Header == NULL){
        printf("UnderFlow");
        return;
    }

    struct node *ptr = *Header;
    struct node *prev = NULL;

    while(ptr != NULL && ptr->Data != item){
        prev = ptr;
        ptr = ptr->Link;
    }

    if(ptr == NULL){
        printf("Invalid item (%d not present in the List).\n",item);
        return;
    }
    
    if(prev == NULL) *Header = ptr->Link;
    else prev->Link = ptr->Link;
    free(ptr);
}

int main(){
    struct node *Header = Create_Node();
    Header->Data = 0;
    Header->Link = NULL;

    int choice, item, pos;
    while (1){
        printf("\n\n1.Display \n2.Count Nodes \n3.Search \n4.Insert At Begining \n5.Inser At Last \n6.Insert At Specific. \n7.Delete the First Node \n8.Delete the End Node \n9.Delete Specific Node \n10.Delete Node By its Data\n11.EXIT\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            traverse(Header);
            printf("\n");
            break;

        case 2:
            countNodes(Header);
            printf("\n");
            break;

        case 3:
            printf("Enetr the value to be Searched : ");
            scanf("%d", &item);
            Search(Header, item);
            printf("\n");
            break;

        case 4:
            printf("Enetr the value to Insert at Header : ");
            scanf("%d", &item);
            insert_begining(&Header, item);
            printf("\n");
            break;

        case 5:
            printf("Enetr the value to Insert at End : ");
            scanf("%d", &item);
            insert_at_End(&Header, item);
            printf("\n");
            break;

        case 6:
            printf("Enetr the position of node to insert : ");
            scanf("%d", &pos);
            printf("\n");
            printf("Enetr the Data to insert in node : ");
            scanf("%d", &item);
            insertSpecific(&Header, item, pos);
            printf("\n");
            break;

        case 7:
            del_begining(&Header);
            printf("\n");
            break;

        case 8:
            del_end(&Header);
            printf("\n");
            break;

        case 9:
            printf("Enetr the position of node : ");
            scanf("%d", &pos);
            del_specific(&Header, pos);
            printf("\n");
            break;

        case 10:
            printf("Enetr the Node's Item : ");
            scanf("%d", &item);
            del_item(&Header, item);
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