#include <stdio.h>
#include "bytecode.h"
#include "vm.h"

int main()
{
  printf("dvm -- dynamic virtual machine\n");
  // little-endian 1
  char bytes[] =
  {
    PUSHIN, 1, 0, 0, 0, 0, 0, 0, 0,
    DEBUG, 0
  };
  dvm_run(NULL, bytes);
}
