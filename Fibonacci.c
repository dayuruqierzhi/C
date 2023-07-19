#include <stdio.h>

/*斐波那契数列*/
unsigned long Fibonacci(int count);

int main(void)
{
    int count = 0 ;
    unsigned long fib = 0;
    printf("请输入一个正整数(q to quit):");
    while(scanf("%d",&count)==1)
    {
        if(count <= 0)
        {
            printf("请输入一个正整数:");
        }
        else
        fib = Fibonacci(count);

        printf("该值对应的斐波那契数值为:%lu  ",fib);
        printf("请输入下一个数(q to quit):\n");
    }

    printf("Done!\n");
    return 0;

}


unsigned long Fibonacci(int count)
{
    unsigned long fin = 0;
    if((count == 1)||(count ==2))
    {
        fin = 1;
    }
    if(count > 2 )
    fin += (Fibonacci(count -1) + Fibonacci(count -2));

    return fin;
}
