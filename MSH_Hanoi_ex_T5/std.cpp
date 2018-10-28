#include <cstdio>
#include <iostream>
#include <cstring>
#define min(a,b) a<b?a:b
using namespace std;
const int maxn = 100;
const int maxm = 100;
long long d[maxn],f[maxn][maxm],sum;
int n,m;
long long solve(int n,int m){
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
char name[100];
int main(){
    memset(f,0x3f,sizeof(f));
    n = 0, m = 0;
    scanf("%d%d",&n,&m);
    d[0] = 0;
    for(int i = 1; i <= m; i++)
        f[0][i] = 0;
    for(int i = 1; i <= n; i++)
        d[i] = 2*d[i-1] + 1;
    for(int i = 1; i <= n; i++)
        solve(i, m);

    printf("%lld",f[n][m]);
    return 0;

}
