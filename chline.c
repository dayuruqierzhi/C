#include <stdio.h>

/*编程练习-----设计一个函数chline(ch, i, j)，打印指定的字符j行i列。在一个简单的驱动程序中测试该函数。*/

void chline(char ch, int i, int j);

int main(void)
{
    char ch;
    int j, i;
    printf("请输入一个字符以及行数列数:");
    scanf("%c%d%d", &ch, &j, &i);
    chline(ch,i,j);

    return 0;
}

/*j行那么j在外围循环*/
void chline(char ch, int i, int j)
{
    int m,n;
    for(m = 0; m < j;  m++)
    {
        for(n = 0; n < i; n++)
        {
            putchar(ch);
        }
        putchar('\n');
    }

    return;
}