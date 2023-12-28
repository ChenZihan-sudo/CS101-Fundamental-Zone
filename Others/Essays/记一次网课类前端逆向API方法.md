记一次网课类前端逆向API方法

本次逆向的是一种记录学时的网课，在播放时会不定时弹出答题弹窗打断播放，且播放页面关闭时有一定概率无法记录学习时长，因此通过逆向提交学习时长的API来达到全自动刷课的目的

打开视频页面，观察Network请求

![image-20231130113021768](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130113021768.png)经过多次观察发现，视频播放后若干时间后，会发送postTimeH5请求，之后网课时长会更新，推测此为时长更新请求。发送前伴随一个GetServerTime，其很可能与匹配服务器时间有关，推测其无法无限制地刷时长，只能随正常时间流逝更新刷课时长。

我们多播放一会儿，看看请求有什么规律

<img src="/Users/catcolia/Library/Application Support/typora-user-images/image-20231130120705358.png" alt="image-20231130120705358" style="zoom:33%;" />

看起来每次时长更新请求间隔是200s左右

![image-20231130112526119](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130112526119.png)继续深入postTimeH5请求，观察Headers和Payload可知其发送POST请求，需要videoID,studyID,userID,courseID,key,hs,playTime,innerTime,isEnded参数，发送请求需要的数据参数均来自前端合成，因此追溯前端源文件获取或合成这些参数是可能的。

<img src="/Users/catcolia/Library/Application Support/typora-user-images/image-20231130113151972.png" alt="image-20231130113151972" style="zoom:50%;" />

观察可知hs字段是一个毫秒为单位的时间戳，且与之前的GetServerTime相同。

innerTime这个字段是180，我们和上一个GetServerTime请求对比，发现其正好相差180s，与我们之前判断的200s左右正好相同。

继续深入，在Source内查找前端源码，我们只看主站，可以看到其分成了html和静态资源两部分，继续深入静态资源js部分，逐文件搜索包含请求参数的字段，如videoID,studyID,userID等，最终只在一个混淆文件内发现了相关字段。

![image-20231130113625424](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130113625424.png)![image-20231130114049463](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130114049463.png)

这种混淆程度看起来不是很高，而且字段均暴露在外，因为我们随便找几个js混淆解码网站尝试一下......我去，解出来了！

<img src="/Users/catcolia/Library/Application Support/typora-user-images/image-20231130114429548.png" alt="image-20231130114429548" style="zoom: 33%;" />

稍微格式化整理一下代码，直接追溯请求位置

![image-20231130115713696](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130115713696.png)

找到了！现在去溯源参数

首先是videoID，我们一步一步溯源，可以看到videoID来自videoModel，好像是一个模块

<img src="/Users/catcolia/Library/Application Support/typora-user-images/image-20231130120006576.png" alt="image-20231130120006576" style="zoom:50%;" />

前面这一块define中形如h5/xxx看起来是从其他地方导入的，我们问问copilot这是做什么的

![image-20231130115020666](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130115020666.png)

![image-20231130115128864](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130115128864.png)

那接下来我们去Console尝试移入这些模块，看看这些模块含有的功能能否使用

![image-20231130121234660](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130121234660.png)

看起来是可以的！我们接下来按照相同的套路揪出来userID,studyID,courseID

![image-20231130121826301](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130121826301.png)

现在我们还缺少，key,hs,playTime,innerTime,isEnded没有找到，key字段是有MD5值合成的，这一步骤比较杂糅，我们最后再完成，我们先来找isEnded

![image-20231130122316488](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130122316488.png)

由此可以得知isEnded为Boolean，不同场景下saveData请求不同

接着是playTime，可以stats模块中获取

![image-20231130122615493](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130122615493.png)

还剩下innerTime,hs,key，字段部分我们就快要完成了！

根据之前的分析，我们知道innerTime是180，这一字段是由上一次请求和现在请求的差值计算而来的，这意味着这一字段就是要添加的学习时长，是可控变量，可惜有serverTime服务器时间的自然流逝时间控制，不然的话我们可以无限的增加学习时长！

根据前面的分析，hs是服务器时间戳，我们需要在发送添加学习时长请求前请求获取服务器时间戳，我们追溯serverTime，不难发现

![image-20231130123415048](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130123415048.png)

其通过ajax发送了获取serverTime的请求，我们还差发送请求的目的地URL，即basePath+postDataUrl

![image-20231130123714823](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130123714823.png)

这里我们获取到了所有url，因此后文不再赘述，我们发送请求试一下

![image-20231130124016316](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130124016316.png)                                                        

可以看到获取成功了！

我们最后还差key，这也是我们最后的步骤了

![image-20231130135503907](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130135503907.png)

这里的key就是keyMd5Str，keyStr由一系列字符串构成，postTimeKey可以通过上述方法获取。hex_md5的引用并没有在此源码中找到，因此去往实际页面的Console查找，看其是否为全局变量

![image-20231130135851906](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130135851906.png)

果然是一个全局变量，至此合成API所需的所有参数都已找到了，简单写一个测试代码尝试一下

![image-20231130140321496](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130140321496.png)

这里postMD5的innerTime参数是提交学习时长的时间，看起来提交1s是可以做到的，但是时间长了就会提示不能同时学习，推测提交后服务器会计算时间间隔，如果提交的学习时长超过自然时间流逝的间隔一定范围，那么就提交失败。

因此我们可以设置其与自然流逝时间相同的interval，这样即可保证时间的一致性

![image-20231130141041519](/Users/catcolia/Library/Application Support/typora-user-images/image-20231130141041519.png)

The End.