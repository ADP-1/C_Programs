#include <stdio.h>

int fibSeries(int n){
    if (n <= 1) return n;

    return fibSeries(n - 1) + fibSeries(n - 2);
}

int main(){
    int n ;
    printf("Enter the nth place : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        printf("%d ", fibSeries(i));
    }   

    return 0;
}