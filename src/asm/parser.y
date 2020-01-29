%{
  #include <stdlib.h>
  #include <stdio.h>

  int yylex();
  extern int yylineno;
  int yyerror(const char *bruh)
  {
    fprintf(stderr, "\033[31mError near line %d:\033[0m %s\n", yylineno, bruh);
    exit(1);
  }

  char error_text[1024] = { 0 };
%}

%union {
  double number;
  char sigil;
  char *text;
}

%token <number> T_NUMBER
%token <sigil> T_SIGIL
%token <text> T_IDENT
%token T_PUSH
%token T_POP

%%

program:
  %empty
  | program instruction
  {
    //
  }

instruction:
  T_PUSH T_NUMBER
  {
    printf("push %f\n", $2);
  }
  | T_POP T_SIGIL T_IDENT
  {
    switch ($2)
    {
      case '$':
        printf("$%s = pop\n", $3);
        break;
    }
  }
  | T_IDENT
  {
    sprintf(error_text, "'%s' not defined", $1);
    yyerror(error_text);
  }

%%

int main(int argc, char **argv)
{
  yyparse();
}
