// strings1.c
#include <stdio.h>

//字符串内双引号，双引号表明其是一点字符串，并不是字符串本身包含的双引号。
#define MSGP "\"I am a symbolic string constant.\""
#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81

int main(void)
{
    char words[MAXLENGTH] = "I am a string in an array.";//字符串创建以及初始化的方式1
    const char * pt1 = "Something is pointing at me.";//方式2
    /*
    puts()使用.需要注意的是，这里的字符串创建是不带双引号且puts()的双引号并不会打印出来，
    而且puts()会自动在字符串结尾加上换行符。*/
    puts("Here are some strings:");
    puts(MSG);
    puts(MSGP);
    puts(words);
    puts(pt1);

    words[8] = 'p';//
    puts(words);
    return 0;
}