#include <iostream>

using namespace std;

class Singleton{
    public:
        virtual ~Singleton(){
            if(instance!=nullptr)
                delete instance;
        };

        static Singleton *getInstance(){
            return instance;
        }

        /*bool operator==(const Singleton &s)
        {
            return instance == s.instance;
        }*/
    private:
        static Singleton *instance = new Singleton;
        Singleton(){}
};

int main(int argc, char *argv[])
{
    Singleton *s = Singleton::getInstance();
    Singleton *t = Singleton::getInstance();

    //std::cout<<*t==*s<<std::endl;
    return 0;
}
