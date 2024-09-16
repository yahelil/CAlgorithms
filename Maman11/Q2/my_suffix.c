#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int suffix(char str[], char c){
    char ending[126] = "";
    bool read = false;
    int added_char = 0;
    int len = strlen(str);
    int i = 0;
    while (str[i]){
        if (read){
            strncat(ending, &str[i], 1);
            added_char += 1;
        }
        if (c == str[i]){
            read = true;
            printf("%s\n", &str[i]);
            strcpy(ending, "");  // Reset ending
            added_char = 0;
        }
        i++;
    }
    return added_char;

}
int main()
{
    char c;
    char str[126];
    int num;
    printf("Enter a char: ");
    scanf(" %c", &c);
    printf("Enter a string: ");
    scanf("%s", &str);
    printf("The character is %c and the string is %s", c, str);
    num = suffix(str, c);
    printf("Number of characters in the suffix: %d\n", num);
    return 0;
}


