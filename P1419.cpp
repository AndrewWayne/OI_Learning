#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 100000+10;
int A[maxn];
int n,s,t;
double sum[maxn];
int q[maxn],head,tail;//q中存编号
bool can(double x) {
    sum[0]=0;
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+A[i]-x;//减去一个x(平均值)后如果前缀和大于零就可以，小于零则不可以
    head=1; tail=0;                  //初始化单调队列为空
    for (int i = 1; i <= n; i++) {
        if (i >= s) {                 //足够s个  //front为在i-t..i-s区间内的最小值
            while (head<=tail && sum[i - s] < sum[q[tail]])  tail--;  //维护单调递增
            q[++tail] = i - s;        //入队区间起点-1
        }
        if (head <= tail && q[head] < i - t) head++;  //维护区间i-t//q[head]<i-t表示已经超出了[s,t]的范围
        if (head <= tail && sum[i] - sum[q[head]] >= 0) return true; //有大于0的区间和(前缀和相减得区间和，见课件p19)说明最大平均值还可以更大
    }
    return false;
}
int main() {
    scanf("%d%d%d",&n,&s,&t);
    double L=0,R=0;
    for(int i=1;i<=n;i++) scanf("%d",&A[i]),R=max(R,(double)A[i]);
    while(R-L>1e-4) {//二分一个答案，保留3位小数，故精度到1e-4
        double M=L+(R-L)/2;
        if(can(M)) L=M;
        else R=M;
    }
    printf("%.3lf\n",L);
    return 0;
}
