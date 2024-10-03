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
       
        float average ;
        average = sum/n;
        printf("Average = %f", average);


    return 0;
}