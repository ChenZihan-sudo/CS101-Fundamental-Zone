#include "outer_lib/outer_lib.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

extern "C" int main()
{
  printf("This is a test file.\n");
  outer_function();
  return 0;
}
