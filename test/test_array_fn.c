#include "../array.h"

void green(){
  printf("\033[1;30m");
}

void red(){
  printf("\033[0;31m");
}

void white(){
  printf("\033[1;0m");
}

void print_result(int passed,char *message){
  if(passed){
    green();
    printf("   ✔ %s\n",message);
  }else{
    red();
    printf("   ✘ %s\n",message);
  }
  white();
}

int increment(int num){
  return num+1;
}

Bool is_odd(int num){
  if(num % 2 != 0){
    return True;
  }
  return False;
}

int add(int num_a, int num_b ) {
  return num_a + num_b;
}

void test_map(){
  printf("\nmap\n");
  int list[3] = {2,3,4};
  int expected_list[3] = {3,4,5};
  Array *array = init_array(3);
  Array *expected = init_array(3);
  memcpy(array->array,list, 3*sizeof(int));
  memcpy(expected->array,expected_list, 3*sizeof(int));
  Array *actual = map(array, &increment);
  char message[] = "should map list with numbers";
  print_result(compare(expected,actual),message);

  Array *array2 = init_array(0);
  Array *expected2 = init_array(0);
  Array *actual2 = map(array2, &increment);
  char message2[] = "should map and empty array ";
  print_result(compare(expected2,actual2),message2);
}

void test_filter(){
  printf("\nfilter\n");
  int list[5] = {2,3,4,5,9};
  int expected_list[3] = {3,5,9};
  Array *array = init_array(5);
  Array *expected = init_array(3);
  memcpy(array->array,list,5*sizeof(int));
  memcpy(expected->array,expected_list,3*sizeof(int));
  Array *actual = filter(array, &is_odd);
  char message[] = "should filter odd numbers in array";
  print_result(compare(expected,actual),message);

  Array *array2 = init_array(0);
  Array *expected2 = init_array(0);
  Array *actual2 = filter(array2, &is_odd);
  char message2[] = "should filter empty array ";
  print_result(compare(expected2,actual2),message2);
}

void test_reduce(){
  printf("\nreduce\n");
  int list[5] = {1,2,3,4,5};
  Array *array = init_array(5);
  memcpy(array->array,list,5*sizeof(int));
  int result = reduce(array, 0, &add);
  char message[] = "should add all numbers in the list";
  print_result(result == 15, message);

  int list2[5] = {1,2,3,4,5};
  Array *array2 = init_array(5);
  memcpy(array2->array, list2, 5*sizeof(int));
  int result2 = reduce(array2, 15, &add);
  char message2[] = "should add all numbers with in the list with context";
  print_result(result2 == 30, message2);
}


int main()
{
  test_map();
  test_filter();
  test_reduce();
  return 0;
}