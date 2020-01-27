#include "bytecode.h"

char *dvm_bc_str(char **bc)
{
  char *str = *bc;
  do
    (*bc)++;
  while (**bc);

  return str;
}

#define DVM_BC_T(bc, t) t t_##t = *(t *)*bc; bc += sizeof(t); return t_##t;

double dvm_bc_dbl(char **bc)
{
  DVM_BC_T(bc, double)
}

int64_t dvm_bc_int(char **bc)
{
  DVM_BC_T(bc, int64_t)
}
