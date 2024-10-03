#include<stdio.h>
#include<math.h>

int main()
{    
     int n, sum=0;
     float mean;   
    printf("no. of elements:");
    scanf("%d",&n);
    int arr[n];

     printf(" enter  %d numbers :",n);
     for(int i=0 ; i<n ; i++)
        {
            
            scanf("%d", &arr[i]);
            sum = sum + arr[i];
        
        }
        mean = (float)sum/n;

        //int term1, term2,
        int sum2 = 0;

        for(int i= 0 ; i < n ;i++)
        {
         
         int term1 = arr[i] - mean ;
         int term2 = term1 * term1;
         sum2 = sum2 + term2;

        }

       float variance;
       variance = sum2/n;
       printf(" variance = %f",variance);

       float sd;
       sd = sqrt(variance);
       printf(" standard deviation = %f",sd);


    return 0;
}