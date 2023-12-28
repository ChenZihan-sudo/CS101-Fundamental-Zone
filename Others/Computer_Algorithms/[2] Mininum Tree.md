## (最小)生成树

https://zhuanlan.zhihu.com/p/136387766

目标：到每个节点使连线长度总权重最短

- 不存在环

- n个顶点的连通图(可到达图内任意顶点)，包含n个顶点和n-1条边

- 最小生成树->带权图，使得权值之和最小

![v2-b0b4cf080ce7b65c245bf5360fd576dc_1440w](/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Algorithm/pics/v2-b0b4cf080ce7b65c245bf5360fd576dc_1440w.webp)

### 成环判断、安全边

- 终点：与某个节点连通的最大节点

### 克鲁斯卡尔(Kruskal)算法

- 使用贪婪方法的最小生成树算法
- 从最小权重边开始连接，若边成环，则丢弃

```pseudocode
G = (V,E)

Kruskal(G,w)
	A = NULL # 生成树边的集合
	for each vertex v in G.V
		MAKE-SET(v)
	sort the edges of G.E in nondecreasing order by weight w
	for each edge(u,v) in G.E, taken in nondecreasing order by weight w
		if FIND-SET(u) ≠ FIND-SET(v)
			A = A + {(u,v)} # 将边加入生成树的集合
			UNION(u,v) # 将两棵树合并
```

### 普里姆(Prim)算法

- 从源点开始连接
- 从源点开始寻找权重最小的边进行连接
- 和Dijkstra算法类似
- 时间复杂度$O(ElgV)$(二叉最小堆)

![image-20231222164012148](/Users/catcolia/Library/Application Support/typora-user-images/image-20231222164012148.png)

```pseudocode
G = (V,E)
Prim(G,w,r)
	for each vertex u in G.V
		u.key = ∞
		u.π = NULL
	r.key = 0
	Q = G.V # 最小优先队列
	while Q ≠ NULL
		u = EXTRACT-MIN(Q)
		for each v in G.adj[u]
    	if v in Q and w(u,v)<v.key
    		v.π = u
    		v.key = w(u,v)
```
