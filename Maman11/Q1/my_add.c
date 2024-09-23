#include <stdio.h>
#include <stdlib.h>
#define BYTE_SIZE 8

void print_binary(int num) {
    if (num > 1) {
        print_binary(num / 2);  // Recursive call for higher bits
    }
    
    // Print the least significant bit (LSB)
    printf("%d", num % 2);
}

unsigned int my_add(unsigned int a, unsigned int b) {
    unsigned int sum = 0, carry = 0, result = 0, bitA, bitB, i;

    for (i = 0; i < sizeof(unsigned int) * BYTE_SIZE;i++) {
        bitA = (a >> i) & 1;
        bitB = (b >> i) & 1;

        /* Calculate the sum of bits and carry */
        sum = bitA ^ bitB  ^ carry;
        printf("\nbitA: %d, bitB: %d, sum: %d", bitA, bitB, sum);

        /* Update the result with the sum at the current bit position */
        result |= (sum << i);

        /* Calculate the new carry */
        carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);
    }

    return result;
}

int main() {
    unsigned int num1, num2, sum;
    char* binary1, *binary2;
    printf("Enter a number: ");
    scanf("%d", &num1); // Reads an integer from the user

    printf("Enter a second number: ");
    scanf("%d", &num2); // Reads an integer from the user

    printf("\nYou entered : %d and %d\n\n", num1, num2);

    print_binary(num1);
    print_binary(num2);
    sum = my_add(num1, num2);
    printf("\nThe sum of %d and %d is:\n%d in decimal\n", num1, num2, sum);
    print_binary(sum);
    printf("in binary");
    
    
    return 0;
}
