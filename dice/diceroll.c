#include <stdio.h>
#include <stdlib.h>//包含ANSI标准C语言的随机数函数rand()


int roll_count = 0; /* 外部链接 */

/*
输入参数:随机的范围例如1~6就输入6
输出参数:返回该范围内的随机数
*/
static int rollem(int sides)  //static的使用，限制该函数为内部链接，只在本文件中可以被调用
{
    int roll;
    roll = rand() % sides + 1;
    roll_count++;
    return roll;
}

/*多骰子的情况*/
long roll_n_dice(int dice, int size)
{
    unsigned long total = 0;
    unsigned long choice = 0; 
    int i = 0;
    if(size < 2){
        printf("Need at least sizes\n");
        return -1;
    }

    if(dice < 1){
        printf("Need at least 1 dice\n");
        return -2;
    }

    for(i; i < dice; i++)
    {
        choice = rollem(size);
        total +=  choice;
        printf("Dice[%d] is :%ld\n",i+1,choice);
    }
    printf("Final total is %ld\n",total);
    return total;
}
