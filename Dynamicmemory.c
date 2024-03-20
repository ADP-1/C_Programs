/*Problem 1:

Write a function that allocates memory for an array of integers of the specified size. 
The function should return a pointer to the allocated memory.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

   int size;

   printf("Enter teh size of the array : \n");
   scanf("%d",&size);

   int *arrayptr = (int*)malloc(size*sizeof(int));

   printf("\nEnter %d elements:", size);
   
   for (int i = 0; i < size; i++){
    printf("\nEnetr the %d index valaue : ",i);
    scanf("%d", &arrayptr[i]);
   }

   for (int i = 0; i < size ; i++){
    printf("\nArray element of array[%d] is : %d ", i , arrayptr[i]);
   }
     

   int sum = 0;
   for (int i = 0; i < size ; i++){
    sum += arrayptr[i];
   }

   printf("\nSum of elements: %d\n", sum);

   free(arrayptr);

   return 0;
}

