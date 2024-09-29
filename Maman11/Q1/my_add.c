#include <stdio.h>
#include <stdlib.h>
#define BYTE_SIZE 8

void print_binary(int num) {
    /*
    This function gets a decimal number and prints it's binary value

    param num: The decimal number to be printed
    @return:
    prints the number in binary
    */
    if (num > 1) {
        print_binary(num / 2);  /*Recursive call for higher bits*/ 
    }
    
    /*Print the least significant bit (LSB)*/ 
    printf("%d", num % 2);
}

unsigned int my_add(unsigned int a, unsigned int b) {
    /*
    This function gets two number and calculates their sum in a binary calculation

    param a: The first number to be added
    param b: The second number to be added
    @return: (unsigned int) The binary value of the two numbers  
    */
    unsigned int sum = 0, carry = 0, result = 0, bitA, bitB, i;

    for (i = 0; i < sizeof(unsigned int) * BYTE_SIZE;i++) {
        bitA = (a >> i) & 1;
        bitB = (b >> i) & 1;

        /* Calculate the sum of bits and carry */
        sum = bitA ^ bitB  ^ carry;

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
    //Asking the user for two number for the calculations and reciving it
    printf("Enter a number: ");
    scanf("%u", &num1); 

    printf("Enter a second number: ");
    scanf("%u", &num2); 

    /*printing the input*/
    printf("\nYou entered : %d and %d\n\n", num1, num2);

    print_binary(num1);
    print_binary(num2);
    sum = my_add(num1, num2);
    printf("\nThe sum of %u and %u is:\n%u in decimal\n", num1, num2, sum);
    print_binary(sum);
    printf(" in binary");
    
    
    return 0;
}
