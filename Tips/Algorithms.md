时间复杂度



O

算法的上限

只保留高阶

**存在n0,C，使得当$$\textcolor{Orange}{n≥n0}$$时，始终存在$$0<f(n)≤c·g(n)$$，则可用$$f(n)=O(g(n))$$表示**

C = O(1) ---> f(n) = C, g(n) = 1 ---> 0<C≤C·1

3C + 2n = O(n) ---> 3C + 2n ≤ Cn

2$$n^2$$ + 3C = O($$n^2$$) ---> 2$$n^2$$ + 3C ≤ C$$n^2$$



o

算法的松上限

**存在n0,对$$\textcolor{Melon}{任意}$$C，使得当$$\textcolor{Orange}{n≥n_0}$$时，始终存在$$0<f(n)<c·g(n)$$，则可用$$f(n)=o(g(n))$$表示**

$$n^2≠o(n^2)$$, f(n) = $$n^2$$, g(n) = $$n^2$$ ---> $$0<n^2<cn^2$$  对于任意c,c≠1时不成立



Θ 

算法从上限到下限

去掉低阶，忽略常数阶



Ω

算法的下限



ω

算法的松下限

**存在n0,对$$\textcolor{Melon}{任意}$$C，使得当$$\textcolor{Orange}{n≥n_0}$$时，始终存在$$0<c·g(n)<f(n)$$，则可用$$f(n)=ω(g(n))$$表示**

$$n^2≠ω(n^2)$$, f(n) = $$n^2$$, g(n) = $$n^2$$ ---> $$0<cn^2<n^2$$  对于任意c,c≠1时不成立



O(n^2)可以是n,2n,1,2n^2等。

Θ(n^2)可以是n^2,3n^2等。

ω(n^2)可以是n^3,n^10等,但不能是n^2。

Ω(n^2)可以是n^2,n^3,n^10等。

o(n^2)可以是n,1,3n等,但不能是n^2



> https://juejin.cn/post/6854573205941092359
>
> https://blog.csdn.net/so_geili/article/details/53353593



递归算法时间复杂度计算

主定理

$$T(n) = aT(n/b) + f(n) \\ a,b≥1$$

> https://blog.restkhz.com/post/how-master-theorem-works

递归树


