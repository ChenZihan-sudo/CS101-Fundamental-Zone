## 物理层  

### 数字编码

#### 归零编码

- 带时钟同步

#### 非归零编码(NRZ)

#### 反向非归零编码(NRZI)

在每个时钟周期的起始，跳变则说明该比特是0，不跳变则说明该比特是1。

#### 曼切斯特编码，差分曼切斯特编码

> https://blog.csdn.net/qq_37790902/article/details/79616450

[^曼切斯特编码]: 1代表从高到低，0代表从低到高
[^差分曼切斯特编码]: 第一个编码与曼切斯特编码相同。在每个时钟周期的起始，跳变则说明该比特是0，不跳变则说明该比特是1。



### 概念

#### 波特率，比特率

波特率 是每秒可能发生的信号变化次数

$波特率 = 比特率/每码元所含比特个数$

一个码元含有k比特信息量，则码元需要的不同离散值为$n = 2^k$



波特率等于调制速率

调制速率 指的是信号被调制以后在单位时间内的变化，即单位时间内载波参数变化的次数

它是对符号传输速率的一种度量，1波特即指每秒传输1个符号。 波特率（Baud rate）等于调制速率。

#### 调制与解调

[^调制]: 数字信号转换到模拟信号
[^解调]: 模拟信号转换到数字信号



### 奈奎斯特定理

$$
极限传输速率 = 2Wlog_2{V} \\ W:理想低通信道的带宽 \\ V:每个码元离散电平数目
$$

### 香农定理

$$
信道极限传输速率 = Wlog_2(1+S/N) \\ W:理想信道的带宽 \\ S:信道传输信号的平均功率 \ N:信道高斯噪声功率 \\ S/N:信噪比
$$


$$
信噪比(dB) = 10log_{10}(S/N) 
$$



### Q&A

#### 1. 求解分组交换数据传输时间？

分组在路由转发时间：一个分组数据大小/传输速率

$数据传输时间 = 数据大小/传输速率 + 路由转发数*分组在路由转发时间$

#### 2. 奈奎斯特和香农定理同时限制速率时，取两定理中最小的传输速率

#### 3. 电路交换，报文交换和分组交换

电路交换，无差错控制，通信时延小

分组交换，相比报文交换，传输单位更小，限制最大传输单元

分组交换：数据报 虚电路