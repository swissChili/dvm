#ifndef DVM_TYPE_H
#define DVM_TYPE_H

#include "object.h"

enum
{
  NUMBER = 0,
  CHAR,
  OBJECT,
};

typedef void (*dvm_vvisitor_t)(dvm_object *);

struct dvm_value
{
  unsigned char type;
  union
  {
    void *ref_val;
    double num_val;
    char char_val;
  };
  unsigned refs;
};
typedef struct dvm_value dvm_value;

/**
 * @brief Allocate a new value on the heap.
 */
dvm_value *dvm_new_value(unsigned char type);
/**
 * @brief Free a value allocated on the heap.
 */
void dvm_free_value(dvm_value *value, dvm_vvisitor_t visitor);
/*
 * @brief Revoke ownership of a value.
 * Decrements the value's reference count, frees it if there are no
 * references remaining.
 */
int dvm_disown(dvm_value *value);
/**
 * @brief Take partial ownership of a value.
 * Adds one to the value's reference count.
 */
int dvm_own(dvm_value *value);

dvm_value *dvm_new_num(double num);
dvm_value *dvm_new_char(char c);

void dvm_print_value(dvm_value *v);

void dvm_object_set(dvm_object *obj, char *key, dvm_value *val);
dvm_value *dvm_object_get(dvm_object *obj, char *key);


#endif//DVM_TYPE_H
