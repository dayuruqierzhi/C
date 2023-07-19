#include <stdio.h>

/*使用循环以及递归进行结阶乘运算*/
long recur(int n);
long circulation(int n);


int main(void)
{
    int count=0;
    long ans=1;
    printf("请输入要求的阶乘的值count:");
    while(scanf("%d",&count)==1)
    {
        if(count < 1)
        {
            printf("请输入一个正整数:\n");
        }

        else if(count > 12)
        {
            printf("请输入一个1~12的正整数:\n");
        }

        else
        {
            //ans = recur(count);//递归
            ans = circulation(count);//循环
            printf("count的阶乘值为%ld,请输入下一个值\n",ans);
        }

    }
        
    printf("Done!\n");

    return 0;
}


long recur(int n)//递归的方法实现阶乘。
{
    long ans=1;

    if(n>=2)
    ans = n * recur(n-1);

    return ans;
}

long circulation(int n)
{
    long ans = 1;
    while(n--)
    {
        ans *= (n+1);
        //n--;
    }

    return ans;
}
