#include "../array.h"
#include "../array_void.h"

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

Object increment_by_1(Object data){
  Object num = malloc(sizeof(Object));
  int number = (*(int *)data) + 1;
  memcpy(num, &number, sizeof(int));
  return num;
}

Object convert_to_lower(Object data){
  Object lower_char = malloc(sizeof(Object));
  char letter = tolower(*(char *)data);
  memcpy(lower_char, &letter , sizeof(char));
  return lower_char;
}

Object add_void(Object data_a, Object data_b){
  Object sum_ptr = malloc(sizeof(Object));
  int num_a = *(int *)data_a;
  int num_b = *(int *)data_b;
  int sum = num_a + num_b;
  memcpy(sum_ptr, &sum , sizeof(char));
  return sum_ptr;
}

Bool is_vowel(Object data){
  char ch = *(char *)data;
  Bool is_lower_vowel = ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ;
  Bool is_upper_vowel = ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ;
  return is_upper_vowel || is_lower_vowel;
}

Bool are_char_equal(Object data_a, Object data_b){
  char a = *(char *)data_a;
  char b = *(char *)data_b;
  return a == b;
}

Bool are_int_equal(Object data_a, Object data_b){
  int a = *(int *)data_a;
  int b = *(int *)data_b;
  return a == b;
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

void test_map_void(){
  printf("\nmap_void\n");
  char message[] = "should convert all letter in list to its lower case";
  char char1 = 'A';
  char char2 = 'B';
  char char3 = 'C';
  ArrayVoid_ptr array_void = init_array_void(3);
  array_void->array[0] = &char1;
  array_void->array[1] = &char2;
  array_void->array[2] = &char3;

  char char4 = 'a';
  char char5 = 'b';
  char char6 = 'c';
  ArrayVoid_ptr expected = init_array_void(3);
  expected->array[0] = &char4;
  expected->array[1] = &char5;
  expected->array[2] = &char6;

  ArrayVoid_ptr mapped_array = map_void(array_void, &convert_to_lower);
  Bool res = compare_array_void(expected,mapped_array,&are_char_equal);
  print_result(res,message);
}


void test_filter_void(){
  printf("\nfilter_void\n");
  char message[] = "should filter vowels in the list";
  char char1 = 'A';
  char char2 = 'B';
  char char3 = 'E';
  ArrayVoid_ptr array_void = init_array_void(3);
  array_void->array[0] = &char1;
  array_void->array[1] = &char2;
  array_void->array[2] = &char3;

  char char4 = 'A';
  char char5 = 'E';
  ArrayVoid_ptr expected = init_array_void(2);
  expected->array[0] = &char4;
  expected->array[1] = &char5;

  ArrayVoid_ptr actual = filter_void(array_void, &is_vowel);
  Bool res = compare_array_void(expected,actual,&are_char_equal);
  print_result(res,message);

  char message2[] = "should filter empty list ";
  ArrayVoid_ptr array_void2 = init_array_void(0);
  ArrayVoid_ptr expected2 = init_array_void(0);

  ArrayVoid_ptr actual2 =  filter_void(array_void2, &is_vowel);
  Bool res2 = compare_array_void(expected2,actual2,&are_char_equal);
  print_result(res2,message2);
  
}

void test_reduce_void(){
  printf("\nreduce_void\n");
  char message[] = "should add all numbers in the list with the initial value";
  char num1 = 10;
  char num2 = 20;
  char num3 = 30;
  ArrayVoid_ptr array_void = init_array_void(3);
  array_void->array[0] = &num1;
  array_void->array[1] = &num2;
  array_void->array[2] = &num3;

  int init = 40;
  
  char message2[] = "should return init value for empty list";
  Object actual = reduce_void(array_void, &init ,&add_void);
  print_result((*(int *)actual) == 100, message);
  ArrayVoid_ptr array_void2 = init_array_void(0);

  int init2 = 40;
  
  Object actual2 = reduce_void(array_void2, &init2 ,&add_void);
  print_result((*(int *)actual2) == 40, message2);
}


int main()
{
  test_map();
  test_filter();
  test_reduce();
  test_map_void();
  test_filter_void();
  test_reduce_void();
  return 0;
}