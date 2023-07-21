/* repeat.c -- 带参数的 main() */
#include <stdio.h>
int main(int argc, char *argv [])//argc(argement count 参数数量) argv(参数列表/参数值 argement vetor/value)  字符串数组，用空格隔开各字符串
{
    int count;
    printf("The command line has %d additional arguments:\n", argc - 1);
    for (count = 1; count < argc; count++)
    printf("%d: %s\n", count, argv[count]);
    printf("\n");
    return 0;

}
