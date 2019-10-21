#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
typedef pair<int,int> pii;
int n, m, c[maxn], a, b, sum[maxn], ans[maxn], maxc;
int size[maxn];
vector<int> E[maxn];
vector<pii> query[maxn];
map<int, int> color, num[maxn], cnt[maxn];
//num[i][j]表示第i个点的子树中颜色为j的节点的个数
//cnt[i][j]表示第i个点的子树中，出现次数超过j次的颜色数
void dfs(int x, int f){
        num[x][c[x]] = 1, cnt[x][1] = 1;
        size[x] = 1;
        for(auto i = E[x].begin(); i != E[x].end(); i++)
                if(*i != f) {
                        dfs(*i, x);
                        if(size[*i] > size[x])
                                num[x].swap(num[*i]), cnt[x].swap(cnt[*i]);
                        size[x] += size[*i];
                        for(auto j = num[*i].begin(); j != num[*i].end(); j++) {
                                int Key = j->first;
                                while((j->second)--) {
                                        num[x][Key]++;
                                        cnt[x][num[x][Key]]++;
                                }
                        }
                }

        if(query[x].size() > 0) {
                for(auto i = query[x].begin(); i != query[x].end(); i++) {
                        ans[i->second] = cnt[x][i->first];
                }
        }
}
int main(){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
                scanf("%d", c+i);
                if(color.count(c[i]) == 0)
                        color[c[i]] = ++maxc, c[i] = maxc;
                else
                        c[i] = color[c[i]];
        }
        //cerr << maxc << endl;
        for(int i = 1; i < n; i++) {
                scanf("%d%d", &a, &b);
                E[a].push_back(b);
                E[b].push_back(a);
        }
        for(int i = 1; i <= m; i++) {
                scanf("%d%d", &a, &b);
                query[a].push_back(make_pair(b, i));
                //Func[make_pair(a, b)].push_back(i);
        }
        dfs(1, 0);
        for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
