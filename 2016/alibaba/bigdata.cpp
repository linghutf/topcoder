#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

#include <ctime>
#include <cstdlib>

using namespace std;

const int MAXL = 10000000;
const float CLOCK_PER_MILLSECOND = 1000.0;
const string CHAR="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct Stu{
	string name;
	string id;
	string sex;

	bool operator==(const Stu &s)
	{
		return this->name == s.name && this->id == s.id;
	}

	bool operator<(const Stu &s)
	{
		return this->name<s.name;
	}
};

typedef map<string,int> Map;
typedef unordered_map<string,int> HashMap;

bool randSelect(string &dst)
{
	dst.clear();
	//string 不能没有定义长度就使用
	int len = rand()%CHAR.size();
	string s(len,'0');
	for(int i=0;i<len;++i)
		dst.push_back(CHAR[rand()%CHAR.size()]);
	return true;
}

/*
无序map插入比有序快很多，因为有序map每次插入都要维持有序，维持红黑二叉树平衡
*/
void insert_test(Map &m,HashMap &hashmap,int times)
{
	srand(time(NULL));
	// Stu *p=new Stu;
	string s;

	time_t start,end;
	time(&start);
	for(int i=0;i<times;++i){
		randSelect(s);
		m[s]++;
	}
	time(&end);
	cout<<"map insert time:"<<end-start<<endl;

	time(&start);
	for(int i=0;i<times;++i){
		randSelect(s);
		hashmap[s]++;
	}
	time(&end);
	cout<<"hashmap insert time:"<<end-start<<endl;

}

/**
无序查找：key->hash(key) 运算进行查找，
有序查找：红黑树查找，目前来说最快的查找lg(N)

无序比有序快，无序：无碰撞条件是常数时间，有序：lg(N)

无序比较消耗内存
数据量很大

除了要使用有序关联容器，其他情况都应该使用无序map

*/
void search_test(Map &m,HashMap &hashm,const string &key)
{
<<<<<<< Updated upstream
	clock_t start,end;
    start=clock();
    if(m[key]!=0){
        end = clock();
        cout<<"Map found,search time:"<<(end-start)/CLOCK_PER_MILLSECOND<<endl;
    }
    start = clock();
    if(hashm[key]!=0){
        end = clock();
		cout<<"HashMap found,search time:"<<(end-start)/CLOCK_PER_MILLSECOND<<endl;
=======
	time_t start,end;
	start=clock();
	if(m[key]!=0){
		end=clock();
		cout<<"Map found,search time:"<<(end-start)/CLOCK_PER_SECOND<<endl;
	}
	start=clock();
	if(hashm[key]!=0){
		end=clock();
		cout<<"HashMap found,search time:"<<(end-start)/CLOCK_PER_SECOND<<endl;
>>>>>>> Stashed changes
	}
}

void foreach_test(Map &m,HashMap &hash)
{
    clock_t s,e;
    s = clock();
    for(auto it=m.begin();it!=m.end();++it);
    e = clock();
	cout<<"Map,foreach time:"<<(e-s)/CLOCK_PER_MILLSECOND<<endl;

    s=clock();
    for(auto it=hash.begin();it!=hash.end();++it);
    e=clock();
	cout<<"HashMap,foreach time:"<<(e-s)/CLOCK_PER_MILLSECOND<<endl;
}
int main(int argc, char const *argv[])
{
	Map m;
	HashMap hashmap;
	insert_test(m,hashmap,MAXL);
	search_test(m,hashmap,"ac");
    foreach_test(m,hashmap);
	return 0;
}
