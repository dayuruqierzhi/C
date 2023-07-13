// divisors.c -- 使用嵌套if语句显示一个数的约数
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    unsigned long num; // 待测试的数
    unsigned long div; // 可能的约数
    bool isPrime; // 素数标记
    printf("Please enter an integer for analysis; ");
    printf("Enter q to quit.\n");
    while (scanf("%lu", &num) == 1)
    {
        isPrime = true;
        if(num == 1)
        {
            isPrime = false;
            printf("1 is not a prime\n");
        }
else{
        for (div = 2; (div * div) <= num; div++)//判断有没有约数，在for循环的测试表达式中使用了逗号运算符，这样每次 输入新值时都可以把isPrime设置为true
        {
            if ((num % div == 0))//循环过程中发现有约数
            {
                if ((div * div) != num)//如果不是平方本身
                printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
                else
                printf("%lu is divisible by %lu.\n", num, div);
                isPrime = false; // 该数不是素数，一旦进来该for循环就说明岂不是素数
            }
        }

        if (isPrime)
        printf("%lu is prime.\n", num);
        printf("Please enter another integer for analysis; ");
        printf("Enter q to quit.\n");
}
    }
    printf("Bye.\n");
    return 0;
}