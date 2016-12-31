/* 识别protobuf关键字 */
%{
#include <stdio.h>
%}
%{
    enum yytokentype {
        NUMBER = 258,
        INT32 = 259,
        UINT32 = 260,
        INT64 = 261,
        UINT64 = 262,
        STRING = 263,
        BYTE = 264,
        EOL = 265
    };
%}

%%
[0-9]+ {yylval = atoi(yytext);return NUMBER;}
int32 {return INT32;}
uint32 {return UINT32;}
int64 {return INT64;}
uint64 {return UINT64;}
string {return STRING;}
byte {return BYTE;}
\n     {return EOL;}
[ \t]  { /* 忽略空白字符 */ }
.     {printf("错误字符:%c\n",*yytext);}
%%

int main(int argc,char *argv[])
{
    int tok;
    while(tok=yylex())
    {
        printf("%d",tok);
        if(tok == NUMBER)
        {
            printf(" = %d\n",yylval);
        }
        else
        {
            printf("\n");
        }
    }
}
