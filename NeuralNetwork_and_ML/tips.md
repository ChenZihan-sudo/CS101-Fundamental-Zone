行为识别：

Slowfast

动作，环境

视频 100帧 切割序列 进行预测

Low frame rate -> 环境

High frame rate -> 动作

分类任务



姿态估计：

![image-20231121201607290](/Users/catcolia/Library/Application Support/typora-user-images/image-20231121201607290.png)

目标检测    回归任务



DeepSort:

匹配下一时刻的目标

1. 卡尔曼滤波 重合比例大的 状态估计

2. 卷积特征

混合匹配

![image-20231121202403642](/Users/catcolia/Library/Application Support/typora-user-images/image-20231121202403642.png)



点云分割：逐点的分类->分割



Tesla AI: 

多模态->汇总 

多2D->3D看全局，高维特征

初始化高维的特征空间，特征点，多个不同的模态做投影和映射

BEV鸟瞰图



Transformer: 特征放大

视觉Attention

边界特征 -> 注意力机制 -> 通用方法

减小计算量



GNN: 图神经网络 -> 深色模式？

提取特征

![image-20231121204926414](/Users/catcolia/Library/Application Support/typora-user-images/image-20231121204926414.png)



强化学习.



Segment Anything. 视觉大模型(Simple)

数据最重要 数据闭环



Conv

1D 结构化

2D 图像

3D 视频



分类任务和回归任务？

中心特征和边界特征？

