### LD0,QLD0,VLD0

低压差稳压器(LD0，Low Dropout Regulator)

准低压差稳压器(QLD0)，Quasi Low Dropout Regulator)

超低压差稳压器(VLD0，Very Low Dropout Regulator)

### MIPI

CSI: Camera Serial Interface

DSI: Display Serial Interface

### VCC, VDD, AVDD, DVDD, AFVDD, DOVDD, IOVDD

VCC表示给芯片电源供电

VDD表示给芯片中的器件单独供电, 一般VDD＜＝VCC

AVDD表示模拟电压，给芯片中的模拟器件供电，比如camera供电就要用到AVDD

DVDD表示数字电压，给芯片的数字信号供电, 比如０１０１

AFVDD表示auto focus VDD自动对焦电压，是针对一些马达之类的电压

DOVDD, IOVDD 是芯片引脚出来的电压

### YUV

> https://zhuanlan.zhihu.com/p/248116694

YUV4:4:4 YUV4:2:2 YUV4:2:0

Cb、Cr的含义等同于U、V

Y：    灰度值

U,V：色度

最终通过YUV与RGB的转换公式提取出每个像素点的RGB值，然后显示出来

1. YUV 4:4:4采样，每一个Y对应一组UV分量。
2. YUV 4:2:2采样，每两个Y共用一组UV分量。
3. YUV 4:2:0采样，每四个Y共用一组UV分量。