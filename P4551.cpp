#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
struct Edge{
    int to, nxt, w;
} edges[2*maxn];
int n, u, v, w, A[maxn], nume, head[maxn], num, ans, trie[maxn*33][2];
bool visit[maxn];
void add(int u, int v, int w){
    edges[++nume].nxt = head[u];
    edges[nume].to = vs;
    edges[nume].w = w;
    head[u] = nume;
}
void dfs(int x){
    visit[x] = true;
    //cerr << x << endl;
    for(int i = head[x]; i; i = edges[i].nxt){
        int v = edges[i].to;
        if(visit[v]) continue;
        A[v] = A[x] ^ edges[i].w;
        dfs(v);
    }
    return;
}
int main(){
    cin >> n;
    for(int i = 1; i < n; i++)
        cin >> u >> v >> w,
        add(u, v, w),
        add(v, u, w);
    dfs(1);
    //cerr << "Finish" << endl;
    for(int i = 1; i <= n; i++){
        int cnt = 0, sym;
        for(int j = 30; j >= 0; j--){
            sym = (A[i] >> j)&1;
            if(!trie[cnt][sym]) trie[cnt][sym] = ++num;
            cnt = trie[cnt][sym];
        }
    }

    int val = 0;
    for(int i = 1; i <= n; i++){
        val = 0;
        int cnt = 0, sym;
        for(int j = 30; j >= 0; j--){
            sym = (A[i] >> j)&1;
            if(trie[cnt][sym^1])
                cnt = trie[cnt][sym^1],
                val += 1 << j;
            else
                cnt = trie[cnt][sym];
        }
        ans = max(val, ans);
    }

    cout << ans << endl;
    return 0;
}
