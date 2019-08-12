# include <cstdio>
# include <iostream>
# include <queue>
# include <cstring>
# define mp make_pair
# define R register int

using namespace std;

int h,n,m,k,s,t,a,b,c,firs[10009];
struct edge
{
    int co, too, nex;
}g[200009];
int d[10009][12];
bool vis[10009][12];
typedef pair <int,int> pii;
priority_queue <pii,vector<pii>,greater<pii> > q;

void add(int x,int y,int co){
    g[++h].too=y;
    g[h].co=co;
    g[h].nex=firs[x];
    firs[x]=h;
}

void dis(){
    memset(d,127,sizeof(d));
    d[s][0]=0;
    q.push(mp(0,s));
    int beg,j,x;
    while (q.size()){
        beg=q.top().second;
        q.pop();
        x=beg/n;
        beg%=n;
        if(vis[beg][x]) continue;
        vis[beg][x]=true;
        for (R i=firs[beg];i;i=g[i].nex){
            j=g[i].too;
            if(d[beg][x]+g[i].co<d[j][x]){
                d[j][x]=d[beg][x]+g[i].co;
                q.push(mp(d[j][x],j+n*x));
            }
            if(x==k) continue;
            if(d[j][x+1]>d[beg][x]){
                d[j][x+1]=d[beg][x];
                q.push(mp(d[j][x+1],j+(x+1)*n));
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&s,&t);
    for (R i=1;i<=m;++i){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dis();
    printf("%d\n", d[t][k]);
    return 0;
}
