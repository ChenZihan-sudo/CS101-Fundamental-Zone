# 霍夫曼树（最优二叉树）

https://oi-wiki.org/ds/huffman-tree/



在设计不等长编码时，要考虑解码的唯一性，如果一组编码中任一编码都不是其他任何一个编码的前缀，那么称这组编码为 **前缀编码**，其保证了编码被解码时的唯一性。

霍夫曼树可用于构造 **最短的前缀编码**，即 **霍夫曼编码（Huffman Code）**

## 前缀编码

前缀不重复出现

https://zh.wikipedia.org/zh-hans/%E5%89%8D%E7%BD%AE%E7%A2%BC

前缀编码是指**对字符集进行编码时，要求字符集中任一字符的编码都不是其它字符的编码的前缀**，例如：设有abcd需要编码表示（其中，a=0、b=10、c=110、d=11,则110的前缀表示的可以是c或者是d跟a，出现这种情况是因为d的前缀11与c的前缀110有重合部分，这个是关键。）

**前置码**（英语：Prefix code），又译**前缀码**、**前缀编码**，是一种[编码](https://zh.wikipedia.org/wiki/編碼)系统。这种编码系统通常是可变长度码，在其中的每个码字，都具备“前置性质”（prefix property），也就是说，在编码中的每个码字，都不能被其他码字当成前置部位。举例而言，编码字 `{9, 55}` 具备了前置性质，但编码字 `{9, 5, 59, 55}` 就不具备，因为其中的“5”是“59”及“55”的前置字。这也被称为**无首码的代码**（prefix-free codes，PFC，**无前缀码**）。虽然哈夫曼编码只是派生的前缀码中众多算法之一，但前缀码也被称为广义上的“哈夫曼编码”。对于任何唯一可解编码，都有一个具有相同码字长度的前缀码。[克拉夫特不等式](https://zh.wikipedia.org/wiki/克拉夫特不等式)表征了在唯一可解编码中可能出现的码字长度集。
