#include <stdio.h>
#include "hotel.h"

/*主菜单界面*/
int menu(void)
{
    char choice = 'i';
    printf("以下有四家酒店可以选择(q to quit):\n");
    printf("(a)汉庭酒店     (b)如家酒店\n");
    printf("(c)月桂酒店     (d)安康酒店\n\n");
    
    while((choice=getchar())!='q')
    {  
        while(getchar()!='\n')
        continue;
        // if(choice == 'q'){
        //     printf("Quit!\n");
        //     break;
        // }
        switch(choice)
        {
            case 'a':
                hanting();
                break;
            case 'b':
                rujia();
                break;
            case 'c':
                yuegui();
                break;
            case 'd':
                ankang();
                break;
            default:
                break;
        }
        printf("重新选择酒店\n");
    }
   
    printf("感谢光临!\n");
    return 0;
}

/*汉庭酒店*/
void hanting(void)
{
    int days = 0;
    double consumption = 0.00;
    printf("请输入预住天数(1~10):");
    while(scanf("%d",&days)==1)
    {
        if (days>=1 && days <= 10)
        {
            consumption = HANTING * days;
            printf("需要支付的价格为:%.2f\n",consumption);
            printf("可以继续输入预住的天数(q to quit):\n");
        }
        else
            printf("请输入有效天数(q to quit):\n");
    }
    
    while(getchar()!='\n')
    continue;
    return;
}

/*如家酒店*/
void rujia(void)
{
    int days = 0;
    double consumption = 0.00;
    printf("请输入预住天数(1~10):");
    while(scanf("%d",&days)==1)
    {
        if (days>=1 && days <= 10)
        {
            consumption = RUJIA * days;
            printf("需要支付的价格为:%.2f\n",consumption);
            printf("可以继续输入预住的天数(q to quit):\n");
        }
        else
            printf("请输入有效天数(q to quit):\n");
    }
    
    while(getchar()!='\n')
    continue;
    return;
}

/*安康酒店*/
void ankang(void)
{
    int days = 0;
    double consumption = 0.00;
    printf("请输入预住天数(1~10):");
    while(scanf("%d",&days)==1)
    {
        if (days>=1 && days <= 10)
        {
            consumption = ANKANG * days;
            printf("需要支付的价格为:%.2f\n",consumption);
            printf("可以继续输入预住的天数(q to quit):\n");
        }
        else
            printf("请输入有效天数(q to quit):\n");
    }
    
    while(getchar()!='\n')
    continue;
    return;
}



void yuegui(void)
{
    int days = 0;
    double consumption = 0.00;
    printf("请输入预住天数(1~10):");
    while(scanf("%d",&days)==1)
    {
        if (days>=1 && days <= 10)
        {
            consumption = YUEGUI * days;
            printf("需要支付的价格为:%.2f\n",consumption);
            printf("可以继续输入预住的天数(q to quit):\n");
        }
        else
            printf("请输入有效天数(q to quit):\n");
    }
    
    while(getchar()!='\n')
    continue;
    return;
}