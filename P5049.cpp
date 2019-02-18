#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define readit(x) scanf("%d", &x)
#define printit(x) printf("%d ", x)
using namespace std;
const int MAXN = 5e5 + 10;
const int MAXM = 1e6 + 10;
int n, m, u, v, du, dv, nume, numans, ans[MAXN], temp_ans[MAXN], dg[MAXN], head[MAXN];
int stacknode[MAXN][MAXN], top[MAXN];
bool better = true, visit[MAXN];
pair<int, int> couple[MAXN];
struct Edge{
	int pre, nxt, to;
}edge[MAXM];
void add(int u, int v){
	dg[u]++;
	edge[++nume].nxt = head[u];
	edge[head[u]].pre = nume;
	edge[nume].to = v;
	head[u] = nume;
}
inline bool check(int u, int v){
	if( u == du && v == dv)
		return false;
	if( u == dv && v == du)
		return false;
	return true;
}
bool best = false;
void dfs(int x){
	if(!better) return;
	if(visit[x]) return;
	if(best == false && temp_ans[numans+1] < x){
		better = false;
		return;
	}
	if(temp_ans[numans+1] > x)
		best = true;
	visit[x] = true;
	temp_ans[++numans] = x;
	top[x] = 0;

	for(int i = head[x]; i; i = edge[i].nxt)
		if(!visit[edge[i].to] && check(x, edge[i].to))
			stacknode[x][++top[x]] = edge[i].to;

	sort(stacknode[x]+1, stacknode[x]+1+top[x]);
	for(int i = 1; i <= top[x]; i++)
		dfs(stacknode[x][i]);
}
int main(){
	readit(n), readit(m);
	memset(ans, 0x7f, sizeof(ans));
	for(int i = 1; i <= m; i++){
		readit(u), readit(v);
		add(u, v);
		add(v, u);
		couple[i] = make_pair(u, v);
	}

	better = true;
	if( m == n-1 ){
		memset(visit, 0, sizeof(visit));
		memset(top, 0, sizeof(top));
		memcpy(temp_ans, ans, sizeof(ans));
		best = false;
		better = true;
		numans = 0;
		du = 0;
		dv = 0;
		dfs(1);
		memcpy(ans, temp_ans, sizeof(ans));
	}

	if( m == n){
		for(int i = 1; i <= m; i++){
			if(dg[couple[i].first] < 2 || dg[couple[i].second] < 2)
				continue;
			memset(visit, 0, sizeof(visit));
			memset(top, 0, sizeof(top));
			memcpy(temp_ans, ans, sizeof(ans));
			best = false;
			better = true;
			numans = 0;
			du = couple[i].first;
			dv = couple[i].second;
		//	dd(du,dv);
			dfs(1);
		//	for(int i = 1; i <= numans; i++)
		//		cerr << "#" << temp_ans[i];
		//	cerr << endl;
			if(numans < n)
				continue;
			memcpy(ans, temp_ans, sizeof(ans));
		}
	}

	for(int i = 1; i <= n; i++)
		printit(ans[i]);

	return 0;
}
