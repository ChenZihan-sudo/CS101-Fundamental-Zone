# C++ Advanced Grammers

## 虚函数

https://zhuanlan.zhihu.com/p/54145222

基类对成员使用virtual，作为接口，子类继承基类时，可以将virtual的成员重载为子类自己的成员

### private, protected的访问范围

protected:只允许子类及本类的成员函数访问

private:只允许本类的成员函数访问

**protected 可以被子类成员函数访问，而 private 不可以被子类成员函数访问**



## 隐式地声明一个默认构造函数

在 C++ 中，如果你没有为类显式地提供一个构造函数，编译器会为你隐式地声明一个默认构造函数。这个默认构造函数被称为 "implicitly-declared" 构造函数。这个构造函数不做任何事情，只是创建一个对象实例。

如果没有显式地声明一个构造函数，则编译器会隐式声明一个。这个构造函数是 `constexpr` 的，这意味着它可以在**编译时被调用**，而不是在运行时。

然而，当你的类有静态成员变量时，你需要在**类的实现文件**中为这些静态成员变量提供定义。



## 类中的静态成员与非静态成员

> https://blog.csdn.net/qq_25800311/article/details/81133483

静态成员：静态类中的成员加入static修饰符,即是静态成员.可以直接使用类名+静态成员名访问此静态成员,因为静态成员存在于内存,非静态成员需要实例化才会分配内存,所以静态成员不能访问非静态的成员..因为静态成员存在于内存,所以非静态成员可以直接访问类中静态的成员.静态成员在每个类中只有一个拷贝，是解决同一个类的不同对象之间数据和函数共享问题的。

非静态成员：所有没有加Static的成员都是非静态成员,当类被实例化之后,可以通过实例化的类名进行访问.非静态成员的生存期决定于该类的生存期.而静态成员则不存在生存期的概念,因为静态成员始终驻留在内容中.



## 类型转换运算符

C++ 提供了四种类型转换运算符：`static_cast`、`dynamic_cast`、`const_cast`和`reinterpret_cast`。

1. `static_cast`：这是最常用的类型转换运算符。它可以在任何类型之间进行转换，但是转换的类型需要是相关的，例如从 int 转换为 float，或者从派生类指针转换为基类指针。

```cpp
int i = 10;
float f = static_cast<float>(i);  // 将 int 转换为 float
```

2. `dynamic_cast`：这个运算符主要用于多态类型的安全转换。它在运行时检查转换是否有效。如果转换无效，它会返回 null（对于指针）或抛出异常（对于引用）。

```cpp
Base* base = new Derived();
Derived* derived = dynamic_cast<Derived*>(base);  // 如果 base 确实指向一个 Derived 对象，这个转换是安全的
```

3. `const_cast`：这个运算符用于移除常量性。它允许你修改一个 const 对象的值，但是这通常是不安全的，因为 const 对象可能存储在只读内存中。

```cpp
const int ci = 10;
int* pi = const_cast<int*>(&ci);
*pi = 20;  // 这是未定义行为，因为我们正在修改一个 const 对象
```

4. `reinterpret_cast`：这个运算符用于进行低级别的类型转换。它可以在任何类型的指针或引用之间进行转换，或者将指针转换为足够大的整数类型，或者将整数类型转换为指针。这个运算符很危险，应该尽量避免使用。

```cpp
int i = 10;
int* pi = &i;
char* pc = reinterpret_cast<char*>(pi);  // 将 int* 转换为 char*
```



sourcetrail

https://www.bilibili.com/read/cv24235677/
