# 搜狗面试题总结

1. Fibnacci递归法的时间复杂度是O(2^n)
```
fib(x)=fib(x-1)+fib(x-2);
设fib(x-2)的时间为T1,fib(x-1)的时间是T2,fib(x)的时间是T
T=T1+T2
T1>=T2
T~=2*T2 ==>T(n) = 2(T-1) =...=O(2^n)
```
2. SYN-FLOOD 可以攻击TCP和UDP,clinet丢弃从服务器发来的SYN_ACK报文，导致服务器不断重发报文最终瘫痪
3. cookie是服务器用来验证用户信息，并存放在client上的文件，通过http请求发送到服务器进行验证
为了安全性考虑，不能读取所有cookie
