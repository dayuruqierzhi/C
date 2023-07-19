#include <stdio.h>

#define SCORE_ONE 60
#define SCORE_TWO 90
#define SCORE_TRE 120
#define SCORE_FIN 150

int main(void)
{
    int score;
    printf("Please enter the scores(q to quit)\n");
    while(scanf("%d",&score)==1)
    {
        if (score<SCORE_ONE&&score<=SCORE_FIN)
        {
            printf("socre:%d 不及格\n", score);
        }
        else if(score<SCORE_TWO&&score<=SCORE_FIN)
        {
            printf("socre:%d 中\n", score);
        }
        else if(score<SCORE_TRE&&score<=SCORE_FIN)
        {
            printf("socre:%d 良\n", score);
        }
        else if(score>=SCORE_TRE&&score<=SCORE_FIN)
            printf("socre:%d 优\n", score);
        else
        printf("invalid data\n");
               
    }
    printf("quit");
    return 0;

}