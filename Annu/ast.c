#include <stdlib.h>
#include "ast.h"

struct ASTNode *create_number(int value) {
    struct ASTNode *node = malloc(sizeof(struct ASTNode));
    node->type = NODE_NUMBER;
    node->intval = value;
    return node;
}

struct ASTNode *create_binop(char op, struct ASTNode *left, struct ASTNode *right) {
    struct ASTNode *node = malloc(sizeof(struct ASTNode));
    node->type = NODE_BINOP;
    node->binop.op = op;
    node->binop.left = left;
    node->binop.right = right;
    return node;
}

