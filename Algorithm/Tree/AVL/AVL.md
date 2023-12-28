# AVL Tree

> https://www.cnblogs.com/leipDao/p/10097001.html

在插入位置找平衡因子至`|b|=2`，此为最小不平衡树

### 平衡因子

> https://blog.csdn.net/Travelerwz/article/details/52186357

<img src="https://img-blog.csdn.net/20160811205300657?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom:75%;" /> 

### 不平衡情况

#### L-L case (Do Right Rotation)

对最小不平衡树根节点进行旋转操作

 ![v2-eee97a3e3e45d8cb6668841f6b44191a_1440w](https://pic3.zhimg.com/80/v2-eee97a3e3e45d8cb6668841f6b44191a_1440w.webp)

![img](https://mmbiz.qpic.cn/mmbiz_png/DA2c4JxxnnZjlfBw8SrJVicR7SoicVQMnnW5z3b3V1tNw1yticzjjDNPfbsLCTupOL5jAAskxDpNaQGhicGXtzm6mA/640?wx_fmt=png)

![img](https://mmbiz.qpic.cn/mmbiz_png/DA2c4JxxnnZjlfBw8SrJVicR7SoicVQMnnibllCCicvW8bnAjWtRb8abD4OgJ3avkOERde5ibFMR17Q7Q8YJyjyeiaGw/640?wx_fmt=png) 

#### R-R case (Do Left Rotation)

对最小不平衡树根节点进行旋转操作

#### ![v2-0a737f5850ac96deec1821c80391a08a_1440w](https://pic3.zhimg.com/80/v2-0a737f5850ac96deec1821c80391a08a_1440w.webp)

![img](https://mmbiz.qpic.cn/mmbiz_png/DA2c4JxxnnZjlfBw8SrJVicR7SoicVQMnn3259SVE6hAFsXnGtM6TJM6HsiaXBVN6h4fGKtw1ezKVfz0VBbynxbjA/640?wx_fmt=png)

#### R-L case (Do Right-Left Rotation)

对最小不平衡树根节点的`下一节点`进行旋转操作

![img](https://mmbiz.qpic.cn/mmbiz_png/DA2c4JxxnnZjlfBw8SrJVicR7SoicVQMnnhxWuzoqfRVFsdbaqB5Lwe9P9BbjY8Xsr4Ned0YZ9EMfrcATNaobjcw/640?wx_fmt=png)

![img](https://mmbiz.qpic.cn/mmbiz_png/DA2c4JxxnnZjlfBw8SrJVicR7SoicVQMnn03pxiatsRicj1tTVUg5UflyAVgc0VLkMscLafLicRiaUG1RX6dpy514xow/640?wx_fmt=png)

![img](https://mmbiz.qpic.cn/mmbiz_png/DA2c4JxxnnZjlfBw8SrJVicR7SoicVQMnnJUDYL6SUzjJ4tuSYTpibFPCcgAPFlbPv7qk42p2Yl9oukk8NIiaDIsXA/640?wx_fmt=png)

#### L-R case (Do Left-Right Rotation)

对最小不平衡树根节点的`下一节点`进行旋转操作

![img](https://mmbiz.qpic.cn/mmbiz_png/DA2c4JxxnnZjlfBw8SrJVicR7SoicVQMnnMxRyen30clVfLhmwVM5V4q9m6ba5vK0DA8ecLXib89yIyoZZ7Yd9e2Q/640?wx_fmt=png)

![img](https://mmbiz.qpic.cn/mmbiz_png/DA2c4JxxnnZjlfBw8SrJVicR7SoicVQMnnWN19P2xV9Tkr8O1iceyVdZNVztiaGrebCZIIdke93z7lUhsLm3Ypia2iag/640?wx_fmt=png)

![img](https://mmbiz.qpic.cn/mmbiz_png/DA2c4JxxnnZjlfBw8SrJVicR7SoicVQMnnJygXJX4C92T328rtNEkp1gAD3KJa1nTEQ33BAQlQU2ibWuicFycSJCibA/640?wx_fmt=png)