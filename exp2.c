#include <stdio.h>
#include <string.h>

int main() {
    char *program[] = {
        "START MACRO",
        "MOV A, B",
        "ADD A, C",
        "MEND",
        "DISPLAY MACRO",
        "MOV R1, R2",
        "END",
        "END"
    };

    int i;
    printf("MACRO definition identified:\n");
    printf("----------------------------\n");

    for (int i = 0; strcmp(program[i], "END") != 0; i++) {
        if (strstr(program[i], "MACRO")) {
            printf("%s\n", program[i]);
        }
    }

    return 0;
}