/* copy2.c -- 使用 strcpy() */
#include <stdio.h>
#include <string.h> // 提供strcpy()的函数原型
#define WORDS "beast"
#define SIZE 40
int main(void)
{
    const char * orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char * ps;
    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);//这里strcpy返回值为第一个参数字符串的地址。
    //strcpy拷贝时会把最后的空字符也拷贝进来，同样不检查目标数组能否装下要拷贝的字符
    puts(copy);

    puts(ps);//所以这里从copy的第8个最开始打印。
    return 0;
}