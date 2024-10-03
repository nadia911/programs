#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int product = 1;

    
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        product *= arr[i];
        product = product * arr[i];

    }

    
    printf("The product of the entered numbers is: %d\n", product);

    return 0;
}