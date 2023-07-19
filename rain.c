#include <stdio.h>


int main(void)
{
    float total,temp,aver_total,aver_month;
    int x,y;
    float rain[2][3] = 
    {
    {10.5, 11.5, 22.5},
    {5.5, 10.5, 2.5},
    };

    for(x=0,total = 0;x<2;x++)
    {
        for(y = 0, temp = 0; y < 3; y++)
        {
           temp += rain[x][y];
        }
        total +=temp;
    }
    printf("总降水量为:%.2f,年平均降水量为:%.2f\n", total, total/2);

    for(y = 0; y< 3; y++)
    {
        for(x = 0,aver_month = 0; x <2; x++)
        {
            aver_month +=rain[x][y];
        }        
        printf("%d月的平均降水量为:%.2f\n", y+1, aver_month/2);

    }

    return 0;

}