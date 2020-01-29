%{
  #include <stdlib.h>
  #include "parser.h"
%}

%option noyywrap

sigil [\$@%]
ident [a-zA-Z_\-\.]+
num   [0-9]+\.[0-9]+

%%

[ \t\r\n] // skip
;[^\n]\n // skip
{sigil} { yylval.sigil = *yytext; return T_SIGIL; }
{num} { yylval.number = strtof(yytext, NULL); return T_NUMBER; }
push { return T_PUSH; }
pop { return T_POP; }
{ident} { yylval.text = strdup(yytext); return T_IDENT; }
