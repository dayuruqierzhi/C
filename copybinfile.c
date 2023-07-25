/*
编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文
件名。尽量使用标准I/O和二进制模式
*/
#include <stdio.h>
#include <stdlib.h>//包含exit()函数

#define SIZE 512

int main(int argc, char * argv[])
{
    FILE * source;//源文件
    FILE * target;//目标文件

    size_t bytes = 0;
    char * transient[SIZE] = {0};//用于读取源文件的数据并写入到目标文件

    if(argc != 3)//如果命令函参数不对
    {
        fprintf(stderr, "Usage: please enter sourcefile and targefile.\n");
        exit(EXIT_FAILURE);
    }

    if((source=fopen(argv[1],"rb")) == NULL)//先赋值的话要加括号，打开模式要用双引号
    {
        fprintf(stderr,"Failed to open the source file.\n");
        exit(EXIT_FAILURE);
    }

    if((target = fopen(argv[2],"wb")) == NULL)
    {
        fprintf(stderr,"Failed to open the target file..\n");
        exit(EXIT_FAILURE);
    }

    if((bytes = fread(transient,sizeof(char),SIZE,source)) > 0)//fread返回值为读取的数据块的个数，正常即为size
    {
        fwrite(transient,sizeof(char),bytes,target);
    }

    if(fclose(source) != 0)//fclose返回值类型为int型
    fprintf(stderr,"Failed to close source file.\n");
    if(fclose(target) != 0)
    fprintf(stderr,"Failed to close target file.\n");

    return 0;

}
