1. 删除linux上的二进制可执行文件
```
find . -exec file {} \; | grep LSB | cut -d: -f1 | xargs rm

LSB: 可执行文件
text:文本文件
```
