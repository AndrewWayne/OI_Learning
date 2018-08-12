//树状数组ex 利用差分实现区间修改，单点查询。
#include <cstdio>
#include <iostream>
#define MAXN 500050
using namespace std;
int a1,a2,b,c[MAXN],n,m;
inline int lowbit(int x){
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
    a1=0;
    for(register int i=1;i<=n;i++){
        cin>>a2;
        b=a2-a1;
        add(i,b);
        a1=a2;
    }//build

    for(register int i=1;i<=m;i++){
        scanf("%d",&b);
        if(b==1){
            scanf("%d%d%d",&a1,&a2,&b);
            add(a1,b);
            add(a2+1,-1*b);
        }
        else{
            scanf("%d",&b);
            printf("%d\n",ss(b));
        }
    }
}
