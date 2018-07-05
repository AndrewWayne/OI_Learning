#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX(a,b) a>b?a:b
#define rep(k,j) for(int i=k;i<=j;i++)
#define MAXN 100010
using namespace std;
int next_i[MAXN],ans,n;
bool visited[MAXN];
inline void read(int &x){
      int f=1;x=0;
      char s=getchar();
      while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
      while(s>='0'&&s<='9'){x=x*10+(s-'0');s=getchar();}
      x*=f;
}
void go(int p){
    while(!visited[p]){
        visited[p]=true;
        ans++;
        p=next_i[p];
    }
}
void tarjan()//所以这题要等到暑假学了强连通分量再说
int main(){
    scanf("%d",&n);
    rep(1,n)
      read(next_i[i]);
    rep(1,n){
        memset(visited, 0, sizeof(visited));
        ans=0;
        go(i);
        printf("%d\n",ans);
    }
}
