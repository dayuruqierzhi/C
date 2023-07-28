/*time.h 模块使用测试*/
/*
    <time.h>常用函数
    time_t time(time_t *timer) --> 计算当前日历时间，并返回time_t的类型
    time_t mktime(struct tm *timeptr) --> 将tm的结构指针所指向的结构转化为time_t，将当地时间转化为GMT/UTC时间戳
    char *ctime(const time_t *timer) -->秒计数器转化成字符串日期
    char *asctime(const struct tm *timeptr) -->tm结构日期转化为字符串日期
    struct tm *gmtime(const time_t *timer) -->将秒计数器转化为格林尼治时间
    struct tm *localtime(const time_t *timer) -->将秒计数器转化为当地时间
    size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr) -->将秒计数器转化为特定格式的字符串输出
    
    struct tm {
    int tm_sec;          秒，范围从 0 到 59              
    int tm_min;          分，范围从 0 到 59              
    int tm_hour;         小时，范围从 0 到 23            
    int tm_mday;         一月中的第几天，范围从 1 到 31  
    int tm_mon;          月份，范围从 0 到 11                 加1       
    int tm_year;         自 1900 起的年数                     加1900            
    int tm_wday;         一周中的第几天，范围从 0 到 6         加1
    int tm_yday;         一年中的第几天，范围从 0 到 365 
    int tm_isdst;        夏令时                        
    }
*/

#include <stdio.h>
#include <time.h>

time_t time_cnt;//秒计数器变量
struct tm *time_date;//秒计数所对应的日期
char * time_str;//实际用于显示的日期

int main(void)
{
    time_cnt = time(NULL);//取系统时间并转化为秒计时数
    printf("time_cnt = %d\n", time_cnt);

    time_str = ctime(&time_cnt);//将秒计时数转换成字符串日期   应该是当地时间
    printf("time_str: %s",time_str);

    time_date = gmtime(&time_cnt);//将妙计时器数转化为结构日期
    printf("year = %d\n",time_date->tm_year + 1900);
    printf("month = %d\n",time_date->tm_mon + 1);
    printf("day = %d\n",time_date->tm_mday);
    printf("hour = %d\n",time_date->tm_hour + 8);
    printf("min = %d\n",time_date->tm_min);
    printf("sec = %d\n",time_date->tm_sec);
    printf("time_date = %d\n",time_date->tm_wday);

    time_cnt = mktime(time_date);//将结构化日期转化为秒计数值
    printf("time_cnt = %d\n", time_cnt);

    time_str = asctime(time_date);//讲结构日期转化为字符日期
    printf("time_str: %s",time_str);



    strftime(time_str, 70, "%Y-%m-%d %H:%M:%S", time_date);


    printf("%s\n",time_str);
}






