/* strptr.c -- 把字符串看作指针 */
#include <stdio.h>
int main(void)
{
printf("%s, %p, %c\n", "We", "are", *"space farers");//这里的演示方式
return 0;
}