#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int power;
    struct Node* next;
};

struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->power = pow;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayPolynomial(struct Node* poly) {
    struct Node* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->power);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->power == temp2->power) {
            insertTerm(&result, temp1->coefficient + temp2->coefficient, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->power > temp2->power) {
            insertTerm(&result, temp1->coefficient, temp1->power);
            temp1 = temp1->next;
        } else {
            insertTerm(&result, temp2->coefficient, temp2->power);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insertTerm(&result, temp1->coefficient, temp1->power);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertTerm(&result, temp2->coefficient, temp2->power);
        temp2 = temp2->next;
    }

    return result;
}

void cleanup(struct Node* poly) {
    struct Node* current = poly;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    int choice;
    do {
        printf("\nPolynomial Menu:\n");
        printf("1. Enter Polynomial 1\n");
        printf("2. Enter Polynomial 2\n");
        printf("3. Display Polynomial 1\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Add Polynomials\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int coeff, power;
                printf("Enter the coefficient and power for Polynomial 1 (Enter -1 -1 to stop):\n");
                while (1) {
                    scanf("%d %d", &coeff, &power);
                    if (coeff == -1 && power == -1) {
                        break;
                    }
                    insertTerm(&poly1, coeff, power);
                }
                break;
            }

            case 2: {
                int coeff, power;
                printf("Enter the coefficient and power for Polynomial 2 (Enter -1 -1 to stop):\n");
                while (1) {
                    scanf("%d %d", &coeff, &power);
                    if (coeff == -1 && power == -1) {
                        break;
                    }
                    insertTerm(&poly2, coeff, power);
                }
                break;
            }

            case 3:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                break;

            case 4:
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                break;

            case 5: {
                struct Node* result = addPolynomials(poly1, poly2);
                printf("Sum of Polynomials: ");
                displayPolynomial(result);
                cleanup(result);
                break;
            }

            case 6:
                cleanup(poly1);
                cleanup(poly2);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
