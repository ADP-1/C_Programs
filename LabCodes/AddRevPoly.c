/*
you are given a known empty linked list representing  2 non-negative  integers 
the digits are stored in revered order and each of the noe contains a sample digit.
write a function to add these two nodes and return a sum of those linked list 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int Digit;
    struct Node *next;
};

struct Node *Create_Node(){
    return (struct Node *)malloc(sizeof(struct Node));
}

void insertTerm(struct Node **poly, int value){
    struct Node *newNode = Create_Node();
    newNode->Digit = value;
    newNode->next = *poly;
    *poly = newNode;
}

void displayPolynomial(struct Node *poly){
    struct Node *temp = poly;
    while (temp != NULL)
    {
        printf("%d->", temp->Digit);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2){
    struct Node *result = NULL;
    struct Node *temp1 = poly1;
    struct Node *temp2 = poly2;
    int extra = 0;

    while (temp1 != NULL || temp2 != NULL || extra != 0){
        int val1 = (temp1 != NULL) ? temp1->Digit : 0;
        int val2 = (temp2 != NULL) ? temp2->Digit : 0;

        int sum = val1 + val2 + extra;
        extra = sum / 10;
        int digit = sum % 10;

        insertTerm(&result, digit);

        if (temp1 != NULL){
            temp1 = temp1->next;
        }

        if (temp2 != NULL){
            temp2 = temp2->next;
        }
    }

    return result;
}

void cleanup(struct Node *poly){
    struct Node *current = poly;
    struct Node *next;

    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enter Number 1\n");
        printf("2. Enter Number 2\n");
        printf("3. Display Number 1\n");
        printf("4. Display Number 2\n");
        printf("5. Add Numbers\n");
        printf("6. Display Result\n");
        printf("7. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int number;
                printf("Enter the whole number for Number 1: ");
                scanf("%d", &number);

                while (number > 0) {
                    int digit = number % 10;
                    insertTerm(&poly1, digit);
                    number /= 10;
                }
                break;
            }

            case 2: {
                int number;
                printf("Enter the whole number for Number 2: ");
                scanf("%d", &number);

                while (number > 0) {
                    int digit = number % 10;
                    insertTerm(&poly2, digit);
                    number /= 10;
                }
                break;
            }

            case 3:
                printf("Number 1: ");
                displayPolynomial(poly1);
                break;

            case 4:
                printf("Number 2: ");
                displayPolynomial(poly2);
                break;

            case 5:
                result = addPolynomials(poly1, poly2);
                printf("Numbers Added.\n");
                break;

            case 6:
                printf("Result: ");
                displayPolynomial(result);
                break;

            case 7:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 7);

    cleanup(poly1);
    cleanup(poly2);
    cleanup(result);

    return 0;
}
