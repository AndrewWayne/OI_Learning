#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const ull N = 13705834633;
const int maxN=1010;
const ull base = 137;//不能是97，会被卡
char s1[maxN],s2[maxN];
ull hash1[maxN],hash2[maxN],p[maxN],now;
int n,m,q,l,r,ans;
void init(){
    p[0] = 1;
    hash1[0] = s1[0]-'a';
    hash2[0] = s2[0]-'a';
    for(int i = 1; i <= n+1; i ++)p[i] =p[i-1] * base;
    for(int i = 1; i < n; i ++)hash1[i] = hash1[i - 1] * base + (s1[i] - 'a');
    for(int i = 1; i < m; i ++)hash2[i] = hash2[i - 1] * base + (s2[i] - 'a');//自然上溢，取模会超时
}
ull get(int l, int r){//取出g里l - r里面的字符串的hash值
    return hash1[r]-hash1[l - 1]*p[r - l + 1];
}
int main(){
    cin>>n>>m>>q;
    scanf("%s%s",s1,s2);
    init();
    for(int i=1;i<=q;i++){
        scanf("%d%d",&l,&r);//不能用cin，会被卡
        ans=0;
        for(int j=l-1;j+m-1<=r-1;j++){
            now=get(j,j+m-1);
            if(now==hash2[m-1])
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
