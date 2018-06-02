#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int i,j;
    int n,x,t=0;
    int end=0;
    int map[12][100005];
    while(~scanf("%d",&n)){
        if(!n)break;
        for(i=0;i<n;i++){
            scanf("%d%d",&x,&t);
            map[x][t]++;
            end=max(end,t);
        }
        for(i=end;i>=0;i--)
            for(j=0;j<=10;j++){
                if(j>0&&j<10)
                    map[j][i]=max(map[j-1][i+1],max(map[j][i+1],map[j+1][i+1]))+map[j][i];
                if(j==0)
                    map[j][i]=max(map[j][i+1],map[j+1][i+1])+map[j][i];
                if(j==10)
                    map[j][i]=max(map[j-1][i+1],map[j][i+1])+map[j][i];
            }
    }
    printf("%d",map[5][0]);
    return 0;
}
