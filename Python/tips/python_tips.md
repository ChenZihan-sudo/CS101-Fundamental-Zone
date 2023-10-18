# Python tips

### pip: Could not find a version that satisfies the requirement
**Upgrade your pip module**
https://blog.csdn.net/csdn_am/article/details/79924744

### .pyi file
**Python Interface**

### .pyd file
https://zhuanlan.zhihu.com/p/479371538

### *args 和 **kwargs 的用法
https://blog.csdn.net/GODSuner/article/details/117961990

### * 和 ** 在函数中的参数
https://blog.csdn.net/yilovexing/article/details/80577510


### Python @staticmethod @classmethod @property 用法及区别

# conda
**conda set inactivate base environment**  
conda config --set auto_activate_base false

# pyenv
https://www.cnblogs.com/wangmo/p/12040220.html  
https://zhuanlan.zhihu.com/p/44991667  
使用Pyenv作为Python版本管理工具  
Install: `curl https://pyenv.run | bash`  

```bash
pyenv global <version>
pyenv local <version>
pyenv shell <version>
# 优先级: global > local > shell
```