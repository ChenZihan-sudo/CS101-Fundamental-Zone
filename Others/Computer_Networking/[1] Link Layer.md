# Link Layer

### 多路访问链路和协议

#### 信道划分协议

##### FDM

##### TDM



#### 随机接入协议

---

##### 时隙ALOHA

N个节点，传输概率为P，传输效率：$Np(1-p)^{N-1}$

$N->\infty,\ 最大效率\ \frac{1}{e} = 0.37$



##### 纯ALOHA

传输效率比时隙ALOHA慢2倍

---

##### 载波侦听多路访问(CSMA)

[^冲突发生]: 随机等待一段时间，重新开始监听

| 信道状态 |  1-坚持  |          非坚持          |   p-坚持    |
| :------: | :------: | :----------------------: | :---------: |
|   空闲   | 立即发送 |         立即发送         | 以概率p发送 |
|    忙    | 继续监听 | 放弃监听，随机时间后监听 |  继续监听   |



##### 载波侦听多路访问/冲突检测(CSMA/CD)

- 适用于有线通信

- 先听后发，边听边发，冲突停发，随机重发

[^创建帧]: NIC receives datagram from network layer, creates frame
[^监听信道状态]: If idle: start frame transmission; If busy: wait until channel idle, then transmit
[^保持监听冲突]: If NIC detects another transmission while sending:  abort, send jam signal
[^冲突发生后使用二进制指数后退]: After aborting, NIC enters binary (exponential) backoff

**二进制指数后退(Binary exponential backoff):**

After $m$th collision, NIC chooses K at random from {0,1,2, …, 2$m$-1}. NIC waits K·512 bit times, 
returns to *监听信道状态*



##### 载波侦听多路访问/碰撞避免(CSMA/CA)

- 适用于无线通信

---



#### 轮流协议

---

##### 轮询协议

- 指定主节点，主节点循环轮询每个节点

##### 令牌传递协议

<img src="/Users/catcolia/Library/Application Support/typora-user-images/image-20231220172516315.png" alt="image-20231220172516315" style="zoom:50%;" />

<img src="/Users/catcolia/Library/Application Support/typora-user-images/image-20231220172531895.png" alt="image-20231220172531895" style="zoom:50%;" />



### 以太网,MAC帧,MAC地址

网络适配器(NIC, Network Interface Card)

#### Mac Address(LAN Address, Physical Address)

- 链路层地址
- 6bytes 48bit XX-XX-XX-XX-XX-XX
- 唯一地址，24bit(厂商代码) - 24bit(网卡序列号)
- 广播地址 FF-FF-FF-FF-FF-FF

#### Mac帧

- 无连接
- 不可靠
- Ethernet’s MAC protocol: unslotted CSMA/CD with binary backoff(Binary exponential backoff)

![image-20231220174916941](/Users/catcolia/Library/Application Support/typora-user-images/image-20231220174916941.png)

[^前导码]: 前同步码(7B)和定界符(1B)
[^目的地址，源地址]: Mac地址(6B)
[^协议类型]: 网络层或链路层协议类型(2B)
[^MTU]: 最大传输单元为1500字节
[^校验码(FCS)]: 使用CRC冗余校验(CRC-32bit)

​                                                                                            

### 地址解析协议(ARP, Address resolve protocol)

IP node: host, router

*How to determine interface’s MAC address, knowing its IP address?   **ARP table***

- Each IP node on LAN has ARP table

- IP/MAC address mappings for some LAN nodes: <IP address; MAC address; TTL>

- TTL (Time To Live): time after which address mapping will be forgotten (typically 20 min)

![image-20231220210614246](/Users/catcolia/Library/Application Support/typora-user-images/image-20231220210614246.png)

![image-20231220210754439](/Users/catcolia/Library/Application Support/typora-user-images/image-20231220210754439.png)



**Example: Send datagram from A through R to B.**

![image-20231220210402830](/Users/catcolia/Library/Application Support/typora-user-images/image-20231220210402830.png)

![image-20231220210453744](/Users/catcolia/Library/Application Support/typora-user-images/image-20231220210453744.png)



### Switches vs. routers (交换机vs路由器)

![image-20231220211305955](/Users/catcolia/Library/Application Support/typora-user-images/image-20231220211305955.png)
