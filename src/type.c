#include "type.h"
#include "object.h"
#include <stdlib.h>
#include <stdio.h>

dvm_value *dvm_new_value(unsigned char type)
{
  dvm_value *v = malloc(sizeof(dvm_value));
  v->type = type;
  v->refs = 1;
  return v;
}


void dvm_free_value(dvm_value *value, dvm_vvisitor_t visitor)
{
  switch (value->type)
  {
  case OBJECT:
    visitor(value->ref_val);
  default:
    free(value);
  }
}

dvm_value *dvm_new_num(double num)
{
  dvm_value *val = dvm_new_value(NUMBER);
  val->num_val = num;
  return val;
}

dvm_value *dvm_new_char(char c)
{
  dvm_value *val = dvm_new_value(CHAR);
  val->char_val = c;
  return val;
}

int dvm_own(dvm_value *value)
{
  return ++value->refs;
}

int dvm_disown(dvm_value *value)
{
  if (--value->refs == 0)
  {
    dvm_free_value(value, &dvm_free_object);
  }

  return value->refs;
}

void dvm_print_value(dvm_value *v)
{
  switch (v->type)
  {
    case NUMBER:
      printf("%f\n", v->num_val);
  }
}

void dvm_object_set(dvm_object *obj, char *key, dvm_value *val)
{
  map_set(obj->slots, key, val);
}

dvm_value *dvm_object_get(dvm_object *obj, char *key)
{
  if (map_exists(obj->slots, key))
  {
    return (dvm_value *)map_get(obj->slots, key);
  }
  else if (obj->proto != NULL && map_exists(obj->proto->slots, key))
  {
    return (dvm_value *)map_get(obj->proto->slots, key);
  }
  else
  {
    return NULL;
  }
}

