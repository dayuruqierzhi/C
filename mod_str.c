/* mod_str.c -- 修改字符串 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81
void ToUpper(char *);
int PunctCount(const char *);
int main(void)
{
    char line[LIMIT];
    char * find;
    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n'); // 查找换行符
    if (find) // 如果地址不是 NULL，
    *find = '\0'; // 用空字符替换
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n",PunctCount(line));
    return 0;
}

void ToUpper(char * str)
{
    while (*str)
    {
    *str = toupper(*str);//toupper()将小写字符转换为大写字符，并返回该大写字符。
    str++;
    }
}

int PunctCount(const char * str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))//非标点符号,返回0。
        ct++;
        str++;
    }
    return ct;
}