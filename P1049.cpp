#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main(){
    int i,j;
    int v,n;
    int tools[31];
    int f[31][20000];
    scanf("%d%d",&v,&n);
    for(i=1;i<=n;i++)scanf("%d",&tools[i]);
    for(i=1;i<=n;i++)
        for(j=v;j>=0;j--){
            f[i][j]=f[i-1][j];
            if(j>=tools[i])f[i][j]=max(f[i-1][j],f[i-1][j-tools[i]]+tools[i]);
        }
    printf("%d",v-f[n][v]);
    return 0;
}
