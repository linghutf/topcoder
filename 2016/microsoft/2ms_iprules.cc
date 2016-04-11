/*
 *
 * ip 访问规则
 * 第一步:将ip转换成二进制串,分为不同类型
 *        如有前缀长度，则保留一定前缀
 *        注意区分前缀长度为1和0的情况
 *
 * ip:点分十进制，字符串分割，转化成二进制串
 *
 *
 * 第二步:根据所给的IP地址，在保存的规则中
 *        选取匹配长度最长的那条规则，来确
 *        定禁止还是允许访问
 *
 * 如果没有查找到:按照第一条默认规则(前缀码为0)
 *
 */
#include <iostream>
#include <algorithm>
//#include <unordered_map>

#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define ISONE 100
#define ISZERO 110
#define MAXN 32
#define HAVM 120
#define COMMON 130
#define ALLOW 50
#define DENY 60


struct Type {
	int type;
	int r;
    Type():type(-1),r(-1){}
};

struct Rule{
    string ip;
    Type mark;
    Rule(string& s,Type m):ip(s),mark(m){}

};
//typedef unordered_map<string, Type> Map;

typedef vector<Rule> Map;

string DectoBin(string& s)
{
	stringstream ss;
	int n;
	ss << s;
	ss >> n;
	string out(8, '0');
	int a, i = 7;
	do {
		a = n % 2;
		out[i--] = '0' + a;
		n /= 2;
	} while (n);
	return out;
}

void split(std::vector<std::string> &v, std::string str, std::string pattern)
{
	string::size_type pos;
	//std::vector<std::string> result;
	str += pattern;//扩展字符串以方便操作
	int size = str.size();

	for (int i = 0; i<size; i++)
	{
		pos = str.find(pattern, i);
		if (pos<size)
		{
			std::string s = str.substr(i, pos - i);
			v.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}

}
//计算网址的bit,根据len前位
std::string ipStrToBits(string s)
{
	vector<string> v;
	split(v, s, ".");
	string t;
	string out;
	for (int i = 0; i < v.size(); ++i) {
		t = DectoBin(v[i]);
		out.append(t);
	}
	return out;
}

//测试ip前缀是否相同
//比较0个字符时为真
bool isEqual(const string& rule, string& ip, int len) {
	return (rule.compare(0, len, ip, 0, len) == 0);
}

//获取符合的规则
//选取最长匹配---关键
//0.0.0.0/0匹配任何地址，但是是最终其他规则都不匹配时
//
bool GetRule(Map& map, string t)
{
    int maxlen = 0;//记录最长匹配
    Type maxt;//记录最长匹配的类型

	for (Map::iterator it = map.begin(); it != map.end(); ++it)
	{
		int len;
        //相同规则情况下只找到第一个匹配位置
		switch (it->mark.type) {
		case ISONE://前缀长度为1，避免和完全匹配的结果混淆
			len = 1;
            if (isEqual(it->ip, t, len)){
                if(maxlen <= len){
                    maxlen = len;
                    maxt.r = it->mark.r;
                }
            }
            break;
		case ISZERO://网络段数为0,肯定匹配,因此多个相同规则下，肯定匹配了多次,以最后一个更新规则
			if (isEqual(it->ip, t, 0)){
                if(maxlen <= 0){
                    maxlen = 0;
                    maxt.r = it->mark.r;
                }
            }
			break;
		case COMMON://完全比较
			if (isEqual(it->ip, t, MAXN)){
                if(maxlen <= MAXN){
                    maxlen = MAXN;
                    maxt.r = it->mark.r;
                }
            }
			break;
		default://hav mask,type中是比较的长度
			if (isEqual(it->ip, t, it->mark.type)){
                if(maxlen <= it->mark.type){
                    maxlen = it->mark.type;
                    maxt.r = it->mark.r;
                }
            }
		}
	}
    //查看最长匹配的规则
    //cout<<"LEN:"<<maxlen<<endl;//匹配正确

    //匹配全0时,使用默认规则
    //在循环体中已经更新,因此不需要

    /*
    if(maxlen==0){
        maxt.r = map[default_rule_idx].mark.r;
    }
    */
	return maxt.r==ALLOW;
}

void testcase()
{
	int m, n;
	cin >> m >> n;
	int i;
	string rule, ipstr;
	int r = -1;
	vector<int> rules;
	vector<string> ipstrs;
	vector<string> tests;

	for (i = 0; i < m; ++i) {
		cin >> rule >> ipstr;
        //规则
		if (rule.compare("allow")==0) r = ALLOW;
		else if(rule.compare("deny")==0) r = DENY;

		rules.push_back(r);
		ipstrs.push_back(ipstr);
	}
	for (i = 0; i < n; ++i) {
		cin >> ipstr;
		tests.push_back(ipstr);
	}

	int idx;
	int len;
	stringstream ss;
	Map map;
	string result;
	Type type;
	for (i = 0; i < m; ++i) {
		len = 0;
		ipstr = ipstrs[i];
		idx = ipstr.find('/');
        //如果有前缀长度
		if (idx != string::npos) {
			ss << ipstr.substr(idx + 1);
			ss >> len;
			ss.clear();
			result = ipStrToBits(string(ipstr.substr(0, idx)));
			//两种特殊情况
            if (len == 1) type.type = ISONE;
			else if (len == 0)
                type.type = ISZERO;
			else type.type = len;
		}
		else {
			result = ipStrToBits(ipstr);
			type.type = COMMON;
		}
		type.r = rules[i];
		//map[result] = type;
        map.push_back(Rule(result,type));
	}

	for (i = 0; i < n; ++i) {
		result = ipStrToBits(tests[i]);

		if (GetRule(map, result))
			cout << "YES" << endl;
		else
			cout << "No" << endl;
	}
}

int main()
{
	testcase();
	return 0;
}

