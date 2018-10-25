//可用递归进行拓展
/*
#include <cstdio>
#include <iostream>
#include <cstring>
#define min(a,b) a<b?a:b
using namespace std;
int d[13],f[13];
int main(){
    memset(d,0x3f,sizeof(d));
    memset(f,0x3f,sizeof(f));
    d[0] = 0;
    f[0] = 0;
    for(int i = 1; i <= 12; i++){
        d[i] = 2*d[i-1] + 1;
        for(int j = 0; j < i ;j++)
            f[i] = min(2*f[j] + d[i - j], f[i]);
    }

    for(int i = 1; i <= 12; i++)
        printf("%d\n",f[i]);

    return 0;
}*/

//以下为递归写法

#include <cstdio>
#include <iostream>
#include <cstring>
#define min(a,b) a<b?a:b
using namespace std;
const int maxn = 30;
const int maxm = 6;
int d[maxn],f[maxn][maxm],n,m;
int solve(int n,int m){
    if( n < m){
        f[n][m] = 2*(n-1) + 1;
        return f[n][m];
    }
    else if( m <= 3){
        f[n][m] = d[n];
        return f[n][m];
    }
    else
        for(int i = 0; i <= n; i++)
            f[n][m] = min(solve(n-i, m-1) + 2*f[i][m], f[n][m]);
    return f[n][m];
}
int main(){

    memset(d,0x3f,sizeof(d));
    memset(f,0x3f,sizeof(f));
    cin>> n >> m;
    d[0] = 0;
    for(int i = 1; i <= m; i++)
        f[0][i] = 0;
    for(int i = 1; i <= n; i++)
        d[i] = 2*d[i-1] + 1;

    for(int i = 1; i <= n; i++)
        solve(i, m);

    for(int i = 1; i <= n; i++)
        printf("%d\n",f[i][m]);

    return 0;
}
