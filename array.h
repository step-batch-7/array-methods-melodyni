#ifndef __ARRAY_H
#define __ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h> 

typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;


Array *map(Array *src, Mapper mapper);
Array *filter(Array *src, Predicate predicate);
int reduce(Array *src, int init, Reducer reducer);

Bool compare(Array *array_a,Array *array_b);
Array *init_array(int array_length);
#endif
