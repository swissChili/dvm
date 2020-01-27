#ifndef DVM_VM_H
#define DVM_VM_H

#include "bytecode.h"
#include "object.h"

void dvm_run(dvm_object *root, char *bc);


#endif//DVM_VM_H
