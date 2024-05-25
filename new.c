#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 9 


void fizzBuzz(int n, char result[][MAX_STRING_LENGTH]) {
    for (int i = 1; i <= n; ++i) {
        char s[MAX_STRING_LENGTH] = ""; 
        
        if (i % 3 == 0)
            strcat(s, "Fizz");
        if (i % 5 == 0)
            strcat(s, "Buzz");
        
        if (strlen(s) == 0) {
            sprintf(s, "%d", i); 
        }
        
        strcpy(result[i - 1], s); 
    }
}

int main() {
    int n = 15;
    char result[15][MAX_STRING_LENGTH];

    fizzBuzz(n, result);
    

    for (int i = 0; i < n; ++i) {
        printf("%s\n", result[i]);
    }

    return 0;
}
