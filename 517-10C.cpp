#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define mid ((l + r) >> 1)
#define lc T[p].l
#define rc T[p].r
#define lb(x) (x & -x)
using namespace std;
const int maxn = 2e5 + 10;
vector<int> E[maxn];
int n, m, q, x, y, fa[23][maxn], depth[maxn], cnt;
int L[maxn], R[maxn], tot, top[23][maxn], RES[maxn];
int ANS[maxn];
int c[maxn];
pair<int,pair<int,int> > Q[maxn*6];
inline int lowbit(int x){
	return x & -x;
}
inline int sign(int x){
	return x >= 0 ? 1 : -1;
}
void dfs(int x){
    L[x] = ++cnt;
    for(int i = 1; i <= 20; i++)
        fa[i][x] = fa[i-1][fa[i-1][x]];
    for(vector<int>::iterator i = E[x].begin(); i != E[x].end(); i++){
        if(*i == fa[0][x]) continue;
        fa[0][*i] = x;
        depth[*i] = depth[x] + 1;
        dfs(*i);
    }
    R[x] = cnt;
}
void dfs1(int x){
    for(vector<int>::iterator i = E[x].begin(); i != E[x].end(); i++){
        if(*i == fa[0][x]) continue;
        dfs1(*i);
        if(depth[top[0][*i]] < depth[top[0][x]] || (top[0][x] == 0 && depth[x] != 0))
            top[0][x] = top[0][*i];
    }
}
void dfs2(int x){
    for(int i = 1; i <= 20; i++){
        top[i][x] = top[i-1][top[i-1][x]];
    }
    for(vector<int>::iterator i = E[x].begin(); i != E[x].end(); i++){
        if(*i == fa[0][x]) continue;
        dfs2(*i);
    }
}
void add(int x, int p){
	for(int i = x; i <= n; i += lowbit(i))
		c[i] += p;
}
int query(int x){
	int res = 0;
	for(int i = x; i; i -= lowbit(i))
		res += c[i];
	return res;
}
void goUp(int &node, int step){
    for(int i = 20; i >= 0 && step != 0; i--){
        if(step - (1 << i) >= 0)
            step -= 1<< i,
            node = fa[i][node];
    }
}
int LCA(int x, int y){
    //cerr << depth[x] << " " << depth[y] << endl;
    if(depth[x] < depth[y]) swap(x, y);
    //cerr << depth[x] << " " << depth[y] << endl;
    goUp(x, depth[x] - depth[y]);
    //cerr << x << " " << y << endl;
    if(x == y) return x;
    for(int i = 20; i >= 0; i--)
        if(fa[i][x] != fa[i][y])
            x = fa[i][x], y = fa[i][y];
    return fa[0][x];
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        top[0][i] = i;
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs(1);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        int lca = LCA(x, y);
        //cerr << lca << endl;
        if(depth[lca] < depth[top[0][x]])
            top[0][x] = lca;
        if(depth[lca] < depth[top[0][y]])
            top[0][y] = lca;
    	Q[++tot] = make_pair(L[x], make_pair(L[y], -maxn));
    	Q[++tot] = make_pair(L[y], make_pair(L[x], -maxn));
    	//cerr << "$$" << endl;
	    //cerr << L[x] << " " << L[y] << endl;
	    //cerr << L[y] << " " << L[x] << endl;
    }
    dfs1(1);
    dfs2(1);
    //for(int i = 1; i <= n; i++){
    //	cerr << i << ": ";
	//	for(int j = 0; j <= 20; j++){
	//		cerr << top[j][i] << " ";
	//		if(top[j][i] == top[j+1][i]) break;
	//	}
	//	cerr << endl;
	// }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        scanf("%d%d", &x, &y);
        if(depth[x] < depth[y]) swap(x, y);
        int lca = LCA(x, y);
        int ans = 0;
        int res = 0;
        for(int j = 20; j >= 0; j--){
            if(depth[top[j][x]] > depth[lca]){
                if(x != top[j][x])
                    ans += (1 << j);
                x = top[j][x];
            }
        }
        for(int j = 20; j >= 0; j--){
            if(depth[top[j][y]] > depth[lca]){
                if(y != top[j][y])
                    ans += (1 << j);
                y = top[j][y];
            }
        }
        //cerr << ans << endl;
        if(depth[top[0][x]] > depth[lca] || depth[top[0][y]] > depth[lca]){
            ANS[i] = -1;
            continue;
		}else if(y == lca && depth[top[0][x]] <= depth[y]){
			ANS[i] = -1 - ans - 1;
			continue;
		}else{
        	ANS[i] = ans;
        	int xx1 = L[x], xx2 = R[x];
        	int yy1 = L[y], yy2 = R[y];
        	Q[++tot] = make_pair(xx2, make_pair(yy2, i));
        	Q[++tot] = make_pair(xx1-1, make_pair(yy1-1, i));
			Q[++tot] = make_pair(xx2, make_pair(yy1-1, -i));
			Q[++tot] = make_pair(xx1-1, make_pair(yy2, -i));
        }
    }
//    cerr << "K" << endl;
    sort(Q+1, Q+1+tot);
	for(int i = 1; i <= tot; i++){
		int pos = Q[i].second.first;
		int key = Q[i].second.second;
		//cerr << "$$ -- " << Q[i].first << " " << pos << endl;
		if(key == -maxn){
			add(pos, 1);
			continue;
		}
		int SIGN = sign(key);

		key = SIGN * key;
		//cerr << key << ": " << query(pos) * SIGN << endl;
		RES[key] += query(pos) * SIGN;
	}
//	cerr << "K" << endl;
	for(int i = 1; i <= q; i++){
		if(ANS[i] != -1 && RES[i] > 0) ANS[i] += 1;
		else if(ANS[i] < -1) ANS[i] = -(ANS[i] + 1);
		else if(ANS[i] != -1) ANS[i] += 2;
		printf("%d\n", ANS[i]);
	}
    return 0;
}
