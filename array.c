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

Array *fill_array(Array *src,int list[], int array_length){
  for(int i = 0; i< array_length; i++){
    src->array[i] = list[i];
  }
  return src;
}

Array *create_array(int list[], int array_length){
  Array *src = init_array(3);
  return fill_array(src,list,array_length);
}

Array *map(Array *src, Mapper mapper){
  int list[src->length];
  for(int i= 0; i < src->length; i++){
    list[i] = (* mapper)(src->array[i]);
  }
  return create_array(list,src->length);
}
