/* rand0.c --生成随机数*/
/* 使用 ANSI C 可移植算法 */
#include <stdio.h>

unsigned int rand0(void);
void seed(unsigned long buf_next);//给种子赋值

static unsigned long next = 1; /* 种子 */

int main(void)
{
    int count;
    unsigned long buf_next;
    printf("please enter a seed(q to quit)\n");
    while(scanf("%ld",&buf_next)==1)
    {
        seed(buf_next);
        for (count = 0; count < 5; count++)
        printf("%d\n", rand0());
        printf("please enter next seed(q to quit)\n");
    }
    printf("Done!\n");
    return 0;
}


unsigned int rand0(void)
{
    /* 生成伪随机数的魔术公式 */
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;

}

void seed(unsigned long buf_next)//给种子赋值
{
    next = buf_next;//因为是静态变量，所以不需要用返回值传参
    return;
}
