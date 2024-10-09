#ifndef AST_H
#define AST_H

struct ASTNode {
    enum { NODE_NUMBER, NODE_BINOP } type;
    union {
        int intval; // For numbers
        struct {
            char op; // Operator
            struct ASTNode *left;
            struct ASTNode *right;
        } binop; // For binary operations
    };
};

struct ASTNode *create_number(int value);
struct ASTNode *create_binop(char op, struct ASTNode *left, struct ASTNode *right);

#endif

