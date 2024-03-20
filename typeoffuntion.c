/*
Types of Functions:

Implement a function calculateSquare that takes an integer as a parameter and returns its square.

Implement a recursive function to calculate the factorial of a no.

*/

#include <stdio.h>

int factorial = 1;

int factorialof(int n);
int squarenum(int num);


int main(){
    int num;
    printf("Enetr the number : ");
    scanf("%d",&num);
    
    int Square_result = squarenum(num); 
    printf("\nThe Square of the number is : %d ",Square_result);
    
    int factorial_result = factorialof(num);
    printf("\nThe Factorial of %d is : %d ",num,factorial_result);

    return 0;
}

int squarenum(int num){
    int Square ;
    Square = num*num;
    return Square;
}

int factorialof(int n){
    if(n<1){
        return factorial;
    }
    else{
        factorial = n*factorialof(n-1);
    }
}