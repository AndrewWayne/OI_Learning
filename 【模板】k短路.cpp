/*
 * Author: xiaohei_AWM
 * Date: 7.18
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
const int MAX_N = 10000;
const int MAX_M = 50000;
const int MAX_K = 10000;
const int MAX_C = 1000;
/* 若存在无限多种可能路径，必能借由找到某条简单路径后，
 * 一直添加 cycle 来构造出 K 条长度都不超过
 * MAX_C * MAX_N * MAX_K 的路径。
 */
const long long MAX_V = (long long) MAX_C * MAX_N * MAX_K;
int n, m, k, s, t;
int cnt;
long long V;
struct EDGE {
    int y, v;
    EDGE(int y = 0, int v = 0) : y(y), v(v) {}
};
// 用 Dijkstra 算法算出每个点到终点的最短距离，存在 dij.dis[] 里
struct Dijkstra{
    vector<EDGE> e[MAX_N + 1];
    int dis[MAX_N + 1];
    bool used[MAX_N + 1];
    struct Data{
        int id, v;
        Data(int id = 0, int v = 0): id(id), v(v) {}
        bool operator<(const Data& b) const {return v > b.v;}
    };
    void build() {
        for(int i = 1; i <= n; i++) {
            dis[i] = MAX_N * MAX_C;
            used[i] = 0;
        }
        dis[t] = 0;
        priority_queue<Data> pq;
        pq.emplace(t, 0);
        while(!pq.empty()) {
            Data now = pq.top();
            pq.pop();
            if(used[now.id]) continue;
            used[now.id] = 1;
            for(size_t i = 0; i < e[now.id].size(); i++) {
                int y = e[now.id][i].y;
                if(dis[y] > now.v + e[now.id][i].v) {
                    dis[y] = now.v + e[now.id][i].v;
                    pq.emplace(y, dis[y]);
                }
            }
        }
    }
}dij;
/*
 * 比较函数是为了把每个点的所有连出去的边按照 v+dis[y] 由小到大排序
 * 其中 v 是该编的权重，dis[y] 是与 x 相邻的点到终点的最短路径。
 * 排完序后有两个好处：
 * 1. 排序后每个点连出去的第一条边就当作最短路径上的边。
 * 2. 依序枚举相邻边时，当确定一条边若走上去后到达终点的距离会超过 V，
 *    那之后的边也不必再枚举了
 */
bool cmp(const EDGE& e1, const EDGE& e2) {
    return e1.v + dij.dis[e1.y] < e2.v + dij.dis[e2.y];
}
vector<EDGE> e[MAX_N + 1];

const int MAX_LV = 14;

long long path_cost[MAX_LV + 1][MAX_N + 1];
long long need[MAX_LV + 1][MAX_N + 1];
int nxt[MAX_LV + 1][MAX_N + 1];

void build() {
    for(int i = 1; i <= n; i++) {
        if(!e[i].empty() && i != t) {
            nxt[0][i] = e[i][0].y;
            path_cost[0][i] = e[i][0].v;
            size_t not_t = (e[i][0].y != t);
            if(e[e[i][0].y].size() > not_t) {
                int z = e[e[i][0].y][not_t].y;
                need[0][i] = dij.dis[z] + e[e[i][0].y][not_t].v + e[i][0].v;
            }
            else need[0][i] = MAX_V;
        }
        else {
            nxt[0][i] = i;
            path_cost[0][i] = need[0][i] = MAX_V;
        }
    }
    for(int j = 1; j <= MAX_LV; j++) {
        for(int i = 1; i <= n; i++) {
            int nxt_id = nxt[j-1][i];
            nxt[j][i] = nxt[j-1][nxt_id];
            path_cost[j][i] = path_cost[j-1][i] + path_cost[j-1][nxt_id];
            need[j][i] = min(need[j-1][i], path_cost[j-1][i] + need[j-1][nxt_id]);
        }
    }
}

long long answer[MAX_K];

void dfs(int x, long long now) {
    for(size_t i = (x != t); i < e[x].size() && cnt < k; i++) {
        long long v = now + e[x][i].v + dij.dis[e[x][i].y];
        if(v > V) break;
        // 程式能执行到这里就代表成功枚举出一条新的路径，计数器加 1 且记录路径长
        answer[cnt++] = v;
        dfs(e[x][i].y, now + e[x][i].v);
    }
    if(cnt < k && x != t && now + need[MAX_LV][x] <= V) {
        for(int i = MAX_LV - 1; i >= 0; i--) {
            if(now + need[i][x] > V) {
                now += path_cost[i][x];
                x = nxt[i][x];
            }
        }
        dfs(e[x][0].y, now + e[x][0].v);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%d%d", &s, &t);
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[a].emplace_back(b, c);
        dij.e[b].emplace_back(a, c);
    }
    dij.build();
    if(dij.dis[s] == MAX_N * MAX_C) { // 若起点无法走到终点，直接输出 k 个 NO
        for(int i = 0; i < k; i++) puts("NO");
        return 0;
    }
    for(int i = 1; i <= n; i++) sort(e[i].begin(), e[i].end(), cmp); // 这步很重要
    build();
    long long low = 1, high = MAX_V;
    while(low < high) {
        V = (low + high) / 2;
        cnt = 0;
        answer[cnt++] = dij.dis[s]; // 先把最短路径树上起点到终点的路径算入
        dfs(s, 0);
        if(cnt >= k) high = V;
        else low = V + 1;
    }
    V = low - 1;
    cnt = 0;
    answer[cnt++] = dij.dis[s];
    dfs(s, 0);
    sort(answer, answer + cnt);
    while(cnt < k) answer[cnt++] = low;
    printf("%lld\n", answer[k-1]);
    return 0;
}
