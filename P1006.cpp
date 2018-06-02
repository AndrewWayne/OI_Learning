//
//  P1006.cpp
//  
//
//  Created by Andrew on 2018/5/19.
//

#include <cstdio>
#include <iostream>
#include <string.h>
#define LIM 51
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int map[LIM][LIM];
    int f[LIM][LIM][LIM];
    memset(map, 0, sizeof(map));
    memset(f, 0, sizeof(f));
    int i,j,k;
    int m,n;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&map[i][j]);
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            for(k=1;k<=m;k++){
                if (i!=k&&j!=i+j-k) {
                    f[i][j][k]=max(f[i-1][j][k-1],max(f[i-1][j][k],max(f[i][j-1][k],f[i][j-1][k-1])))+map[i][j]+map[k][i+j-k];
                }
            }
    printf("%d",f[m][n][m-1]);
    return 0;
}
