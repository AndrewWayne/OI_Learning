//
//  HDU5115.c
//  P1098
//
//  Created by admin on 2018/5/9.
//  Copyright © 2018年 AndrewWayne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f3f
int min(int a,int b){
    if(a>b)return b;
    else return a;
}
int main(){
    int t,n;
    int i,j,k;
    int cases=0;
    struct wolf{int basic;int extra;};
    struct wolf wolves[203];
    int damage[203][203];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for (i = 1; i <= n; ++i)
        {
            for(j=1;j<=n;++j){
                damage[i][j]=INF;
            }
        }
        for (i = 1; i <= n; ++i)scanf("%d",&wolves[i].basic);
        for (i = 1; i <= n; ++i)scanf("%d",&wolves[i].extra);
        wolves[0].extra=0;
        wolves[n+1].extra=0;
        for (i = 1; i <= n; ++i)
        {
            for (j = i; j > 0; --j)
            {
                for (k = j; k <= i; ++k)
                {
                    damage[j][i]=min(damage[j][i],damage[j][k-1]+damage[k+1][i]+wolves[k].basic+wolves[i+1].extra+wolves[j-1].extra);
                }
            }
        }
        printf("Case #%d: %d\n",++cases,damage[1][n]);
    }
    return 0;
}
