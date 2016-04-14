#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Person{
    public:
        Person(){}
        Person(int id_,const string& name_):id(id_),name(name_){}
    protected:
        int id;
        string name;
        bool sign;
        int signtime;
};

class Employee:public Person{
    public:
        Employee(int id_,const string& name_):Person(id_,name_){}
        bool isSign(){return this->sign;}
};

class Leader:public Employee{
    public:
        Leader(int id_,const string& name_):Employee(id_,name_){}
};

class Sign{
    public:
        Sign(long time):time_(time){}
    private:
        long time_;
        vector<Person*> singmap;
};

int main()
{
    Leader *pl = new Leader(12,"张");
    if(pl->isSign())
        cout<<"YES"<<endl;
    delete pl;
    return 0;
}
