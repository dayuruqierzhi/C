/* fgets3.c */
#include <stdio.h>
#define STLEN 10
int main(void)
{
    char words[STLEN];
    int i = 0;
    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
    {
        while(words[i] != '\n' && words[i] != '\0')
        i++;
        if(words[i]=='\n')//说明限制的字符串大小够用，一行输入已经完成
        words[i] = '\0';
        else//说明输入行已经超过限制的范围，还没有将最后的回车给输入到字符串内
        {
            while(getchar()!='\n')
            continue;
        }
        fputs(words, stdout);
    }
    puts("Done.");
    return 0;
}