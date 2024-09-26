#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define STRING_LENGTH 127

int suffix(char str[], char c){
    bool read = false;
    int suffix = 0, len = strlen(str), i = 0;
    while (str[i]){
        if (c == str[i]){
            read = true;
        }
        if (read){
            print_ending(&str[i]);
            read = false;
            suffix += 1;

        }

        i++;
    }
    return suffix;
}

void print_ending(char str[]){
    printf("%s\n", str);
}

int main()
{
    char c;
    char str[STRING_LENGTH];
    int num;
    printf("Enter a char: ");
    scanf(" %c", &c);
    printf("Enter a string: ");
    scanf("%s", &str);
    printf("The character is %c and the string is %s\n", c, str);
    num = suffix(str, c);
    printf("Number of suffixes in the string is %d\n", num);
    return 0;
}


