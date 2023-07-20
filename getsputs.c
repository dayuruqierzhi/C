#include <stdio.h>
#define STLEN 99

int main(void)
{
    char words[STLEN];
    puts("Enter a string, please.");
    gets(words); // 典型用法
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");
    return 0;
}