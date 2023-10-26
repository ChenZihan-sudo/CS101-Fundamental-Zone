### Remap

`<remap>`将节点发布的话题重映射



下面是两个launch启动两个节点的例子：
一个节点叫pub_node，它发布一个topic名为/pub_data
一个节点叫sub_node，它订阅一个topic名为/sub_data

```xml
重命名一个已经存在的主题：
<!--pub_node.launch-->
<launch>    
    <node pkg="pub_node" type="pub_node" name="pub_node" output="screen">
    <!--pub_node节点发布的topic为/pub_data-->
        <!--将pub_node节点发布的话题/pub_node映射到/talker的名字上去：改名字-->
        <remap from="/pub_data" to="/talker" />        
    </node> 
</launch>

```



```xml
将别人发布的主题映射到自己订阅的主题上：
<!--sub_node.launch-->
<launch>    
    <node pkg="sub_node" type="sub_node" name="sub_node" output="screen">
    <!--sub_node节点需要订阅话题为/sub_data-->
        <!--将别人发布的/talker主题改为sub_node节点订阅的sub_data名字：映射别人给自己用-->
        <remap from="/sub_data" to="/talker" />
    </node>
</launch>

```



### Group

ns namespace命名空间

### Include

包含其他launch文件

Required

### If-unless

### Respawn

Restart the node automatically if it quits.

### Required

If node dies, kill entire roslaunch.

## 静态坐标转换

static_transform_publisher x y z qx qy qz qw frame_id child_frame_id period_in_ms

```en
<node pkg="tf" type="static_transform_publisher" name="link1_broadcaster" args="1 0 0 0 0 0 1 link1_parent link1 100" />
```

![20160912150719773](./pics/20160912150719773.png)

