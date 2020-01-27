#include "object.h"
#include <stdlib.h>
#include <collect/map.h>

dvm_object *dvm_new_object(dvm_object *proto)
{
  dvm_object *obj = malloc(sizeof(dvm_object));
  obj->slots = new_map();
  obj->proto = proto;
  return obj;
}

void dvm_free_object(dvm_object *obj)
{
  free_map(obj->slots);
  free(obj);
}

