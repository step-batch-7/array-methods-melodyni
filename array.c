#include "array.h"

Array *init_array(array_length){
  Array *src = malloc(sizeof(Array));
  src->array = malloc(sizeof(int)*array_length);
  src->length = array_length;
  return src;
}

Bool compare(Array *src_a,Array *src_b){
  Bool status = True;
  int *array_a = src_a->array ;
  if(src_a->length != src_b->length){
    return False;
  }
  for(int i= 0; i < src_a->length; i++){
    if(src_a->array[i] != src_b->array[i]){
      status = False;
    }
  }
  return status;
}

Array *map(Array *src, Mapper mapper){
  int list[src->length];
  for(int i= 0; i < src->length; i++){
    list[i] = (* mapper)(src->array[i]);
  }
  Array *result = init_array(src->length);
  memcpy(result->array,list,src->length);
  return result;
}
