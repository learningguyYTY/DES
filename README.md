# DES
DES加密算法的实现

主要参考了张宇老师的PPT以及互联网上的一篇博客: http://www.hankcs.com/security/des-algorithm-illustrated.html

实现了通过DES算法进行加密、解密，密钥可以选择由随机生成或是自己给定

您也可以根据自己的需求自己实现main函数

在您自己实现main函数中应首先调用initialize()函数为明文、密文、子密钥在堆上分配空间

再给定一个key(直接给定或随机生成一个)，并调用generate_subkeys(key)生成子密钥

linux下：

```
$ gcc des.c main.c -o main
```

如果您在Windows下编译，删除main.c中的第二行

​```
#include<unistd.h>
​```

并注释掉main函数中出现的所有read函数，替换成相应的get_s函数

并务必确保按64位程序进行编译

如果您在Windows下编译，请务必确保按64位程序进行编译，否则应该会在一些指针与long型转换等过程中出现错误

欢迎学习交流探讨 QQ私我就行

HIT 羿天阳
