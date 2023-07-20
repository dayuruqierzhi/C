#include <stdio.h>

//put_put.c -- 用户自定义输出函数

//函数原型
void put1(const char *);
int put2(const char *);

int main(void)
{
    put1("If I'd as much money");
    put1(" as I could spend,\n");
    printf("I count %d characters.\n",put2("I never would cry old chairs to mend."));
    return 0;
}


/* put1.c -- 打印字符串，不添加\n */
void put1(const char * string)/* 不会改变字符串 */
{
    while (*string != '\0')//while (*string) 空字符数值上也是0
    putchar(*string++);
}


/* put2.c -- 类似puts(),打印一个字符串，并统计打印的字符数 */
int put2(const char * string)
{
    int count = 0;
    while (*string) /* 常规用法 */
    {
        putchar(*string++);
        count++;
    }
    putchar('\n'); /* 不统计换行符 */
    return(count);//不包含最后的空字符。
}