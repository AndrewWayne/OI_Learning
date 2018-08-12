//树状数组基础版，实现区间询问以及单点修改（单点询问左转树状数组ex）
#include <cstdio>
#include <iostream>
#define MAXN 500050
using namespace std;
int a,c[MAXN],n,m;
int lowbit(int x){
    return x & -x;
}
void add(int pos,int num){
    while(pos<=n){
        c[pos]+=num;
        pos+=lowbit(pos);
    }
}
int ss(int x){
    int ans=0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        add(i,a);
    }
    int caozuo,x,y,k;
    for(int i=1;i<=m;i++){
        scanf("%d",&caozuo);
        if(caozuo==1){
            scanf("%d%d",&x,&k);
            add(x,k);
        }else{
            scanf("%d%d",&x,&y);
            int ans=ss(y)-ss(x-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
