/*编写一个文件拷贝程序，提示用户输入文本文件名，并以该文件名作
为原始文件名和输出文件名。该程序要使用 ctype.h 中的 toupper()函数，在
写入到输出文件时把所有文本转换成大写。使用标准I/O和文本模式。*/

#include <stdio.h>
#include <ctype.h>//使用toupper()函数
#include <stdlib.h>

int main(void)
{
    FILE * fp1;
    char filename[51];
    char ch;
    int count = 0;
    long current;

    printf("Please enter the filename: ");
    scanf("%s",filename);

    if((fp1 = fopen(filename,"r+")) == NULL)//r+模式打开一个已存在的文件，可读可写
    {
        fprintf(stderr,"Can't open %s.\n",filename);
        exit(EXIT_FAILURE);
    }

    current = ftell(fp1);
    printf("while之前当前文件所在的位置为%ld.\n",current);

    while((ch = getc(fp1)) != EOF)//getc(fp1)以文件fp1作为文件输入，获取单个字符。
    {   
        count++;
        fprintf(stdout, "第%d次循环,",count);
        current = ftell(fp1);
        printf("while中当前文件所在的位置为%ld.\n",current);
        if(islower(ch))//如果是一个小写字符，进行小写转换成大写的操作
        {
            fseek(fp1,-1L,SEEK_CUR);
            putc(toupper(ch),fp1); //toupper()返回值就是将消协转换为大写的操作
            fseek(fp1,0L,SEEK_CUR);
        }
 
    }
    rewind(fp1);
    printf("File %s:\n", filename);
    while ((ch = getc(fp1)) != EOF)
    {
        putchar(ch);
    }
    putchar('\n');

    if(fclose(fp1)!=0)
    {
        fprintf(stderr,"Failed to close %s.\n",filename);
    }
    return 0;

}
