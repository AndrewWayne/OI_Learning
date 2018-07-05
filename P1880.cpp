#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int f[101][101];
int f1[101][101];
int s[101];
int n,i,j,k,x;
int main()
{
    scanf("%d",&n);
    for (i=1; i<=n; i++)
    {
        scanf("%d",&x);
        s[i]=s[i-1]+x;//预处理前缀和
    }
    memset(f,127/3,sizeof(f));        //赋值127是很大的正数，若无/3后面的相加
    for (i=1; i<=n; i++) f[i][i]=0,f1[i][i]=0x7f;   //可能超出int的范围
    for (i=n-1; i>=1; i--)
        for (j=i+1; j<=n; j++)
            for (k=i; k<=j; k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
                f1[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
            }
    printf("%d\n",f[1][n]);
    printf("%d\n",f1[1][n]);
    return 0;
}
