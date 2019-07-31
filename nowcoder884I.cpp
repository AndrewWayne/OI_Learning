#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAXN 500006

int n , lst;
char ch[MAXN] , revch[MAXN];
ll ans = 0;

struct SAM{
    int son[MAXN][30]; // sons
    int par[MAXN] , len[MAXN]; // node
    int head[MAXN] , nxt[MAXN<<1] , to[MAXN<<1]; // edge
    int cnt , ecnt;
    void adde( int u , int v ) {
        to[++ecnt] = v;
        nxt[ecnt] = head[u];
        head[u] = ecnt;
    }
    void init(  ) {
        memset( son , 0 , sizeof son ) , memset( head , -1 , sizeof head );
        cnt = lst = 1; par[1] = ans = ecnt = 0;
    }
    void addall(  ) { // 将所有link边连到边集合中
        for( int i = 2 ; i <= cnt ; ++ i ) adde( par[i] , i );
    }
    void ins( int x ) {
        int cur = ++ cnt;
        len[cur] = len[lst] + 1;
        int p = lst;
        while( p && !son[p][x] ) son[p][x] = cur , p = par[p];
        if( !p ) par[cur] = 1;
        else {
            int q = son[p][x];
            if( len[q] == len[p] + 1 ) par[cur] = q;
            else {
                int cl = ++ cnt;
                memcpy( son[cl] , son[q] , sizeof son[q] );
                par[cl] = par[q]; // copy
                len[cl] = len[p] + 1 , par[q] = par[cur] = cl;
                while( p && son[p][x] == q ) son[p][x] = cl , p = par[p] ;
            }
        }
        lst = cur;
        ans += len[lst] - len[par[lst]];
    }
} S ;

#define ULL unsigned long long
const int maxn=2000000+20;
ULL P = 1313131;
ULL sqr[maxn/2],has[maxn/2],V[maxn];

int Laxt[maxn],Next[maxn],cnt=0;

const int MOD = 2000007;

bool _insert(ULL Now)
{
    int u=Now%MOD;
    for(int i=Laxt[u];i;i=Next[i]){
        if(V[i]==Now) return true;
    }
    Next[++cnt]=Laxt[u];
    Laxt[u]=cnt;
    V[cnt]=Now;
    return false;
}
int ANS=0;
void _hash(int x,int y){
    ULL Now=has[y]-has[x-1]*sqr[y-x+1];
    if(!_insert(Now)) ++ANS;
}
int _malacher( char* c )
{
    int R=0,Mid=0,Len;
    Len=strlen(c+1);
    sqr[0]=1;
    for(int i=1;i<=Len;i++){
        sqr[i]=sqr[i-1]*P;
        has[i]=has[i-1]*P+c[i];
    }
    int r[maxn];
    for(int i=1;i<=Len;++i) {
        _hash(i,i);
        if(R>i) r[i]=min(r[2*Mid-i],R-i);
        while(i+r[i]+1<=Len&&c[i+r[i]+1]==c[i-r[i]-1]){
            _hash(i-r[i]-1,i+r[i]+1);
            r[i]++;
        }
        if(i+r[i]>R) {
            R=i+r[i];
            Mid=i;
        }
    }

    cnt=0;Mid=0;R=0;
    memset(Laxt,0,sizeof(Laxt));
    memset(r,0,sizeof(r));
    for(int i=2;i<=Len;++i) {
        if(R>i) r[i]=min(r[2*Mid-i],R-i+1);
        while(i+r[i]<=Len&&c[i+r[i]]==c[i-r[i]-1]) {
            _hash(i-r[i]-1,i+r[i]);
            ++r[i];
        }
        if(i+r[i]-1>R) {
            R=i+r[i]-1;
            Mid=i;
        }
    }
    return ANS;
}

ll ans1 , ans2;
int main() {
    scanf("%s",ch + 1); n = strlen( ch + 1 );
    S.init(  );
    for( int i = 1 ; i <= n ; ++ i ) S.ins( ch[i] - 'a' );
    ans1 = ans;
    S.ins( 26 );
    for( int i = n ; i >= 1 ; -- i ) S.ins( ch[i] - 'a' );
    ans -= 1LL * ( n + 1 ) * ( n + 1 );
    ans2 = 2 * ans1 - ans - _malacher( ch );
    printf("%lld",ans1 - ans2 / 2 );
}
