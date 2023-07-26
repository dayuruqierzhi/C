#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void makeFile(void);

int main(int argc, char **argv)
{
    //makeFile();
    FILE *fp;
    char ch;

    if (argc != 3)
    {
        fprintf(stderr, "Usage:%s [character] [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    else
    {
        if (strlen(argv[1]) != 1)
        {
            fprintf(stderr, "The second parameter should be a character\n");
            exit(EXIT_FAILURE);
        }
        if ((fp = fopen(argv[2], "r")) == NULL)
        {
            fprintf(stderr, "Open %s failed\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }

    ch = argv[1][0];
    char a[256];
    while (fgets(a, 256, fp) != NULL)//fgets(char *ch,length, File * fp)，从fp文件给ch赋值，知道length或者遇到换行符
    {
        if (strchr(a, ch))//查找到该字符那么，返回该字符的的地址。
        {
            puts(a);
        }
    }

    system("pause");
    return 0;
}

void makeFile(void)
{
    srand((unsigned long)time(0));
    FILE *fp;
    fp = fopen("file.txt", "w");
    // 随机生成100条字符串
    for (int j = 0; j < 100; ++j)
    {
        int n = rand() % 256;
        for (int i = 0; i < n; ++i)
        {
            putc(32 + rand() % 95, fp);
        }
        putc('\n', fp);
    }
    fclose(fp);
}
