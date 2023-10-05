# ROS Tips
http://www.autolabor.com.cn/book/ROSTutorials/
https://www.fishros.org.cn/forum/
https://github.com/zx595306686/sim_demo

## Important hints
### source after roscore
For each terminal, every time start up ROS Master must call this to run correctly:
run `source ./devel/setup.bash`

### Build with compile commands
When using `clangd` or other frontend language server, add `-DCMAKE_EXPORT_COMPILE_COMMANDS=1` to build to generate `compile_command.json`
```bash
catkin_make -DCMAKE_EXPORT_COMPILE_COMMANDS=1
```

### rosdep cannot download default sources list when initialize
use `sudo -E rosdep init` instead.


## ROS install, build, execute and test steps
### Build ROS by source code
https://wiki.ros.org/melodic/Installation/Source


## ROS file system architecture
```text
WorkSpace --- 自定义的工作空间

    |--- build:编译空间，用于存放CMake和catkin的缓存信息、配置信息和其他中间文件。

    |--- devel:开发空间，用于存放编译后生成的目标文件，包括头文件、动态&静态链接库、可执行文件等。

    |--- src: 源码

        |-- package：功能包(ROS基本单元)包含多个节点、库与配置文件，包名所有字母小写，只能由字母、数字与下划线组成

            |-- CMakeLists.txt 配置编译规则，比如源文件、依赖项、目标文件

            |-- package.xml 包信息，比如:包名、版本、作者、依赖项...(以前版本是 manifest.xml)

            |-- scripts 存储python文件

            |-- src 存储C++源文件

            |-- include 头文件

            |-- msg 消息通信格式文件

            |-- srv 服务通信格式文件

            |-- action 动作格式文件

            |-- launch 可一次性运行多个节点 

            |-- config 配置信息

        |-- CMakeLists.txt: 编译的基本配置
```

## ROS Commands

### roscore
`roscore [-p <port number>]`
roscore will start up a ROS Master, a ROS Parameter Server and a rosout

#### [IMPORTANT] Setup
For each terminal, every time start up ROS Master must call this to run correctly:
run `source ./devel/setup.bash`

### roslaunch
`roslaunch <Pack Name> <File Name>`

Launch File Example (.launch):  
**Launch file should be placed in the pack directory**
```xml
<!-- example.launch -->
<launch>
    <!-- For cpp type -->
    <node pkg="pack_ros_test" type="ros_pack_test" name="hello_world_cpp" output="screen" />
    <!-- For python type -->
    <node pkg="pack_ros_test" type="ros_pack_py_test.py" name="hello_world_py" output="screen" />

    <node pkg="turtlesim" type="turtlesim_node" name="turtle_GUI" />
    <node pkg="turtlesim" type="turtle_teleop_key" name="turtle_control" />
</launch>
```
Attributes:  
node ---> 包含的某个节点  
pkg -----> 功能包  
type ----> 被运行的节点文件  
name --> 为节点命名  
output-> 设置日志的输出目标  

### rosrun
`rosrun [--prefix cmd] [--debug] PACKAGE EXECUTABLE [ARGS]`  
rosrun will locate PACKAGE and try to find an executable named EXECUTABLE in the PACKAGE tree. If it finds it, it will run it with ARGS.

### catkin_create_pkg
Creates a new catkin package  
`catkin_create_pkg <pack name> [dependencies [dependencies ...]]`  

```text
usage: catkin_create_pkg [-h] [--meta] [-s [SYS_DEPS [SYS_DEPS ...]]]
                         [-b [BOOST_COMPS [BOOST_COMPS ...]]] [-V PKG_VERSION]
                         [-D DESCRIPTION] [-l LICENSE] [-a AUTHOR]
                         [-m MAINTAINER] [--rosdistro ROSDISTRO]
                         name [dependencies [dependencies ...]]

positional arguments:
  name                  The name for the package
  dependencies          Catkin package Dependencies

optional arguments:
  -h, --help            show this help message and exit
  --meta                Creates meta-package files
  -s [SYS_DEPS [SYS_DEPS ...]], --sys-deps [SYS_DEPS [SYS_DEPS ...]]
                        System Dependencies
  -b [BOOST_COMPS [BOOST_COMPS ...]], --boost-comps [BOOST_COMPS [BOOST_COMPS ...]]
                        Boost Components
  -V PKG_VERSION, --pkg_version PKG_VERSION
                        Initial Package version
  -D DESCRIPTION, --description DESCRIPTION
                        Description
  -l LICENSE, --license LICENSE
                        Name for License, (e.g. BSD, MIT, GPLv3...)
  -a AUTHOR, --author AUTHOR
                        A single author, may be used multiple times
  -m MAINTAINER, --maintainer MAINTAINER
                        A single maintainer, may be used multiple times
  --rosdistro ROSDISTRO
                        The ROS distro (default: environment variable
                        ROS_DISTRO if defined)
```

### catkin_make

### 常用命令
`rostopic list` 列出所有话题  
`rostopic type` 获取消息类型  
`rostopic echo <topic>` 打印话题实时数据  
`rosmsg info` 获取话题格式

### rosbag 
http://wiki.ros.org/rosbag/Commandline  
`rosbag record -a -O <目标文件>` 录制文件  
`rosbag info <bag-files>`  
`rosbag play <bag-files>`  

## ROS Communication 

### Custom data message or data
**Allowed data type:**  
- int8, int16, int32, int64 (unsigned trpe included)  
- float32, float64  
- string  
- time, duration  
- other msg files  
- variable-length array[] and fixed-length array[C]  
- Header  

### Topics communication
```text
        ROS Master (管理者)  

Listener (订阅者)      Talker (发布者)  
```

**Topic communication model**  
RPC: Remote Procedure Call  
<img src="pics/topic%20communication%20model.jpg" width="50%" height="50%"/>

### Service communication
**Service communication model**  
RPC: Remote Procedure Call  
<img src="pics/service%20communication%20model.jpg" width="50%" height="50%"/>

> 1. Client 使用 TCP 与 Server 建立网络连接，并发送请求数据。  
> 2. Server 接收、解析请求的数据，并产生响应结果返回给 Client。  

- 客户端请求被处理时，需要保证服务器已经启动。
- 服务端和客户端都可以存在多个。

### Param communication
参数服务器  
Talker 通过 ROS Master 设置参数  
Listener 通过 ROS Master 获取参数  
http://www.autolabor.com.cn/book/ROSTutorials/di-2-zhang-ros-jia-gou-she-ji/24-can-shu-fu-wu-qi/231-can-shu-fu-wu-qi-li-lun-mo-xing.html  
http://www.autolabor.com.cn/book/ROSTutorials/assets/03ROS%E9%80%9A%E4%BF%A1%E6%9C%BA%E5%88%B603_%E5%8F%82%E6%95%B0%E6%9C%8D%E5%8A%A1%E5%99%A8.jpg

## 进阶
### TF坐标变换

