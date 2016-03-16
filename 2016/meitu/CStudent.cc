/** 拷贝构造函数和赋值构造
 */
#include <iostream>
#include <cstring>

#include <algorithm>

class CStudent{
    public:
        CStudent(const char *pName,int id):m_ID(id){
            //增加空指针判断
            if(pName!=NULL){
                int len = strlen(pName);
                m_pName = new char[len+1];
                strcpy(m_pName,pName);
            }else{
                //是空指针,置为空，避免析构函数异常
                m_pName = NULL;
            }
        }

        void setID(int id){m_ID = id;}
        int getID(){return m_ID;}

        void setName(const char *name){
            if(m_pName!=NULL)
                delete[] m_pName;
            int len = strlen(name);
            m_pName = new char[len+1];
            strcpy(m_pName,name);
        }

        const char *getName(){return m_pName;}

        ~CStudent(){
            if(m_pName!=NULL) delete[] m_pName;
            m_pName=NULL;
        }

        //增加拷贝构造函数和赋值构造函数
        //(赋值构造编译器默认按照拷贝构造实现)
        CStudent(const CStudent& cs)
        {
            CStudent tmp(cs.m_pName,cs.m_ID);
            std::swap(tmp.m_pName,this->m_pName);
            this->m_ID = cs.m_ID;
            //需要将tmp的指针置为空
            tmp.m_pName = NULL;
        }

        //可以不需要
        //测试实现
        CStudent& operator=(const CStudent &cs)
        {

            CStudent tmp(cs);//调用拷贝构造函数
            std::swap(tmp.m_pName,this->m_pName);
            tmp.m_pName = NULL;

            //*this(cs);//不可以如此调用
            return *this;
        }
    private:
        char *m_pName;
        int m_ID;
};

int main(int argc, char *argv[])
{
    CStudent A("xu",1);
    CStudent B("zhang",2);
    CStudent tmp = A;
    tmp.setID(B.getID());

    //可以看出tmp和A的name都指向同一块内存，
    //需要复制内存空间才不会影响
    //增加拷贝构造函数后不影响
    tmp.setName("haha");
    std::cout<<"id:"<<tmp.getID()<<'\t'<<tmp.getName()<<std::endl;
    std::cout<<"id:"<<A.getID()<<'\t'<<A.getName()<<std::endl;

    //测试空指针等情况
    //将成员变量默认为空后运行正常通过
    CStudent C(NULL,0);//程序发生异常，说明strcpy不能传入NULL指针，在构造函数中异常
    const char *p = NULL;//测试是否可以指向空指针,结论:可以

    return 0;
}
