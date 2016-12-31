#include <iostream>
#include <string>

void get_z_arr(const std::string & str, int * Z)
{
    int n = str.length();
    int L,R,k;
    L = R = 0;
    for(int i=1;i<n;++i)
    {
        if(i>R)
        {
            L = R = i;
            while(R<n && str[R-L] == str[R])
            {
                ++R;
            }
            Z[i] = R-L;
            --R;
        }
        else
        {
            k = i - L;
            if(Z[k]<R-i+1)
            {
                Z[i] = Z[k];
            }
            else
            {
                L = i;
                while(R<n && str[R-L]==str[R])
                {
                    ++R;
                }
                Z[i] = R-L;
                --R;
            }
        }
    }
}

void search(const std::string & text, const std::string & pattern)
{
    std::string concat = pattern+"$"+text;
    int len = concat.length();

    int * Z = new int[len];
    get_z_arr(concat,Z);

    for(int i=0;i<len;++i)
    {
        if(Z[i] == pattern.length())
        {
            std::cout<<i-pattern.length()-len<<std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    char str[]="Geek for Geeks.";
    search(str,"Geek");
    return 0;
}
