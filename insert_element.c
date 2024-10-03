#include <stdio.h>
int n;
void scan_array(int arr[] ,int  n)
{
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
void insert(int arr[], int item, int index){
    for (int i = n ; i > index; i--)
    {
        arr[i] = arr[i - 1];      
    }
    arr[index + 1] = item;
    n = n+1;
}
void display_array( int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
          {  
             printf("  %d\n" , arr[i]);
          }
           
    }
}
int main() {
    int  item, index ,element;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
     int arr[n];
    
    printf("Enter %d elements: \n", n);

    scan_array(arr,n);

    printf("enter number after which you want to insert\n");
    scanf("%d",&element);

    for (int i = 0; i < n; i++)
    {
        if( arr[i]  == element)
          {
              index = i;
              break;
          }
    }
     printf("enter number you want to insert\n");
    scanf("%d",&item);

    insert( arr,item,index);
    
    
    display_array( arr ,n);

    
    

    return 0;
}