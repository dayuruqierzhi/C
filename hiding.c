// hiding.c -- 块中的变量
/*
内层块会隐藏
外层块的定义。但是离开内层块后，外层块变量的作用域又回到了原来的作
用域。
*/
#include <stdio.h>
int main()
{
    int x = 30; // 原始的 x
    printf("x in outer block: %d at %p\n", x, &x);
    {
        int x = 77; // 新的 x，隐藏了原始的 x
        printf("x in inner block: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);
    while (x++ < 33) // 原始的 x
    {
        int x = 100; // 新的 x，隐藏了原始的 x
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);
    return 0;
}