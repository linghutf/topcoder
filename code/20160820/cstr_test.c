#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void test_strstr()
{
    const char * pnull = "";
    char * q = strstr("abc",pnull);
    printf("empty str:%s\n",q);

    q = strstr("abaab","cabc");
    assert(q==NULL);

    printf("normal:%s\n",strstr("abc","bc"));

    char str[]="123";
    char sub[]="2";
    char * p = strstr(str,sub);
    if(p!=NULL)
    {
        printf("%ld\n",p-str);
    }
}


typedef void (*PFunc)();

int main(int argc, char *argv[])
{
    const int N = 16;
    PFunc func[N];
    func[0]=test_strstr;

    int c = atoi(argv[1]);
    func[c]();
    return 0;
}
