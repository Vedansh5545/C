/*
In this recitation assignment, will write a complete C program (rec01_LastName_FirstName.c) that will prompt the user to enter an ASCII printable character and then print out its decimal (base 10), hexadecimal (base 16) and all 8 binary digits of its binary (base 2) representation.

You may assume that the user enters a valid ASCII printable character when prompted. Examples of printable characters include A, B, C, #, $, &, +, 0, 1, 2, <, a, b, c, and so forth, and they typically range in decimal value from 33 to 126. You do not have to do any error checking for non-printable characters.
*/

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
void ConvertTo8Bit(long long num){
    int binaryNum[8];
    for(int i = 0; i < 8; i++){
        binaryNum[i] = num % 10;
        num /= 10;
    }
    for(int i = 7; i >= 0; i--){
        printf("%d", binaryNum[i]);
    }
    printf("\n");
}
int main(){
    char c;
    printf("Enter an ASCII printable character: ");
    scanf("%c", &c);
    printf("Decimal: %d\n", c);
    printf("Hexadecimal: %x\n", c);
    printf("Binary: ");
    ConvertTo8Bit(ConvertToBinary(c));
}

