#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int count = 0;
    
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if( arr[i] % 2 == 0)
          {
              count++;
          }
           
    }
    
    printf("count = %d\n",count);

    printf(" even numbers are :\n");
    for (int i = 0; i < n; i++)
    {
        if( arr[i] % 2 == 0)
          {
              printf(" %d\n", arr[i]);
          }
           
    }
    

    return 0;
}