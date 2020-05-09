#include "array_void.h"

ArrayVoid_ptr init_array_void(int length){
  ArrayVoid_ptr array_void = malloc(sizeof(ArrayVoid));
  array_void->array = malloc(sizeof(Object)*length);
  array_void->length = length;
  return array_void;
}

Bool compare_array_void(ArrayVoid_ptr src_a, ArrayVoid_ptr src_b, EquatorFn equator){
  if(src_a->length != src_b->length){
    return False;
  }
  for(int i= 0; i < src_a->length; i++){
    if(!equator(src_a->array[i], src_b->array[i])){
      return False;
    }
  }
  return True;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper){
  Object list[src->length];
  for(int i=0; i< src->length; i++){
    list[i] = (*mapper)(src->array[i]);
  }
  ArrayVoid_ptr array_void = init_array_void(src->length);
  memcpy(array_void->array, list ,sizeof(Object)*src->length);
  return array_void;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate){
  Object list[src->length];
  int filter_count = 0;
  for(int i=0; i< src->length;i++){
    Bool status = (*predicate)(src->array[i]);
    if(status){
      list[filter_count] = src->array[i];
      filter_count++;
    }
  }
  ArrayVoid_ptr array_void = init_array_void(filter_count);
  memcpy(array_void->array, list ,sizeof(Object)*filter_count);
  return array_void;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer){
  for(int i=0; i< src->length;i++){
    init = (*reducer)(src->array[i], init);
  }
  return init;
}
