#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

char *exp;
int pos = 0;

struct TreeNode* createNode(char ch) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->data = ch;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* parseExpression() {
    struct TreeNode *left = createNode(exp[pos++]);

    while (exp[pos] == '+' || exp[pos] == '-') {
        char op = exp[pos++];
        struct TreeNode *right = createNode(exp[pos++]);
        struct TreeNode *node = createNode(op);

        node->left = left;
        node->right = right;
        left = node;
    }

    return left;
}

void printTree(struct TreeNode *root, int level) {
    if (root == NULL)
        return;

    printTree(root->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("    ");

    printf("%c\n", root->data);

    printTree(root->left, level + 1);
}

int main() {
    printf("Enter arithmetic expression: ");
    char expression[100];
    scanf("%99s", expression);

    exp = expression;
    pos = 0;

    struct TreeNode *root = parseExpression();

    printf("\nParse Tree:\n");
    printTree(root, 0);

    return 0;
}