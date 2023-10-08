#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
using namespace std;

struct CException : public exception
{
  std::string outputs;
  CException(std::string str) : outputs("CException: " + str) { }

  const char* what() const throw() override
  {
    return outputs.c_str();
  }

  const char* base() const throw()
  {
    return "std::exception";
  }

  const char* normal() const
  {
    return "Normal function";
  }
};

void func_throw_int(int int_val, const char* char_val) throw(int)
{
  throw int_val;
  throw char_val; // Unexpected type of throw, handle by std::terminate
}

int main()
{
  try {
    throw std::exception();
  } catch (const std::exception& e) {
    std::cout << "Error throw: " << e.what() << std::endl;
  }

  // Virtual e.what() overrided
  try {
    throw CException("exception throwed");
  } catch (const std::exception& e) {
    std::cout << "OVERRIDE: " << e.what() << std::endl;
  }

  try {
    throw CException("exception throwed");

  } catch (CException& ce) {
    std::cout << ce.what() << std::endl;
    std::cout << ce.base() << std::endl;
    std::cout << ce.normal() << std::endl;
  }

  try {
    func_throw_int(100, "throw c_str");
  } catch (int throw_val) {
    std::cout << "Func throw val: " << throw_val << std::endl;
  } catch (const char* c_str) {
    std::cout << c_str << std::endl;
  }

  while (1) { }
}
