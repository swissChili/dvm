%{
  #include <stdlib.h>
  #include <stdio.h>

  int yylex();
  int yyerror(const char *bruh)
  {
    puts(bruh);
    exit(1);
  }
%}

%union {
  double number;
  char sigil;
  char *text;
}

%token <number> T_NUMBER
%token T_SIGIL
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
  | T_POP T_NUMBER
  {
    printf("pop %f\n", $2);
  }
  | T_IDENT
  {
    printf("Error: '%s' not defined.", $1);
    yyerror("Instruction undefined error");
  }

%%

int main(int argc, char **argv)
{
  yyparse();
}
