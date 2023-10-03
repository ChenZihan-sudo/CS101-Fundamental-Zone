#include <cstdint>
#include <iostream>
#include <limits>
#include <memory>
#include <ostream>
#include <string>

int main()
{

  std::allocator<int> alloc_int;
  int* int_i = alloc_int.allocate(10);
  for (uint8_t i = 0; i < 10; i++) {
    printf("%llu %llu %d %d \n", int_i, int_i + i, sizeof(int*), sizeof(int));
    alloc_int.construct(int_i + i, i); // -> new data_type(...)
  }
  for (uint8_t i = 0; i < 10; i++) {
    std::cout << int_i[i] << std::endl;
  }
  alloc_int.deallocate(int_i, 10);

  std::allocator<std::string> alloc_str;
  std::string* string_i = alloc_str.allocate(10);
  for (auto i = 0; i < 10; i++) {
    printf("%llu %llu %d %d\n", string_i, string_i + i, sizeof(std::string*), sizeof(std::string));
    alloc_str.construct(string_i + i, "hello_world_" + std::to_string(i));
  }
  for (auto i = 0; i < 10; i++) {
    std::cout << string_i[i] << std::endl;
  }

  //   std::allocator<std::string> realloc_str;
  //   decltype(alloc_str)::rebind<std::string>::other realloc_str;
  //   std::allocator_traits<decltype(alloc_str)>::rebind_alloc<std::string> realloc_str;

  alloc_str.deallocate(string_i, 10);

  // int* (8B) == string* (8B) == void * (8B), int (4B), string (32B)
  // int_pointer (addr1), str_pointer (addr2), offset
  // address of (int_pointer + offset) = addr1 + offset * 4B(sizeof(int), 4*8bit)
  // address of (str_pointer + offset) = addr2 + offset * 32B(sizeof(string), 32*8bit)
}
