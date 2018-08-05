#include <cstdio>
#include <iostream>
using namespace std;
int n,l,r,h,t;
int a[200200];
int f[200200];
int queue[200200];
long long ans;
int main(){
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i = n - l + 1; i <= n; i++) f[i] = a[i];
    for(int i=n+1;i<=n-l+r;i++)queue[t++]=i;
    for(int i=n-l;i>=0;i--){//从后往前DP
        while(h^t&&queue[h]>i+r)h++;//超右界
        while(h^t&&f[queue[t-1]]<f[i+l])t--;//维护单调递增
        queue[t++]=i+l;
        f[i]=f[queue[h]]+a[i];
    }
    cout<<f[0];
    return 0;
}
