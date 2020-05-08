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

void test_map(){
  printf("\nmap\n");
  int list[3] = {2,3,4};
  int expected_list[3] = {3,4,5};
  Array *array = init_array(3);
  Array *expected = init_array(3);
  memcpy(array->array,list,3);
  memcpy(expected->array,expected_list,3);
  Array *actual = map(array, &increment);
  char message[] = "should map list with numbers";
  print_result(compare(expected,actual),message);

  Array *array2 = init_array(0);
  Array *expected2 = init_array(0);
  Array *actual2 = map(array2, &increment);
  char message2[] = "should map and empty array ";
  print_result(compare(expected2,actual2),message2);

}

int main()
{
  test_map();
  return 0;
}