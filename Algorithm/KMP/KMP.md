# KMP算法

https://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html



前缀表达式 Brain-> {B, Br, Bra, Brai}

后缀表达式 Brain-> {rain,ain,in,n}



## Ex: ABCDABD

| 搜索词 |  A   |  B   | C    |    D     |       A       |          B          |              D               |
| :----- | :--: | :--: | ---- | :------: | :-----------: | :-----------------: | :--------------------------: |
| 匹配值 |  0   |  0   | 0    |    0     |       1       |          2          |              0               |
| 前缀式 | NULL |  A   | A,AB | A,AB,ABC | A,AB,ABC,ABCD | A,AB,ABC,ABCD,ABCDA | A,AB,ABC,ABCD, ABCDA, ABCDAB |
| 后缀式 | NULL |  B   | BC,C | BCD,CD,D | BCDA,CDA,DA,A | BCDAB,CDAB,DAB,AB,B | BCDABD, CDABD,DABD, ABD,AD,D |
| 匹配   | NULL | NULL | NULL |   NULL   |       A       |        A,AB         |             NULL             |



## 窗口值: 已匹配字符数-匹配值



Next数组

 
