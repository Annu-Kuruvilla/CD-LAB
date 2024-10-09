%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

void yyerror(const char *s);
int yylex(void);
%}

%union {
    int intval;
    struct ASTNode *node;
}

%token <intval> NUMBER
%type <node> expression term factor

%% 

expression:
    term { $$ = $1; }
    | expression '+' term { $$ = create_binop('+', $1, $3); }
    ;

term:
    factor { $$ = $1; }
    | term '*' factor { $$ = create_binop('*', $1, $3); }
    ;

factor:
    '(' expression ')' { $$ = $2; }
    | NUMBER { $$ = create_number($1); }
    ;

%% 

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    struct ASTNode *ast = parse();
    // Here you would normally traverse and utilize the AST
    return 0;
}

