#include <cstdlib>
#include <cstring>
#include <iostream>
#include "configs/option_config.h"

#ifdef USE_OUTER_LIB
#include "outer_lib/outer_lib.h"
#else
void outer_function(void)
{
  int a = 100;
  int b = 200;
  memcpy(&a, &b, sizeof(int));
  printf("This is a inner function with a memcpy:%d. \n", a);
}
#endif

extern "C" int main()
{
  printf("This is a test file.\n");
  outer_function();
  return 0;
}
