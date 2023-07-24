#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void makeFile()
{
    srand((unsigned long)time(0));

    FILE *fp;

    fp = fopen("file.txt", "w");
    //生成100个浮点数，小数点前有3位，小数点后有4位
    for (int j = 0; j < 100; ++j)
    {
        for (int i = 0; i < 7; ++i)
        {
            if (i == 3)
            {
                putc('.', fp);
            }
            putc(rand() % 10 + '0', fp);
        }
        putc('\n', fp);
    }
    fclose(fp);
}

int main(int argc, char **argv)
{
    //makeFile();

    FILE *fp;
    double n, sum = 0.0;
    int num = 0;

    if (argc == 1)
    {
        fp = stdin;
    }
    else if (argc == 2)
    {
        if ((fp = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "Open %s failed\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Usage:%s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%lf", &n) == 1)
    {
        num++;
        sum += n;
    }
    if (num)
    {
        printf("%lf\n", sum / n);
    }
    else
    {
        puts("There is no number");
    }

    system("pause");
    return 0;
}
