# C++ Advanced Grammers

## 虚函数

https://zhuanlan.zhihu.com/p/54145222

基类对成员使用virtual，作为接口，子类继承基类时，可以将virtual的成员重载为子类自己的成员

### private, protected的访问范围

protected:只允许子类及本类的成员函数访问

private:只允许本类的成员函数访问

**protected 可以被子类成员函数访问，而 private 不可以被子类成员函数访问**
