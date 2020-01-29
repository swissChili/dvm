%{
  #include <stdlib.h>
  #include "parser.h"

  extern char error_text[1024];
  int yyerror(const char *);
%}

%option noyywrap
%option yylineno

sigil [\$@%]
ident [a-zA-Z_\-\.]+
num   [0-9]+(\.[0-9]+)?

%%

[ \t\r\n] // skip
;[^\n]*\n // skip
{sigil} { yylval.sigil = *yytext; return T_SIGIL; }
{num} { yylval.number = strtof(yytext, NULL); return T_NUMBER; }
push { return T_PUSH; }
pop { return T_POP; }
{ident} { yylval.text = strdup(yytext); return T_IDENT; }
. {
    sprintf(error_text, "unexpected token '%s'", yytext);
    yyerror(error_text);
  }
