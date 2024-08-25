#include <stdio.h>
#include <stdlib.h>

long long ConvertToBinary(int n){
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n != 0){
        remainder = n % 2;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

int main(){
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Binary Number: %lld\n", ConvertToBinary(n));
}