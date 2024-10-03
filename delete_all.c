#include <stdio.h>

int main() {
    int n , item, index;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("enter number to be deleted\n");
    scanf("%d",&item);
    


    for (int i = 0; i < n; i++)
    {
         if( item != arr[i])
          {  
             printf(" %d\n" , arr[i]);
          }
           
    }
    

    return 0;
}