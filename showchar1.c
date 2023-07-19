/* showchar1.c -- 有较大 I/O 问题的程序 */
#include <stdio.h>
void display(char cr, int lines, int width);
int main(void)
{
int ch; /* 待打印字符 */
int rows, cols; /* 行数和列数 */
printf("Enter a character and two integers:\n");
while ((ch = getchar()) != '\n')
{
    if(scanf("%d %d", &rows, &cols)!=2)//这里也是改动的地方
    {
        printf("Can't understand rows and cols.Please try again.\n");
        break;
    }
    display(ch, rows, cols);
      while(getchar()!='\n')//这里是进行改进的地方，上面scanf会将空格无视掉，但是最后的回车键会被最外层的while循环给读入，导致循环退出，所以在display之后将scanf的最后的回车键给消除掉
      continue;//意味着单次循环中，只读入有效的几个键入值
    printf("Enter another character and two integers;\n");
    printf("Enter a newline to quit.\n");
}
printf("Bye.\n");
return 0;
}
void display(char cr, int lines, int width)
{
int row, col;
for (row = 1; row <= lines; row++)
{
for (col = 1; col <= width; col++)
putchar(cr);
putchar('\n');/* 结束一行并开始新的一行 */
}
}

