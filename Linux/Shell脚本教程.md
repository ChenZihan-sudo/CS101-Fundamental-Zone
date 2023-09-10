# Shell，套个壳 - Shell 脚本教程

## Shell 示例

```shell
#!/bin/bash
echo "Hello world"
```

> **#!** 是一个约定的标记，它告诉系统这个脚本需要什么解释器来执行，即使用哪一种 Shell。

## 注释 #



## 变量

```shell
#!/bin/bash

variable_name="this is a variable" # 定义变量
echo $variable_name

variable_name="hello world" # 重定义变量
echo $variable_name

readonly variable_name # 修改变量为只读
unset variable_name # 删除变量 
```

变量使用的注意要点



## 数组

```shell
#!/bin/bash

array_name=(value0 value1 value2 value3)
echo ${array_name[0]}

array_name[2]="Array_item_2"
echo ${array_name[2]}

length=${#array_name[*]} # 取得数组元素的个数
elem_length=${#array_name[2]} # 取得数组单个元素的长度

echo $length
echo $elem_length
```



## 字符串与转义字符

```shell
#!/bin/bash

a_string="a string"
echo ${#a_string} # 获取字符串长度

right_str="R I G H T"
op="You are \" $right_str \",\n but Genshin Impact is a" # 双引号内可以添加转义字符
echo -e $op

echo ${op:2:19} # 字符串截断
```



## 参数传递与特殊字符

```bash
./test.sh param1 param2 param3

#!/bin/bash
echo "File name: $0"
echo "Param1: $1"
echo "Param2: $2"
echo "Param3: $3"
echo "Total param passed: $#"
```



### 特殊字符

| 参数处理 | 说明                                                         |
| :------- | :----------------------------------------------------------- |
| $#       | 传递到脚本的参数个数                                         |
| $*       | 以一个单字符串显示所有向脚本传递的参数。 如"$*"用「"」括起来的情况、以"$1 $2 … $n"的形式输出所有参数。 |
| $$       | 脚本运行的当前进程ID号                                       |
| $!       | 后台运行的最后一个进程的ID号                                 |
| $@       | 与$*相同，但是使用时加引号，并在引号中返回每个参数。 如"$@"用「"」括起来的情况、以"$1" "$2" … "$n" 的形式输出所有参数。 |
| $-       | 显示Shell使用的当前选项，与set命令功能相同。                 |
| $?       | 显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。 |

## 基本运算符

### 算术运算符

```shell
#!/bin/bash
val=`expr 1 + 1` # 运算符之间必须要有空格 # 反引号包裹，作用与双引号近似
echo "value: $val"

a=100
b=20

val=`expr $a + $b`
echo "a+b value: $val"

val=`expr $a \* $b` # \* 为转义字符
echo "a*b value: $val"

if [ $a != $b ] # []内部必须有空格，运算符两边必须有空格
then
   echo "a not equal to b"
fi
```

| 运算符 | 说明                                          | 举例                       |
| :----- | :-------------------------------------------- | :------------------------- |
| +      | 加法                                          | `expr $a + $b`             |
| -      | 减法                                          | `expr $a - $b`             |
| *      | 乘法                                          | `expr $a \* $b`            |
| /      | 除法                                          | `expr $a / $b`             |
| %      | 取余                                          | `expr $a % $b`             |
| =      | 赋值                                          | a=$b 把变量 b 的值赋给 a。 |
| ==     | 相等。用于比较两个数字，相同则返回 true。     | [ $a == $b ]               |
| !=     | 不相等。用于比较两个数字，不相同则返回 true。 | [ $a != $b ]               |



### 关系运算符

| 运算符 |                    说明                     |
| :----: | :-----------------------------------------: |
|  -eq   |          equal，检测两个数是否相等          |
|  -ne   |       not equal，检测两个数是否不相等       |
|  -gt   |   great than，检测左边的数是否大于右边的    |
|  -lt   |    less than，检测左边的数是否小于右边的    |
|  -ge   | great equal，检测左边的数是否大于等于右边的 |
|  -le   | less equal，检测左边的数是否小于等于右边的  |



## 管道符

> 管道符，表示把前一个命令的输出作为后一个命令的输入。用于数据在不同的命令之间传输，可以减少硬盘存取损耗。

### 管道符应用示例

#### **重定向+管道符 将所有IO重定向到文件**

```bash 
ls -al &>> output.txt | 
echo "output" &>> output.txt | 
ls unknown/path &>> output.txt
```





## 函数





## 让我们来写一个Shell脚本吧

大家平时在完成程序作业后，时常需要将文件打包成学号+姓名的zip文件格式，那么我们能否写一个 Shell 脚本，它能够在我们输入指定路径后，将需要的文件打包为指定名称的zip文件