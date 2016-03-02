#include <iostream>
#include <vector>

using namespace std;

/**
1：array 定义的时候必须定义数组的元素个数;而vector 不需要；且只能包含整型字面值常量，枚举常量或者用常量表达式初始化的整型const对象，
非const变量以及需要到运行阶段才知道其值的const变量都不能用来定义数组的维度.

2：array 定义后的空间是固定的了，不能改变；而vector 要灵活得多，可再加或减.

3：vector有一系列的函数操作，非常方便使用.和vector不同，数组不提供 push——back或者其他的操作在数组中添加新元素，数组一经定义就不允许添加新元素；
若需要则要充许分配新的内存空间，再将员数组的元素赋值到新的内存空间。

4: 数组和vector不同，一个数组不能用另一个数组初始化，也不能将一个数组赋值给另一个数组；
*/
const int maxs = (2<<32);
int main()
{
	vector<int> v(maxs);
	v.push_back(100);
	cout<<v.size()<<','<<v.capacity()<<endl;

	int a[maxs];
	cout<<"Array:"<<sizeof(a)/sizeof(int)<<endl;
	return 0;
}