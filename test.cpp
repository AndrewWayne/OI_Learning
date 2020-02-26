#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<map>
#include<queue>
#include<vector>
/*
lower_bound是大于等于
upper_bound是大于
set存元素
map有映射
*/
using namespace std;
#define ll long long
const int MAXN=10005;
const int MAXK=105;

int dp[MAXN][MAXK][3]={0};

int tmp[MAXK][3]={0};

int siz[MAXN]={0};
int dep[MAXN]={0};
int faf[MAXN]={0};
int lon[MAXN]={0};
int vis[MAXN]={0};

int N,K;
vector<int> p[MAXN];

void dfs(int u,int fa,int tdep){
	siz[u]=1;
	dep[u]=tdep;
	int v;
	for(int i=0;i<p[u].size();i++){
		v=p[u][i];if(v==fa) continue;
		dfs(v,u,tdep+1);
		siz[u]+=siz[v];
	}
}

void dfs3(int u,int fa){
	dp[u][0][0]=0;
	dp[u][1][1]=0;
	int v,len=0;
	int tt;
	lon[u]=1;
	int man=0;
	for(int i=0;i<p[u].size();i++){
		v=p[u][i];if(v==fa) continue;
		dfs3(v,u);
		memset(tmp,20,sizeof(tmp));
		tmp[0][0]=dp[u][0][0]+dp[v][0][0]+siz[v];
		for(int j=1;j<=lon[v]&&j<=K;j++){
			tmp[j+1][1]=min(tmp[j+1][1],dp[u][0][0]+dp[v][j][1]);
		}
		for(int j=1;j<=lon[u]&&j<=K;j++){
			tmp[j][1]=min(tmp[j][1],dp[u][j][1]+dp[v][0][0]+siz[v]);
		}

		for(int j=2;j<=man;j++){
			tmp[j][2]=min(tmp[j][2],dp[u][j][2]+dp[v][0][0]+siz[v]);
		}

		for(int j=1;j<=lon[u]&&j<=K;j++){
			for(int k=1;k<=lon[v]&&(j+k)<=K;k++){
				if(j+k==K) vis[u]=1;
				man=max(man,j+k);
				tmp[j+k][2]=min(tmp[j+k][2],dp[u][j][1]+dp[v][k][1]);
			}
		}
		tt=lon[u];
		lon[u]=max(lon[u],lon[v]+1);
		dp[u][0][0]=tmp[0][0];
		for(int j=1;j<=min(K,lon[u]);j++) dp[u][j][1]=tmp[j][1];
		for(int j=2;j<=man;j++) dp[u][j][2]=tmp[j][2];
	}
}

void dfs2(int u,int fa){
	int v;
	for(int i=0;i<p[u].size();i++){
		v=p[u][i];if(v==fa) continue;
		faf[v]=faf[u]+N-siz[v]+dp[u][0][0]-dp[v][0][0]-siz[v];
		dfs2(v,u);
	}
}

void prepare(){
	memset(siz,0,sizeof(siz));
	memset(dep,0,sizeof(dep));
	memset(faf,0,sizeof(faf));
	memset(lon,0,sizeof(lon));
	memset(vis,0,sizeof(vis));
	int x,y;
	K++;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<N;i++){
		scanf("%d %d",&x,&y);
		x++,y++;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(1,1,1);
	dfs3(1,1);
	dfs2(1,1);
	int Min=1000000000;
	for(int i=1;i<=N;i++){
		if(vis[i]){
			//cout<<i<<"!";
			//cout<<dp[i][K][2]<<" "<<faf[i]<<"?"<<endl;
			Min=min(Min,dp[i][K][2]+faf[i]);
		}
	}
	cout<<Min<<endl;
	for(int i=1;i<=N;i++) p[i].clear();
}

void solve(){

}

int main(){
    freopen("data.in", "r", stdin);
	while(1){
		cin>>N>>K;
		if(N==0&&K==0) break;
		prepare();
		solve();
	}
	return 0;
}
