/**
 * 模板及其特化示例
 */
#include <functional>
template<typename T,class Compare> bool compare(const T& a,const T& b,Compare &c)
{
    return c(a,b)<0;
}

//模板特化
template<> bool compare(const int& a,const int& b,std::less<int> &c)
{
    return c(a,b)<0;
}

//模板偏特化,有没有int都可以
template</*int,*/class Compare> bool compare(const int& a,const int& b,Compare &c)
{
    return c(a,b)<0;
}
