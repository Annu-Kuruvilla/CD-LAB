%{
#include <stdio.h>
#include <string.h>

char name[100];       // Buffer to store the user's name
char first_four[5];  // Buffer for the first four characters
%}

%%
exit    { return 0; }  // Exit the program if the user types "exit"
[a-zA-Z0-9 ]+ {
    if (strstr(yytext, first_four) == NULL) {
        printf("Accepted: %s\n", yytext);
    } else {
        printf("Rejected: %s (contains '%s')\n", yytext, first_four);
    }
}

\n { /* Ignore newline characters */ }

. { /* Ignore any other single characters */ }

%% 

int main() {
    printf("Enter your name: ");
    scanf("%s", name);
    strncpy(first_four, name, 4);
    first_four[4] = '\0';  // Null-terminate the string

    printf("Enter strings (type 'exit' to end):\n");
    while (1) {
        yylex();  // Continuously call yylex to process input
    }
    return 0;
}

int yywrap() {
    return 1;
}

