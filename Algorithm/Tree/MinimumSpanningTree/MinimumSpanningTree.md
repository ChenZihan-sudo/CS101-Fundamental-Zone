## (最小)生成树

https://zhuanlan.zhihu.com/p/136387766

- 不存在环

- n个顶点的连通图(可到达图内任意顶点)，包含n个顶点和n-1条边

- 最小生成树->带权图，使得权值之和最小

![v2-b0b4cf080ce7b65c245bf5360fd576dc_1440w](/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Algorithm/pics/v2-b0b4cf080ce7b65c245bf5360fd576dc_1440w.webp)

### 成环判断

- 终点：与某个节点连通的最大节点

### 克鲁斯卡尔(Kruskal)算法

- 使用贪婪方法的最小生成树算法
- 从最小权重边开始连接，若边成环，则丢弃

### 普里姆(Prim)算法