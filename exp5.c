#include <stdio.h>
#include <string.h>

int main() {
    char expression[100];

    printf("Enter expression: ");
    fgets(expression, sizeof(expression), stdin);

    if (strstr(expression, "* 2") != NULL) {
        printf("Optimized Expression: x = x + x\n");
    } else {
        printf("No strength reduction applicable.\n");
    }

    return 0;
}