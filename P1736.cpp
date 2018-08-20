#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2510
int dp[N][N],sum[N][N];  //sum表示从(1,1)到(i,j)的元素和
bool map[N][N];
int maxx=0;
int getsum(int i,int j,int x,int y) {
    return sum[x][y]-sum[x][j-1]-sum[i-1][y]+sum[i-1][j-1];  //二维前缀和的精华操作，表示对角线从(i,j)到(x,y)的子矩阵的元素和
}
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}

int main() {
    int i,j,n=read(),m=read();
    for(i=1;i<=n;i++) {
        int num=0;
        for(j=1;j<=m;j++) {
            map[i][j]=read();
            num+=map[i][j];
            sum[i][j]=sum[i-1][j]+num;  //初始化二维前缀和
        }
    }
       //左对角线操作
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(map[i][j]) {
                dp[i][j]=1; //初始化为1，在这里没什么意义，但在下面求右对角线时是必要的
                if(dp[i-1][j-1]) {
                    int num=dp[i-1][j-1];
                    int l=0,r=num,ans=0;
                                        //以下即为二分查找，功能就是找出符合条件的最长对角线长度
                    while(l<=r) {
                        int mid=l+r>>1;
                        if(getsum(i-mid,j-mid,i,j)==mid+1) ans=mid,l=mid+1;
                        else r=mid-1;
                    }
                    dp[i][j]=max(dp[i][j],ans+1);
                }
                maxx=max(maxx,dp[i][j]);
            }
       //右对角线长度
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(map[i][j]) {
                dp[i][j]=1;
                if(dp[i-1][j+1]) {
                    int num=dp[i-1][j+1];
                    int l=0,r=num,ans=0;
                    while(l<=r) {
                        int mid=l+r>>1;
                        if(getsum(i-mid,j,i,j+mid)==mid+1) ans=mid,l=mid+1; //注意getsum()内填入的顺序，我一开始就被坑了
                        else r=mid-1;
                    }
                    dp[i][j]=max(dp[i][j],ans+1);
                }
                maxx=max(maxx,dp[i][j]);
            }
    printf("%d\n",maxx);
    return 0;
}
