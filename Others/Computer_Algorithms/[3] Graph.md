# 图

https://www.51cto.com/article/614590.html

https://blog.csdn.net/z13192905903/article/details/103274283

https://blog.csdn.net/qq_43085848/article/details/126395910

## BFS(Breadth First Search) 广度优先搜索

> https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

<img src="https://img-blog.csdnimg.cn/20191127135310793.gif" alt="广度优先遍历BFS动图" style="zoom: 50%;" />

- 使用队列Queue
- Dijkstra算法 Prim算法
- 邻接表时间复杂度$O(|V|+|E|)$  邻接矩阵时间复杂度$O(|V^2|)$

前驱节点 $u.π$    源节点到节点$u$的距离$u.d$

```pseudocode
G = (V,E)
# s为深搜开始的节点
# WHITE not visited
# GRAY  visited, but vertex in queue
# BLACK visited
BFS(G,s)
	create queue Q
	for each vertex v in G.V
		v.π = NULL
		v.d = 0
	s.d = 0
	s.color = GRAY
	EnQueue(Q,s)
	while Q is not empty set
		u = DeQueue(Q)
		for each v in G.Adj[u]
			if v.color == WHITE
				v.π = u
        v.color = GRAY
        v.d = u.d + 1
        EnQueue(Q,v)
    u.color = BLACK
```

- 首先入列源节点，设置$v.d = 0$
- 循环队列直至没有数据，取出节点，寻找相邻节点且未被访问过，
  - 设置前驱节点$v.π = u$ 
  -  $v.d$设置为前驱节点数值+1
  - 设置当前节点被访问过
  - 设置当前节点入列

## DFS(Depth First Search) 深度优先搜索

<img src="https://img-blog.csdnimg.cn/20191127135244696.gif" alt="深度优先遍历DFS动图" style="zoom:50%;" />

- 邻接表时间复杂度$O(|V|+|E|)$  邻接矩阵时间复杂度$O(|V^2|)$

```pseudocode
G = (V,E)

DFS(G)
	for each vertex u in G.V
		u.color = WHITE
		u.π = NULL
	time = 0
	for each vertex u in G.V
		if u.color == WHITE
			DFS-VISIT(G,u)
DFS-VISIT(G,u)
	time = time + 1
	u.d = time
	u.color = GRAY
	for each v in G.Adj[u]
		if u.color == WHITE
			DFS-VISIT(G,u)
	u.color = BLACK
	time = time + 1
	u.f = time
```



## Toplogical Sorting 拓补排序



