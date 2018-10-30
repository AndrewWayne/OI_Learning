#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXM = 55;
int pos[MAXM],w[MAXM],sum[MAXM],n,m,c;
int f[MAXM][MAXM][2];//当关闭了f[l][r][0]表示当关闭了从 l 到 r 的灯后站在l的最小耗能，f[l][r][0]表示站在r的//下定义
int main()
{
    scanf("%d%d",&n,&c);
    memset(f,0x3f,sizeof(f));//赋成极大值防止后面的min出问题
    for(int i=1;i<=n;i++)
        scanf("%d%d", &pos[i], &w[i]), sum[i] = sum[i-1] + w[i];
    f[c][c][0] = f[c][c][1] = 0;//初始化

    for(int len = 2; len <= n; len++)//扫关了几盏灯（两盏起步）//阶段
        for(int l = 1; l + len - 1 <= n; l++)//要关哪几盏灯//状态//由于是区间dp只扫左点或右点即可
        {
            int r = l + len-1;
            f[l][r][0] = min(f[l+1][r][0] + (pos[l+1] - pos[l]) * (sum[n] - (sum[r]-sum[l])), f[l+1][r][1] + (pos[r] - pos[l]) * (sum[n] - (sum[r]-sum[l])));//两种行为：左端点继续往左，右端点折返往左, 走到左边去拉l灯
            //要注意的一点是 sum[n]-(sum[r]-sum[l]) 是包括了l这一点的电能的，因为走过来的过程中灯 l 也会耗电
            f[l][r][1]=min(f[l][r-1][0] + (pos[r] - pos[l]) * (sum[n] - (sum[r-1]-sum[l-1])), f[l][r-1][1] + (pos[r] - pos[r-1]) * (sum[n] - (sum[r-1] - sum[l-1])));//向右走（两种行为，一种是本来左边折到右边，或是本来右边继续往右）sum[n]-(sum[r-1]-sum[l-1])其中拉掉了l没拉掉r，所以r仍耗电
        }

    int ans=min(f[1][n][0],f[1][n][1]);//比大小
    printf("%d",ans);
    return 0;
}
