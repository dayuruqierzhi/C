/* hello.c -- 把命令行参数转换为数字 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv [])
{
    int i, times;
    if (argc < 2 || (times = atoi(argv[1])) < 1)
    /*
    cd .\C\
    .\hello or .\hello.exe 注意这里的路径表示方法是和linux不一样的
    */  
    printf("Usage: %s positive-number\n", argv[0]);//argv[0]就是该程序的字符串，在这里显示为路径了
    else
    for (i = 0; i < times; i++)
    puts("Hello, good looking!");
    return 0;
}