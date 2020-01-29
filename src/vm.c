#include "vm.h"
#include "type.h"
#include "debug.h"
#include <collect/vector.h>
#include <collect/list.h>


void dvm_run(dvm_object *root, char *bc)
{
  vector *stack = new_vector();
  list *this_stack = new_list();
  list_push(this_stack, root);
  dvm_value *v = NULL;
  char *str = NULL;
  char *original = bc;
  // Fix clang warning
  (void) original;
  (void) root;

  // Bytecode should end with a 0, just makes it easier to loop
  while (*bc)
  {
    dbg("0x%x '%c' @ %ld\n", *bc, *bc, (long)(bc - original));
    switch (*bc++)
    {
      case PUSHIN:
        v = dvm_new_value(NUMBER);
        v->num_val = dvm_bc_dbl(&bc);
        dvm_print_value(v);
        vector_push(stack, v);
        break;
      case DEBUG:
        dbg("Debugging\n");
        for (uint64_t i = 0; i < stack->length; i++)
        {
          printf("stack -> ");
          dvm_print_value(vector_at(stack, i));
        }
        break;

      case LDTHIS:
        str = dvm_bc_str(&bc);
        v = dvm_object_get(this_stack->last->val, str);
        if (v != NULL)
          vector_push(stack, v);
        else
        {
          printf("Error -> Key %s does not exist in this scope.\n", str);
          exit(1);
        }
        break;

      case LDGLBL:
        str = dvm_bc_str(&bc);
        v = dvm_object_get(root, str);
        dbg("Loading global %s\n", str);
        if (v != NULL)
          vector_push(stack, v);
        else
        {
          printf("Error -> Key %s does not exist in global scope.\n", str);
          exit(1);
        }
        break;

      case ASNGLBL:
        str = dvm_bc_str(&bc);
        v = dvm_new_value(NUMBER);
        v->num_val = dvm_bc_dbl(&bc);
        dbg("Assigning global %s to %f @ %ld\n", str, v->num_val, (long)(bc - original));
        dvm_object_set(root, str, v);
        break;

      case ASNTHIS:
        str = dvm_bc_str(&bc);
        v = dvm_new_value(NUMBER);
        v->num_val = dvm_bc_dbl(&bc);
        dvm_object_set(this_stack->last->val, str, v);
        break;
    }
    dbg("0x%x '%c' @ %ld\n", *bc, *bc, (long)(bc - original));
  }
}
