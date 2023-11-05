# C++ Advanced Grammers
## Namespace
https://learn.microsoft.com/zh-cn/cpp/cpp/namespaces-cpp?view=msvc-170#inline-namespaces-c-11

内联命名空间的成员会被视为父命名空间的成员
```cpp
//Header.h
#include <string>

namespace Test
{
    namespace old_ns
    {
        std::string Func() { return std::string("Hello from old"); }
    }

    inline namespace new_ns
    {
        std::string Func() { return std::string("Hello from new"); }
    }
}

#include "header.h"
#include <string>
#include <iostream>

int main()
{
    using namespace Test;
    using namespace std;

    string s = Func();
    std::cout << s << std::endl; // "Hello from new"
    return 0;
}
```

## 双冒号::开头
https://blog.csdn.net/qq_21438461/article/details/131170738

如果你在一个命名空间或类内部看到这样的语法（比如`::ndm_proto_v2::Polygon`），那么这个`::`实际上是在指定从**全局作用域开始查找这个命名空间或类，而不是从当前的作用域**。这样可以避免在有命名冲突的情况下查找错误的命名空间或类。

# C++ Advanced Grammers
# Exceptions
## 函数声明后跟 throw() (C++98)
https://blog.csdn.net/to_Baidu/article/details/53763683

**表示fun函数不允许抛出任何异常，即fun函数是异常安全的。**
```cpp
void fun() throw();
```
**表示fun函数可以抛出任何形式的异常。**
```cpp
void fun() throw(...);
```
**表示fun函数只能抛出exceptionType类型的异常。**
```cpp
void fun() throw(exceptionType);

// 表示只抛出int类型异常
void GetTag() throw(int); 
// 表示抛出in，char类型异常
void GetTag() throw(int，char);         
```

## 函数声明后跟 noexcept (C++11)
https://www.cnblogs.com/RioTian/p/15115387.html

**析构函数默认都是 noexcept 的**
```cpp
void func_not_throw() noexcept; // 保证不抛出异常
void func_not_throw() noexcept(true); // 和上式一个意思

void func_throw() noexcept(false); // 可能会抛出异常
void func_throw(); // 和上式一个意思，若不显示说明，默认是会抛出异常（除了析构函数，详见下面）
```

## std::unexpected
By default, the unexpected handler calls terminate. But this behavior can be redefined by calling set_unexpected.

## Concepts
### stack unwinding 栈展开
https://www.cnblogs.com/zhuyf87/archive/2012/12/23/2829725.ht


# Others

## static_assert
https://blog.csdn.net/u011436427/article/details/125400671

## static_cast

## std::allocator std::allocator_traits
https://blog.csdn.net/qq_40788199/article/details/126797798
https://en.cppreference.com/w/cpp/memory/allocator_traits
https://zhuanlan.zhihu.com/p/185611161

## decltype (C++11)
https://blog.csdn.net/m0_51913750/article/details/131003652

## constexpr
https://zhuanlan.zhihu.com/p/93641410

## vprintf
https://en.cppreference.com/w/cpp/io/c/vfprintf

## numeric_limits
https://blog.csdn.net/wang161019/article/details/102899324
```cpp
<typename T>
std::numeric_limits<T>
```

