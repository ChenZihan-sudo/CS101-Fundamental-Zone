#include <cassert>
#include <iostream>
#include <memory>
#include <sys/types.h>

std::string* create_str_array(ssize_t size)
{
  std::allocator<std::string> str_alloc;
  assert(size > 0 && "String size can't less than 0");
  std::string* strings = str_alloc.allocate(size);
  return strings;
}


#define STR_ARR_CREATE_SIZE -1
std::string* create_str_array_use_static_assert(void)
{
  std::allocator<std::string> str_alloc;
  // This should be used in a constant expression
  static_assert(STR_ARR_CREATE_SIZE > 0, "String size can't less than 0");
  std::string* strings = str_alloc.allocate(STR_ARR_CREATE_SIZE);
  return strings;
}

int main()
{
  create_str_array_use_static_assert();
  create_str_array(-1);
}


// assert(expr) -> Runtime assert
// static_assert(expr) -> Compile-time assert but constant expression needed
