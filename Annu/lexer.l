%{
#include "y.tab.h"
%}

%% 

[0-9]+    { yylval.intval = atoi(yytext); return NUMBER; }
[+\-*]    { return yytext[0]; }
[()]      { return yytext[0]; }
[ \t\n]   { /* ignore whitespace */ }
.         { yyerror("Unexpected character"); }

%% 

