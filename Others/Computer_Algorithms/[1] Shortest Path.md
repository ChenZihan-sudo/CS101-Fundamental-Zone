# 最短路径

- 加权图
- 有向/无向
- 成环/不成环

目标：节点到另一个节点的最短路径

### 松弛操作

> https://blog.csdn.net/dshf_1/article/details/108144085

在节点$v$上标记($v.d$): 为从节点$s$到节点$v$最短权重值

<img src="https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWM0LnpoaW1nLmNvbS84MC92Mi1jNDU5YzE2Y2JhZGFmYmEyYTJiZThlMjVkOTJjMWMyNl8xNDQwdy5qcGc?x-oss-process=image/format,png" alt="img" style="zoom: 67%;" />

<img src="https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWNiLnpoaW1nLmNvbS84MC92Mi0xMjA1ZmIwMjgyNWU5MjJjOGMxM2I0OGE2MzgxMDI2NV8xNDQwdy5qcGc?x-oss-process=image/format,png" alt="img" style="zoom: 67%;" />

**放松操作：按某种顺序找到节点$s$到节点$v$最终的最短权重值**

- 初始设置标记($v.d$)为$\infty$

- 通过数组存储所有得到的最短路径

<img src="https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMzLnpoaW1nLmNvbS84MC92Mi1iYmYzOWVjYTJmMjdjZjczM2Y0ODczOTFjNGE2NWZiZl8xNDQwdy5qcGc?x-oss-process=image/format,png" alt="img" style="zoom: 67%;" />

最短路径算法主要研究的是放松的顺序

```pseudocode
RELAX(u,v,w)
if v.d > u.d + w(u,v)
	 v.d = u.d + w(u,v)
	 v.π = u
```

### Dijkstra算法

- 输入的边权重为非负值
- 时间复杂度$V^2$

记录前驱节点$v.\pi$  记录节点总权重$v.d$  设置最小优先队列$Q$

```pseudocode
G = (V,E)

Dijkstra(G,w,s)
	for each vertex v in G.V
  	v.d = ∞
		v.π = NULL
  s.d = 0 # s为源节点,设置距离为0
	S = NULL
	Q = G.V
	while Q ≠ NULL
		u = GET_MIN(Q)
		S = S + {u}
		# 对于每个刚从优先队列取出的u,寻找其相邻节点,RELAX
		for each vertex v in G.Adj[u] 
			RELAX(u,v,w)
```

### Bellman-Ford算法

- 允许非负值权重边，可以侦测到
- 时间复杂度$VE$
- 放松边循环$V-1$次

记录前驱节点$v.\pi$  记录节点总权重$v.d$  设置最小优先队列$Q$

```pseudocode
G = (V,E)
Bellman-Ford(G,w,s)
	for each vertex v in G.V
		v.d = ∞
		v.π = NULL
  s.d = 0 # s为源节点,设置距离为0
  for i=1 to |G.V|-1
  	for each edge(u,v) in G.E
  		# 每个顶点数次，对每条边进行RELAX
  		RELAX(u,v,w)
  for each edge(u,v) in G.E
  	# 对每个边，检查是否存在负权重
  	if u.d > v.d + w(u,v)
  		return FALSE
```

### DAG(拓补排序)最短路径算法

```pseudocode
G = (V,E)

DAG-SHORTEST-PATH(G,w,s)
	Toplogical sort of G
	for each vertex v in G.V
		v.d = ∞
		v.π = NULL
  s.d = 0 # s为源节点,设置距离为0
  for each vertex v, taken in toplogical order
		for each vertex v in G.Adj[u]
			RELAX(u,v,w)
```







哈希表



