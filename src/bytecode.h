#ifndef DVM_BYTECODE_H
#define DVM_BYTECODE_H

#include <stdint.h>

enum
{
  PUSHIN = 'p', // push 123
  LDGLBL = 'g', // push $something
  LDTHIS = 't', // push @something
  LDLOCL = 'l', // push %n
  ASNGLBL = 'G', // $something = 123
  ASNTHIS = 'T', // @something = 123
  ASNLOCL = 'L', // %n = 123
  ASNGLBLFN = 'f', // $object.method = label
                   // or $object.method:
  POPGLBL = '$', // pop $something
  POPLOCL = '%', // pop %n
  POPTHIS = '@', // pop @something

  DEBUG = '!'
};

char *dvm_bc_str(char **bc);
double dvm_bc_dbl(char **bc);
int64_t dvm_bc_int(char **bc);

#endif//DVM_BYTECODE_H
