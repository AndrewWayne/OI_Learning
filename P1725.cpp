#include <cstdio>
#include <iostream>
#define swap(a,b) a^=b^=a^=b
using namespace std;
int n,l,r,h,t;
int a[200200];
int f[200200];
int queue[200200][2];
long long ans;
int main(){
    cin>>n>>l>>r;
    if(l>r)
        swap(l,r);
    for(int i=0;i<=n;i++)scanf("%d",&a[i]);
    for (int i = n - l + 1; i <= n; i++) f[i] = a[i];
    for(int i=n+1;i>=l;i--){//从后往前DP
        while(h<=t&&queue[t][0]<f[i])t--;//维护单调递增
        queue[++t][0]=f[i];
        queue[t][1]=i;
        f[i-l]=queue[h][0]+a[i-l];
        while(h<=t&&queue[h][1]==i+r)h++;//超右界
    }
    cout<<f[0];
    return 0;
}
