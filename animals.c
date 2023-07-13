#include <stdio.h>
#include <ctype.h>//包含islower()该函数原型


int main(void)
{
    char ch;
    printf("Give me a letter of the alphabet, and I will give ");
    printf("an animal name\nbeginning with that letter.\n");
    printf("Please type in a letter; type # to end my act.\n");
    while ((ch = getchar()) != '#')
    {
        if ('\n' == ch)//这里就是 如果只按下回车的话就什么打印就没有
        {printf("a\n");
        continue;}

        if (islower(ch)) /* 只接受小写字母*/
        switch (ch)
        {
            case 'a':
            printf("argali, a wild sheep of Asia\n");
            break;
            case 'b':
            printf("babirusa, a wild pig of Malay\n");
            break;
            case 'c':
            printf("coati, racoonlike mammal\n");
            break;
            case 'd':
            printf("desman, aquatic, molelike critter\n");
            break;
            case 'e':
            printf("echidna, the spiny anteater\n");
            break;
            case 'f':
            printf("fisher, brownish marten\n");
            break;
            default:
            printf("That's a stumper!\n");
        } /* switch结束 */
        else
            printf("I recognize only lowercase letters.\n");
       
        while (getchar() != '\n')//这里 就是把第一个字符后面的字符忽略掉
        continue; /* 跳过输入行的剩余部分 */
        
        printf("Please type another letter or a #.\n");
        } /* while循环结束 */
    printf("Bye!\n");
    return 0;
}