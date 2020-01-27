#ifndef DVM_OBJECT_H
#define DVM_OBJECT_H

#include <collect/map.h>

struct dvm_object
{
  struct dvm_object *proto;
  map *slots;
};
typedef struct dvm_object dvm_object;

dvm_object *dvm_new_object(dvm_object *proto);
void dvm_free_object(dvm_object *proto);


#endif//DVM_OBJECT_H
