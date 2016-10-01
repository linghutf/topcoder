1. 删除linux上的二进制可执行文件
``` bash
find . -exec file {} \; | grep LSB | cut -d: -f1 | xargs rm

LSB: 可执行文件
text:文本文件

```

2. conect-proxy
115.156.209.252:9001
192.168.3.5:22

3. mail to sync
- `uuencode infile outfile| mail -s`"mail content." abc@qq.com
- read mail
```
mail
p    : show current mail
l    : list
1~N  : select mail
d    : delete
q    : quit
```
