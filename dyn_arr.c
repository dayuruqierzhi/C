/* dyn_arr.c -- 动态分配数组 */
#include <stdio.h>
#include <stdlib.h> /* 为 malloc()、free()提供函数原型 */
int main(void)
{

    double * ptd;
    int max;
    int number;
    int i = 0;
    puts("What is the maximum number of type double entries?");
    if (scanf("%d", &max) != 1)
    {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }
    ptd = (double *) malloc(max * sizeof(double));
    if (ptd == NULL)
    {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    /* ptd 现在指向有max个元素的数组 */
    puts("Enter the values (q to quit):");
    while (i < max && scanf("%lf", &ptd[i]) == 1)
    ++i;
    printf("Here are your %d entries:\n", number = i);
    
    /*这一部分实现换行打印是比较有用的，每7个数打印一个换行,*/
    for (i = 0; i < number; i++)//注意循环出来的时候，i=number.
    {
        printf("%7.2f ", ptd[i]);
        if (i % 7 == 6)//如果是7位数中的最后一位，那么打印一个换行，此时的i结束循环刚好为7的倍数，即%7=0，此时不再需要打印换行，有了下面那一句。
        putchar('\n');
    }
    if (i % 7 != 0)
    putchar('\n');
    
    puts("Done.");
    free(ptd);
    return 0;
}