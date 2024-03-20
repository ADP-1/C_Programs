#include <stdio.h>
#include <string.h>

//                                     --------------------REVERSE STRING--------------------
/*  
void reverseString(char ch[] ,int start,int end ){
    if(start >= end){
        return ;
    }

    char temp = ch[start];
    ch[start] = ch[end];
    ch[end] = temp;

    reverse(ch, start + 1, end - 1);
}



int main(){
    char str[100];
    printf("Enetr the string : ");
    scanf("%s", &str);

    int end = strlen(str) - 1;
    reverseString(str, 0, end);
    printf("%s", str);
    return 0;
}
*/

//                                     --------------------REVERSE ARRAY--------------------

/*
void reverseArray(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start + 1, end - 1);
}

int main()
{
    int ar[10] = {10, 20, 30, 40};
    int size = sizeof(ar) / sizeof(ar[0]);

    printf("Original array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", ar[i]);
    }

    reverseArray(ar, 0, size - 1);

    printf("\nReversed array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", ar[i]);
    }
    return 0;
}

*/

//                                --------------------INSERT ELEMENT IN ARRAY--------------------

void insertElement(int arr[], int *size, int element, int position){
  int x =  *size;

  while(x >= position){
    arr[x+1] = arr[x];
    x -= 1;
  }
  arr[position] = element;
  *size +=1;
}

void printReverseString(const char c[] ,int idx){
    if(c[idx] == '\0'){
        return;
    }

    printReverseString(c ,idx+1);

    printf("%c",c[idx]);
}

int sumArray(const int arr[], int size, int index) {
    if (index >= size) {
        return 0;  // Base case: end of the array
    }

    // Recursive call to sum the rest of the array elements
    return arr[index] + sumArray(arr, size, index + 1);
}
