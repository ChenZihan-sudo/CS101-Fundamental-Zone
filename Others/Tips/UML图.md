# UML图

https://zhuanlan.zhihu.com/p/109655171

https://cloud.tencent.com/developer/article/1176331

## 类图

- “+”表示 `public`
- “-”表示 `private`
- “#”表示 `protected`
- 不带符号表示 `default`

## 关系

## ![v2-e6a48521352fff8270e753ea4a79d9fb_1440w](./pics/v2-e6a48521352fff8270e753ea4a79d9fb_1440w.webp)

### 实现关系

实现关系是指接口及其实现类之间的关系。在UML类图中，实现关系用空心三角和虚线组成的箭头来表示，从实现类指向接口，如图1.9所示。在Java代码中，实现关系可以直接翻译为关键字 `implements`。

interface接口与implements实现、接口与类的关系：

https://blog.csdn.net/Jackmat/article/details/128951289

![v2-616c153ec74d496a811ac50c83c3653c_1440w](./pics/v2-616c153ec74d496a811ac50c83c3653c_1440w.webp)

### 泛化关系

泛化关系（Generalization）是指对象与对象之间的继承关系。如果对象A和对象B之间的“is a”关系成立，那么二者之间就存在继承关系，对象B是父对象，对象A是子对象。例如，一个年薪制员工“is a”员工，很显然年薪制员工Salary对象和员工Employee对象之间存在继承关系，Employee对象是父对象，Salary对象是子对象。

在UML类图中，泛化关系用空心三角和实线组成的箭头表示，从子类指向父类，如图8所示。在Java代码中，对象之间的泛化关系可以直接翻译为关键字 `extends`。　　　　　　　　　　　　　　　　　　　　　　　　　

![img](./pics/v2-04064db11797cf36229d67407fea1b83_1440w.webp)

### 关联关系

让一个对象知道另一个对象的属性和方法

单向关联和双向关联

关联关系（Association）是指对象和对象之间的连接，它使一个对象知道另一个对象的属性和方法。在Java中，关联关系的代码表现形式为一个对象含有另一个对象的引用。也就是说，如果一个对象的类代码中，包含有另一个对象的引用，那么这两个对象之间就是关联关系。

导航性（Navigatity）下图

![v2-3f331f3dc075abb4215413014688638f_1440w](./pics/v2-3f331f3dc075abb4215413014688638f_1440w.webp)

一个对象可以持有其它对象的数组或者集合。在UML中，通过放置多重性（multipicity）表达式在关联线的末端来表示。多重性表达式可以是一个数字、一段范围或者是它们的组合。多重性允许的表达式示例如下：

- 数字：精确的数量
- `*`或者`0..*`：表示0到多个
- `0..1`：表示0或者1个，在Java中经常用一个空引用来实现
- `1..*`：表示1到多个

### 依赖关系

依赖（Dependency）关系是一种弱关联关系。如果对象A用到对象B，但是和B的关系不是太明显的时候，就可以把这种关系看作是依赖关系。如果对象A依赖于对象B，则 A “use a” B。比如驾驶员和汽车的关系，驾驶员使用汽车，二者之间就是依赖关系。

在UML类图中，依赖关系用一个带虚线的箭头表示，由使用方指向被使用方，表示使用方对象持有被使用方对象的引用，如图10所示。

![img](./pics/v2-431e044bbf26778a20dd788968e22aac_1440w.webp)

依赖关系在Java中的具体代码表现形式为**B为A的构造器**或**方法中的局部变量**、**方法或构造器的参数**、**方法的返回值**，或者**A调用B的静态方法**。

### 聚合关系

聚合（Aggregation）是关联关系的一种特例，它体现的是整体与部分的拥有关系，即 “has a” 的关系。此时整体与部分之间是可分离的，它们可以具有各自的生命周期，部分可以属于多个整体对象，也可以为多个整体对象共享，所以聚合关系也常称为共享关系。例如，公司部门与员工的关系，一个员工可以属于多个部门，一个部门撤消了，员工可以转到其它部门。

![{@Workspace}/.pic/s1hiq589gx.png](./pics/s1hiq589gx.png)

```cpp
class Student;
class Classes{
public:
    Student* student; 
    Classes(Student* stu):student(stu){}
};
```

### 组合关系 

组合（Composition）也是关联关系的一种特例，它同样体现整体与部分间的包含关系，即 “contains a” 的关系。但此时整体与部分是不可分的，部分也不能给其它整体共享，作为整体的对象负责部分的对象的生命周期。这种关系比聚合更强，也称为强聚合。如果`A`组合`B`，则`A`需要知道`B`的生存周期，即可能`A`负责生成或者释放`B`，或者`A`通过某种途径知道`B`的生成和释放。

![yxwoqzq8r2](./pics/yxwoqzq8r2.png)

```cpp
class Heart;
class Student{
public:
    Heart* heart; 
    Student(){
        heart=new Heart;
    }
    ~Student(){
        delete heart;
    }
};
```

### 扩展关系

https://www.ibm.com/docs/zh/rsas/7.5.0?topic=relationships-extends