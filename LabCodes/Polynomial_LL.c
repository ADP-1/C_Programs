#include <stdio.h>
#include <stdlib.h>

struct node{
    int Coefficient;
    int Power;
    struct node *link;
};

struct node *Create_Node(){
    return (struct node *)malloc(sizeof(struct node));
}

void traverse(struct node *poly){
    struct node *ptr = poly;
    while (ptr != NULL)
    {
        printf("[%d,%d]->", ptr->Coefficient, ptr->Power);

        ptr = ptr->link;
    }
    printf("Null\n");
}

void CountNode(struct node *poly){
    struct node *ptr = poly;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }

    printf("No. of Nodes : %d", count-1);
}

void insert_begining(struct node **poly, int coeff_value, int power_value){
    struct node *n1 = Create_Node();
    n1->Coefficient = coeff_value;
    n1->Power = power_value;
    n1->link = (*poly)->link;
    (*poly)->link = n1;
    (*poly)->Coefficient++;
    if ((*poly)->Power < power_value) (*poly)->Power = power_value;
}

void insert_end(struct node **poly, int coeff_value, int power_value){
    struct node *n1 = Create_Node();
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    n1->Coefficient = coeff_value;
    n1->Power = power_value;

    if((*poly)->Coefficient == 0){
        (*poly)->link = n1;
        (*poly)->Coefficient++;
    }

    if ((*poly)->Power < power_value) (*poly)->Power = power_value;
    
    else{
        struct node *ptr;
        ptr = *poly;

        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = n1;
    }
}

void insertSpecific(struct node **poly , int coeff_value , int power_value , int pos){
    struct node *n1 = Create_Node();
    if (n1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    n1->Coefficient = coeff_value;
    n1->Power = power_value;
    
    if(pos == 0){
        n1->link = (*poly)->link;
        (*poly)->link = n1;
        (*poly)->Coefficient++;
    }
    
    else{
        struct node *ptr;
        ptr = *poly;
        int currentPos = 0;

        while(ptr!= NULL && currentPos != pos-1){
            ptr = ptr->link;
            currentPos++;
        }
        if (ptr == NULL) {
            printf("Invalid position for insertion.\n");
            free(n1);                                    // Release the allocated memory
            return;
        }
        n1->link = ptr->link;
        ptr->link = n1;
    }

    if ((*poly)->Power < power_value) (*poly)->Power = power_value;

}

void del_begining(struct node **poly){
    if((*poly)->link == NULL){
        printf("UnderFlow");
        return;
    }

    struct node *ptr;
    ptr = *poly;
    *poly = (*poly)->link;
    free(ptr);
}

void cleanup(struct node *poly) {
    struct node *current = poly;
    struct node *next;

    while (current != NULL) {
        next = current->link;
        free(current);
        current = next;
    }
}

int main(){
    struct node *poly = Create_Node();
    poly->Coefficient = 0; // poly coefficiet will contain no of nodes.
    poly->Power = 0;       // poly Power will contain Maximum Power.
    poly->link = NULL;

    int choice, coeff_value, power_value;
    while (1){
        printf("\n\n1.Display \n2.Count Nodes \n3.Insert At Begining \n4.Exit The program\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            traverse(poly);
            printf("\n");
            break;

        case 2:
            CountNode(poly);
            printf("\n");
            break;

        case 3:
            printf("Enetr the Coefficient Value : ");
            scanf("%d", &coeff_value);
            printf("Enetr the power Value : ");
            scanf("%d", &power_value);
            insert_begining(&poly, coeff_value, power_value);
            printf("\n");
            break;
        case 4:
            cleanup(poly);                                     // Free memory before exiting
            exit(0);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }
    return 0;
}
