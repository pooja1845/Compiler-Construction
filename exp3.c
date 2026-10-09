#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[500], word[50];
    char *keywords[] = {
        "int", "float", "char", "double", "if",
        "else", "for", "while", "return", "void"
    };

    int i = 0, j, found;

    printf("Enter C source code:\n");
    fgets(str, sizeof(str), stdin);

    printf("\n--- Lexical Analysis ---\n");

    while (str[i] != '\0') {

        if (isspace(str[i])) {
            i++;
        }

        else if (isalpha(str[i]) || str[i] == '_') {
            j = 0;

            while (isalnum(str[i]) || str[i] == '_') {
                word[j++] = str[i++];
            }

            word[j] = '\0';
            found = 0;

            for (j = 0; j < 10; j++) {
                if (strcmp(word, keywords[j]) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("%s -> KEYWORD\n", word);
            else
                printf("%s -> IDENTIFIER\n", word);
        }

        else if (isdigit(str[i])) {
            printf("%c -> NUMBER\n", str[i]);
            i++;
        }

        else if (strchr("+-*/%=<>!", str[i])) {
            printf("%c -> OPERATOR\n", str[i]);
            i++;
        }

        else {
            printf("%c -> SPECIAL SYMBOL\n", str[i]);
            i++;
        }
    }

    return 0;
}