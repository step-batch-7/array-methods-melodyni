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
  int list[] = {2,3,4};
  int expected_list[] = {3,4,5};
  Array *array = create_array(list,3);
  Array *expected = create_array(expected_list,3);
  Array *actual = map(array, &increment);
  char message[] = "should increment each element in the given list by one";
  print_result(compare(expected,actual),message);
}

int main()
{
  test_map();
  return 0;
}