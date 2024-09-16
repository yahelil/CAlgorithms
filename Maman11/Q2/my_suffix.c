#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int suffix(char str[], char c){
    char ending[127] = "";
    bool read = false;
    int added_char = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++){
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
    }
    return added_char;

}
int main()
{
    char c;
    char str[127];
    int num;
    printf("Enter a char: ");
    scanf(" %c", &c);
    printf("Enter a string: ");
    scanf("%s", &str);

    num = suffix(str, c);
    printf("Number of characters in the suffix: %d\n", num);
    return 0;
}


