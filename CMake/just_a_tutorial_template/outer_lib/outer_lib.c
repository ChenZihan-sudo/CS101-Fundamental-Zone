#include "outer_lib.h"

void outer_function(void)
{
  int a = 100;
  int b = 200;
  memcpy(&a, &b, sizeof(int));
  printf("This is a outer function with a memcpy:%d. \n", a);
}
