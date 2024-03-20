#include <stdio.h>

void PrintArray( int *a , int n){
    printf("The array is as following : \n"); 
    for(int i = 0 ; i < n ; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void swap(int *x, int *y) {
    if (x != y) {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

int bubblesort( int *a , int n){
    printf("Running Bubble Sort.............\n");
    int i , j ;
    
    for( i = 0 ; i < n-1 ; i++){
        for( j = 0 ; j < n-1-i ; j++){
            if(a[j]>a[j+1]){
                swap( &a[j] , &a[j+1] );
            }
        }
    }
}

void selectionsort(int *a, int n)
{
    printf("Running Selection Sort.............\n");
    int i , j , min;
    for ( i = 0; i < n -1 ; i++){
        min = i;
        for( j = i+1 ; j < n ; j++ ){
            if(a[min]>a[j]){
                min = j;
            }
        }
        swap( &a[i] , &a[min]);
    }
}

int main(){
    int n;

    printf("Enter the number of elements to insert : ");
    scanf("%d",&n);

    int a[n];

    for (int i = 0 ; i < n ; i++){
        printf("Enter the %d no. element : ", i+1);
        scanf("%d",&a[i]);
    }

    PrintArray( a , n);                 // Array before Sorting
    selectionsort( a , n);                 // Sorting fx.   
    PrintArray( a , n);                 // Array after Sorting.
    return 0;
}