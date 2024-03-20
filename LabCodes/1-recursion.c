#include <stdio.h>
#include <string.h>

void str_fx(char *str, int idx, int len, char *r);

int main() {
    char str[] = "Aditya Pandey";
    int len_str = strlen(str);

    char r[len_str + 1];
    r[0] = '\0';

    printf("Current string %s\n", str);

    printf("New String :");

    str_fx(str, 0, len_str, r);
    printf("%s\n", r);

    return 0;
}

void str_fx(char *str, int idx, int len, char *r) {
    // Base Case
    if (idx == len) {  // Change here to handle all characters in the string
        r[idx] = '\0';
        return;
    }

    char c = str[idx];

    if (c == 'a' || c == 'A') {
        r[idx] = '\0';
    } else {
        r[idx] = c;
    }

    // Recursive call
    str_fx(str, idx + 1, len, r);
}
