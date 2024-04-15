#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Import the stack implementation
#include "DMAStack.c"

void reverse(struct node **top , char *str);

int main() {
    printf("Enter the size of the stack: ");
    scanf("%d", &MAX);

    struct node *top = createNode();
    top->data = 0;
    top->link = NULL;

    char str[MAX];
    
    printf("Enter a string: ");
    scanf("%s", &str);

    reverse(&top , str);

    return 0;
}

void reverse(struct node **top , char *str) {

    for (int i = 0; i < strlen(str); i++) {
        push(top, str[i]);
    }

    printf("Reversed string: ");
    while (isEmpty(*top)!=1) {
        printf("%c", pop(top));
    }
}