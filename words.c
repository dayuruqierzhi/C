#include <stdio.h>
#include <ctype.h> // 为isspace()函数提供原型
#include <stdbool.h>//提供bool类型

/*统计输入的字符数，行数，以及单词数*/
int main(void)
{
    char c;//输入字符
    char previous;//必要的时候用于记录上次的c字符
    bool inword = false;//首先假定他是不在单词内的，只要第一次遇见非空字符就可以判定为
    int char_count = 0;//统计字符数
    int row_count = 0;//统计行数
    int word_count = 0;//统计单词数
    
    printf("Enter text to be analyzed (| to terminate):\n");
    while((c=getchar())!=EOF)
    {
        char_count++;//字符数统计增加
        
        if(c=='\n')//收到回车则行数增加
        row_count++;

        if(!inword&&!isspace(c))//第一个非空字符代表着第一个单词的开始，inword为假c为字符代表着单词的开始。inword为真c为空字符时代表单次结束。
        {
            word_count++;
            inword = true;
        }

        if((inword&&isspace(c))||inword&&(c==','||c=='.'))//两种情况假如在单词中且为空字符或者是在字符中且为‘,’或者‘。’，表明其为一个单词的结束
        {
           inword =  false;
        }
        
    }
    
    printf("characters = %d, words = %d, lines = %d ",char_count, word_count, row_count);
    return 0;
}
