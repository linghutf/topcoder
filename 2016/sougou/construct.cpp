#include <iostream>

using namespace std;

class B{
public:
	B(){cout<<"default construct...\n";}
	B(const B& rhs){cout<<"copy...\n";}
	B& operator=(const B &rhs)
	{
		cout<<"= construct...\n";;
		return *this;
	}

	~B()
	{
		cout<<"delete ...\n";
	}
};

B func(const B &b)
{
	return b;
}

int main(int argc, char const *argv[])
{
	B b1,b2;//default,default
	b1=func(b2);//copy,=,tmp object delete
	return 0;//delete,delete
}