#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<ll, int> pli;
const int maxn = 5e4 + 10;
int n, m, u, v;
vector<pil> E[maxn];
int id[maxn], fa[22][maxn];
ll w, len[maxn], sum;
bool visited[maxn], used[maxn];
pli choice[maxn];
vector<int> key;
vector<pli> rest;
vector<pli> hards;
void dfs(int x){
	for(int i = 1; i <= 20; i++)
		fa[i][x] = fa[i-1][fa[i-1][x]];
	for(vector<pil>::iterator i = E[x].begin(); i != E[x].end(); i++){
		if(i->first == fa[0][x]) continue;
		fa[0][i->first] = x;
		len[i->first] = len[x] + i->second;
		dfs(i->first);
	}
}
bool dfs1(int x){
	bool flg = false;
    if(visited[x]) return 1;
	for(vector<pil>::iterator i = E[x].begin(); i != E[x].end(); i++){
		if(i->first == fa[0][x]) continue;
		flg = true;
		if(!dfs1(i->first))//维护出哪个子节点的子树没好
            return 0;
	}
	return flg;
}
bool check(ll x){
    //cerr << "$: " << x << endl;
	memset(used, 0, sizeof(used));
	memset(visited, 0, sizeof(visited));
	memset(choice, 0, sizeof(choice));
	rest.clear();
    //cerr << "?" << endl;
	for(int i = 1; i <= m; i++){
		ll cost = 0;
		int idx = id[i];
        //cerr << "-- " << i << ": ";
		for(int j = 20; j >= 0; j--)
			if(fa[j][idx] > 1 && len[idx] - len[fa[j][idx]] + cost <= x)
				cost += len[idx] - len[fa[j][idx]], idx = fa[j][idx];//贪心上跳越高越好
        //cerr << cost << " ";
		if(fa[0][idx] == 1 && cost + len[idx] <= x){//要能去帮助别人，一定是能到顶的
			ll len1 = x - cost - len[idx];
			if(choice[idx].second == 0 || choice[idx].first > len1)
				choice[idx] = make_pair(len1, i);//如果这个子树没有其他点就只能自产自销，如果有多个就找最没前途的那个留下来
			rest.push_back(make_pair(len1, i));//不然还可以帮助别人
            //cerr << i << endl;
		}else
			visited[idx] = 1;//管好自己
	}
    //cerr << endl;
	hards.clear();
    for(auto i = E[1].begin(); i != E[1].end(); i++)
        if(!dfs1(i->first))
            hards.push_back(make_pair(i->second, i->first));//找出难的子树
	if(hards.size() == 0) return 1;
    sort(hards.begin(), hards.end());//从远到近解决问题
    sort(rest.begin(), rest.end());
    auto now = rest.rbegin();
    for(auto i = hards.rbegin(); i != hards.rend(); i++){
        if(choice[i->second].second != 0 && !used[choice[i->second].second]){
            used[choice[i->second].second] = true;
            //cerr << choice[i->second].second << " ";
            continue;
        }
        //cerr << (i -> second) << " ";
        while((used[now->second] || now->first < i->first ) && now != rest.rend()) now++;
        if(now == rest.rend()) return 0;
        used[now->second] = true;
        //cerr << now->second << " ";
    }
    return true;
}
int main(){
    //freopen("a1.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d%d%lld", &u, &v, &w);
		E[u].push_back(make_pair(v, w));
		E[v].push_back(make_pair(u, w));
        if(u == 1) key.push_back(v);
        if(v == 1) key.push_back(u);
	}
	dfs(1);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
		scanf("%d", id+i);
	if(key.size() > m){
		puts("-1");
		return 0;
	}
    //cerr << endl;
	ll ans = 0;
	for(ll i = 60; i >= 0; i--){
        //cerr << "$: " << ans + (1ll << i) << endl;
    	if(!check(ans + (1ll << i))) ans += 1ll << i;
        //cerr << endl;
    }
	printf("%lld", ans+1);
	return 0;
}
