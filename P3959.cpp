#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,g[30][30];
struct node {
    int d[30],deep[30];
    node () {
        for(int i=1;i<=n;i++) d[i]=i,deep[i]=0;
    }
    node (const node & path) {
        memcpy(d,path.d,sizeof d); memset(deep,0,sizeof deep);
        swap(d[rand()%n+1],d[rand()%n+1]);
    }
    double dist() {
        double ans=0;
        deep[d[1]]=1;
        for(int i=2;i<=n;i++) {
            double temp=9999999;
            for(int j=1;j<i;j++) {
                if(g[d[j]][d[i]]!=0x3f3f3f3f && deep[d[j]]*g[d[j]][d[i]]<temp) {
                    temp=deep[d[j]]*g[d[j]][d[i]]; deep[d[i]]=deep[d[j]]+1;
                }
            }
            if(temp!=9999999) ans+=temp;
            else return temp;
        }
        return ans;
    }
};
inline int SA() {
    const double max_temper=10000;
    const double dec=0.998;
    double temp=max_temper;
    node path ;
    while(temp>0.01) {
        node path2(path);
        double del=path2.dist()-path.dist();
        if(del<=0) path=path2;
        else if(exp(-del/temp)*RAND_MAX>=rand()) path=path2;
        temp*=dec;
    }
    return (int)path.dist();
}
int main() {
    srand(19260817);
    scanf("%d %d",&n,&m);
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=m;i++) {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        g[x][y]=g[y][x]=min(g[x][y],w);
    }
    int ans=99999999,T=60;
    while(T--) {
        ans=min(ans,SA());
    }
    printf("%d",ans);
    return 0;
}
