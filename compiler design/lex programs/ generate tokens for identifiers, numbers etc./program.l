%{
#include <stdio.h>
%}

%%
[ \t\n]+                  { /* Skip whitespace */ }
[a-zA-Z_][a-zA-Z0-9_]*   { printf("Identifier: %s\n", yytext); }
[0-9]+                    { printf("Number: %s\n", yytext); }
"=="                      { printf("Operator: %s\n", yytext); }
"!="                      { printf("Operator: %s\n", yytext); }
"<="                      { printf("Operator: %s\n", yytext); }
">="                      { printf("Operator: %s\n", yytext); }
"&&"                      { printf("Operator: %s\n", yytext); }
"||"                      { printf("Operator: %s\n", yytext); }
[;:(),]                   { printf("Punctuation: %s\n", yytext); }
[-+*/%]                   { printf("Operator: %s\n", yytext); }
.                         { printf("Unknown: %s\n", yytext); }

%%

int main() {
    yylex(); // Call the scanner function
    return 0;
}
