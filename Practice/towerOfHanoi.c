#include <stdio.h>

void TOH(int n , char from , char to , char help){
    if (n==0) return;
    TOH(n-1,from , help , to);
    printf("Move %d from %c -> %c\n",n,from , to);
    TOH(n-1 , help , to , from);
}

int main() {
    int N = 3;
    TOH(N, 'A', 'C', 'B');
    return 0;
}