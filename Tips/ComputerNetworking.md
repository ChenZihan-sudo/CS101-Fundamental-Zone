

https://blog.csdn.net/weixin_43466526/article/details/108275227

VLAN

使用VLAN可以将网络划分为多个广播域

分割广播域

> https://cloud.tencent.com/developer/article/1412795





集线器、交换机、路由器、网桥、网关之间的区别和联系

依据OSI模型划分

物理层：集线器，中继器

链路层：网桥，交换机（多端口网桥）

网络层：路由器

应用层：网关



> https://zhuanlan.zhihu.com/p/408653152

集线器，放大中继网络

交换机，交换式集线器



广播域 

冲突域 

- 共享同一物理媒介（物理层共享）产生冲突域



物理层（集线器）              不能隔离冲突域  不能隔离广播域

链路层（交换机，网桥）          隔离冲突域  不能隔离广播域

网络层（路由器）                      隔离冲突域          隔离广播域

> https://blog.csdn.net/starter_____/article/details/102609365





ARP 地址解析协议 IP地址转换到物理地址(MAC)

RARP 反地址解析协议 物理地址(MAC)转换到IP地址



ICMP 网络控制信息协议

