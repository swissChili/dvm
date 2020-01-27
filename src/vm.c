#include "vm.h"
#include "type.h"
#include <collect/vector.h>

#ifdef DEBUG
  #define dbg printf
#else
  #define dbg(...)
#endif

void dvm_run(dvm_object *root, char *bc)
{
  vector *stack = new_vector();
  dvm_value *v = NULL;
  // Bytecode should end with a 0, just makes it easier to loop
  while (*bc)
  {
    switch (*bc++)
    {
      case PUSHIN:
        v = dvm_new_value(NUMBER);
        v->num_val = dvm_bc_dbl(&bc);
        dvm_print_value(v);
        vector_push(stack, v);
        break;
      case DEBUG:
        for (uint64_t i = 0; i < stack->length; i++)
        {
          dvm_print_value(vector_at(stack, i));
        }
    }
  }
}
