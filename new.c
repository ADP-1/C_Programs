#include <stdio.h>
#include <math.h>
#include <string.h>

void squareroot(float num){
    float root;
    printf("Enter the number : ");
    scanf("%f",&num);

    root = sqrt(num);

    printf("The Sqrt of %f is %.3f .", num , root);
}

// Program to compare two strings

void compstr() {
    char a[100], b[100];

    printf("Enter the first string: ");
    scanf("%99s", a); // Reads up to 99 characters or until a whitespace
    printf("\nEnter the second string: ");
    scanf("%99s", b); // Reads up to 99 characters or until a whitespace

    if(strcmp(a, b) == 0){
        printf("\nStrings are Equal.\n");
    }
    else{
        printf("Strings are different.\n");
    }
}

int main() {
    compstr();
    return 0;
}