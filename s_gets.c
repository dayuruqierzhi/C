#include <stdio.h>

/*s_gets()函数实现*/
char * s_gets(char * st, int n);


#define STLEN 10
int main(void)
{
    char words[STLEN];
    puts("Enter strings (empty line to quit):");
    while(s_gets(words, STLEN)!=NULL)
    puts(words);
    puts("Done.");
    return 0;
}


char * s_gets(char * st, int n)
{
    char * ret_val;//fgets()会返回输入的字符串的地址。
    int i = 0;
    ret_val = fgets(st, n, stdin);//如果读到文件结尾标志服就会返回NULL,但是一般的标准输入是不可能读到文件结尾的。

    if (ret_val) // 即，ret_val != NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
        i++;
        if (st[i] == '\n')
        st[i] = '\0';
        else
        while (getchar() != '\n')
        continue;
    }
    return ret_val;
}