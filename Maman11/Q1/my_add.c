#include <stdio.h>
#include <stdlib.h>
#define BYTE_SIZE 33

char* decimalToBinary(int num){
    int result = num;
    char binary[BYTE_SIZE];
    int index = 0;

    while (result > 0) {
        int i = result % 2;
        binary[index++] = i + '0';
        result /= 2;
    }

    binary[index] = '\0';

    // Reverse the string
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = binary[start];
        binary[start] = binary[end];
        binary[end] = temp;
        start++;
        end--;
    }

    
    return binary;
}
void print_binary(char* binary){
    printf("Binary representation: %s\n", binary);
}
unsigned int my_add(unsigned int a, unsigned int b) {
    int carry = 0;
    int result = 0;
    int index = 0;
    int place = 1;

    while (a > 0 || b > 0 || carry > 0) {
        int unit1 = a % 10;
        int unit2 = b % 10;

        int sum = unit1 + unit2 + carry;
        carry = sum / 2;
        sum = sum % 2;

        result += (sum * place);

        a = a / 10;
        b = b / 10;
        place = place * 10;
    }

    return result;
}

int main() {
    int num1, num2, binary1, binary2;
    printf("Enter a number: ");
    scanf("%d", &num1); // Reads an integer from the user

    printf("Enter a second number: ");
    scanf("%d", &num2); // Reads an integer from the user

    printf("\nYou entered : %d and %d\n\n", num1, num2);

    binary1 = decimalToBinary(num1);
    binary2 = decimalToBinary(num2);
    printf("\nThe sum of %d and %d is: %d or %d in decimal\n", num1, num2, addBinary(binary1, binary2), num1 + num2);
    return 0;
}
