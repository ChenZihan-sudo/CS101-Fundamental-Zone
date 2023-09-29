## namespace
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