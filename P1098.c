#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define turn 'A'-'a'
void expand(char* in,int p1,int p2,int p3,int pos){
    int i,j;
    int begin=in[pos-1];
    int end=in[pos+1];
    int distance=end-begin;
    switch (p1){
        case 1:
            for (i = 1; i < distance; ++i)
            {
                if (p3==1)for (j = 0; j < p2; ++j)printf("%c",begin+i);
                if (p3==2)for (j = 0; j < p2; ++j)printf("%c",end-i);
            }
            break;
        case 2:
            for (i = 1; i < distance; ++i)
            {
                if (p3==1)for (j = 0; j < p2; ++j)
                {
                    if(begin>'a')printf("%c",begin+i+'A'-'a');
                    else printf("%c",begin+i);
                }
                if (p3==2)for (j = 0; j < p2; ++j){
                    if(begin>'a')printf("%c",end-i+'A'-'a');
                    else printf("%c",end-i);
                }
            }
            break;
        case 3:
            for (i = 0; i < p2*(distance-1); ++i)
            {
                printf("*");
            }
            break;
        default:
            break;
    }
}
int main(){
    int i;
    int p1,p2,p3;
    char in[100];
    scanf("%d %d %d\n",&p1,&p2,&p3);
    scanf("%s\n",in);
    for (i = 0; i < strlen(in)-1; i++)
    {
        if (in[i]=='-')
        {
            if (in[i-1]<in[i+1]&&(in[i+1]-in[i-1])<30)expand(in, p1, p2, p3, i);
            else printf("-");
            continue;
        }
        printf("%c",in[i]);
    }
    printf("%c",in[strlen(in)-1]);
}
