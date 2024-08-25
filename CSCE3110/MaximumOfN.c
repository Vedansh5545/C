#include <stdlib.h>
#include <stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int maxOfN(int *arr, int n){
    if(n == 1){
        return arr[0];
    }
    return max(arr[n-1], maxOfN(arr, n-1));
}

int main(){
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("The maximum element is: %d\n", maxOfN(arr, n));
    free(arr);
    return 0;
}