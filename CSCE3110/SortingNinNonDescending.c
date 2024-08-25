#include <stdlib.h>
#include <stdio.h>

int bigger(int a, int b){
    return a > b ? a : b;
}

void sort(int *arr, int n){
    if(n == 1){
        return;
    }
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    sort(arr, n-1);
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
    sort(arr, n);
    printf("The elements in non-descending order are: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
