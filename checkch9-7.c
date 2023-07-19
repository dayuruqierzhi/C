#include <stdio.h>
#include <ctype.h> //包含判断字符是否是字母的函数原型int isalpha(int c);


/*编写一个函数，从标准输入中读取字符，直到遇到文件结尾。
程序要报告每个字符是否是字母。如果是，还要报告该字母在字母表中的数值位置。
例如，c和C在字母表中的位置都是3。
合并一个函数，以一个字符作为参数，如果该字符是一个字母则返回一个数值位置，否则返回-1*/

int checkch(char ch);
void inputstream(void);


int main(void)
{
    inputstream();

    return 0;
}

/*检测传入字符在字母中的位置*/
int checkch(char ch)
{
    if(ch >= 'a' && ch <='z')
    {
        return ch - 'a' + 1;
    }

    else if(ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 1;
    }
    
    else
        return -1;
}

void inputstream(void)
{
    char inchar,x;
    while((inchar = getchar())!=EOF)
    {
        x = checkch(inchar);
        if(x > 0)
        printf("Is a alpha %c, it's index is %d\n",inchar, x);
    }

    return;
}