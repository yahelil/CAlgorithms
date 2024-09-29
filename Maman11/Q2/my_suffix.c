#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LENGTH 128


int suffix(char str[], char c){
    /*
    This function finds suffix in a string
    When the function finds the suffix it prints it and counts it

    The function iterates over the string using a while loop.

    param str: (char[]) the string to iterate over
    param c: (char) the char that start the suffix.

    @return: (int) the number of suffix in the string.
    if a suffix is found the program prints it.
    */
    int counter = 0;
    char* currentchar;
    for (currentchar = str; currentchar != '\0'; currentchar++){
        if (*currentchar == 'c'){
            printf("%s\n", currentchar);
            counter += 1;
        }
    }
    return counter;
}

int main()
{
    char c, str[STRING_LENGTH];
    int number_of_suffix;
    /*Asking the user for a character that starts the suffix and reciving it*/
    printf("Enter a char: ");
    scanf(" %c", &c);
    /*Asking the user for a string to find suffix in it and reciving it*/
    printf("Enter a string: ");
    scanf("%s", &str);

    /* printing the input from the user*/
    printf("The character is %c and the string is %s\n", c, str); 
    number_of_suffix = suffix(str, c);
    printf("Number of suffixes in the string is %d\n", number_of_suffix);
    return 0;
}


