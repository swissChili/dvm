#include <stdio.h>
#include "bytecode.h"
#include "vm.h"

int main()
{
  printf("dvm -- dynamic virtual machine\n");
  // little-endian 1
  char bytes[] =
  {
    PUSHIN, 0, 0, 0, 0, 0, 0, 0, 0x40, // push 0
    DEBUG,
    ASNGLBL, 'b', 0, // $b = 2.5
    0, 0, 0, 0, 0, 0, 0x4, 0x40,
    LDGLBL, 'b', 0, // push $b
    DEBUG,
    0
  };

  dvm_object *global = dvm_new_object(NULL);

  printf("it's %f\n", *(double *)(bytes + 13));

  dvm_run(global, bytes);

  dvm_free_object(global);
}
