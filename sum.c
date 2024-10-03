#include<stdio.h>

int main()
{    
     int n , sum = 0;

    printf("no. of elements:");
    scanf("%d",&n);
    int A[n];
   
     printf(" enter  %d numbers :",n);
     for(int i=0 ; i<n ; i++)
        {
            
            scanf("%d", &A[i]);
            sum = sum + A[i];
        
        }
       
    
        printf("sum = %d", sum);


    return 0;
}