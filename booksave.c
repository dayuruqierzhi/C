/* booksave.c -- 在文件中保存结构中的内容 */
/*在原有的基础上，从中读取数据到结构数组中，并将其打印出来，
将文件中原有的数据打印完之后，提示输入新的信息并保存在文件中*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* 最大书籍数量 */

char * s_gets(char * st, int n);//函数原型

struct book { /* 建立 book 模板 */
char title[MAXTITL];
char author[MAXAUTL];
float value;
};

int main(void)
{
    struct book library[MAXBKS]; /* 结构数组 */
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "a+b")) == NULL)//文件打开方式，可读写模式，且可创建文件，且2进制模式打开
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(EXIT_FAILURE);//stdlib
    }
    rewind(pbooks); /* 定位到文件开始，打开方式会定位在文件末尾 */
    while (count < MAXBKS && fread(&library[count], size,1, pbooks) == 1)//从文件中读取数据并打印
    {
        if (count == 0)
        puts("Current contents of book.dat:");           
        printf("%s by %s: $%.2f\n", library[count].title,library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);//先试用count，再加加
        while (getchar() != '\n')
        continue; /* 清理输入行 ，这是针对以上scanf部分的清理*/
        if (count < MAXBKS)
        puts("Enter the next title.");
    }
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", library[index].title,
        library[index].author, library[index].value);
        fwrite(&library[filecount], size, count - filecount, pbooks);
    }
    else
    puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    return 0;
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find) // 如果地址不是 NULL，
        *find = '\0'; // 在此处放置一个空字符
        else
        while (getchar() != '\n')
        continue; // 清理输入行
    }
    return ret_val;
}