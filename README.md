# DES
DES加密算法的实现

主要参考了张宇老师的PPT以及互联网上的一篇博客: http://www.hankcs.com/security/des-algorithm-illustrated.html

实现了通过DES算法进行加密、解密

linux下：

$ gcc des.c main.c -o main

如果您在Windows下编译，删除main.c中的第二行

​```
#include<unistd.h>
​```

并注释掉main函数中出现的所有read函数，替换成相应的get_s函数

并务必确保按64位程序进行编译

欢迎学习交流探讨 QQ私我就行
