#include <stdio.h>
#include <stdlib.h>

int fibo(int num){
    if (num == 0) return 0;
    else if (num == 1) return 1;
    else return(fibo(num - 1) + fibo(num - 2));
}

int main(){
    int n = 6;
    int result = fibo(n-1);
    printf("%d",result);
    return 0;  
}