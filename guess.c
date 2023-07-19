/* guess.c -- 一个拖沓且错误的猜数字程序 */
#include <stdio.h>

void improvement(int guess);
void imp_puls(int guess);


int main(void)
{
int guess = 1;
printf("Pick an integer from 1 to 100. I will try to\
guess ");
printf("it.\nRespond with a y if my guess is right and\
with");

printf("\nan n if it is wrong.\n");
printf("Uh...is your number %d?\n", guess);
imp_puls(guess);
    //while (getchar() != 'y') /* 获取响应，与 y 做对比 */
    //printf("Well, then, is it %d?\n", ++guess);
printf("I knew I could do it!\n");
return 0;
}


void improvement(int guess)
{
    while(getchar() != 'y')
    {
        printf("Well, then, is it %d?\n", ++guess);
        while(getchar() != '\n')//键入的后续字符忽视掉，遇到回车键则什么也不做。
        continue;
    }
}

void imp_puls(int guess)//仍旧有一些小bug，只按回车键的话有两个getchar();要按两次回车对应一次循环。
{
    char i;
    while((i=getchar())!='y')
    {
        if(i=='n')
            printf("Well, then, is it %d?\n", ++guess);

        else 
            printf("Sorry,I understand only y or n\n");
        while(getchar()!='\n')
        continue;
    }
}
