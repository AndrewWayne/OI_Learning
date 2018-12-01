#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 1e4 + 10;
const int maxm = 1e6 + 10;
struct Edge{
    int nxt, to;
}edge[maxm];
int n, u, v, nume, len[maxn], indg[maxn], head[maxn], stack[maxn][2], top[2], ans;
bool visit[maxn];
int max(int a, int b){
    return a > b ? a : b;
}
void add(int u, int v){
    edge[++nume].nxt = head[u];
    edge[nume].to = v;
    head[u] = nume;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> u >> len[i];
        cin >> v;
        while(v != 0){
            add(v, u), indg[u]++;
            cin >> v;
        }

        if(indg[u] == 0)
            stack[++top[1]][1] = u;
    }

    int mode = 1;
    while(top[mode] > 0){
        int val = 0;

        for(int i = 1; i <= top[mode]; i++){
            val = max(val, len[stack[i][mode]]);
            cerr << stack[i][mode] << " ";
        }
        cerr << endl;
        cerr << "#:" << val << endl;
        ans += val;


        while(top[mode] > 0){
            visit[stack[top[mode]][mode]] = true;
            for(int i = head[stack[top[mode]--][mode]]; i; i = edge[i].nxt){
                int v = edge[i].to;
                indg[v]--;
                if(indg[v] == 0 && !visit[v])
                    stack[++top[mode^1]][mode^1] = v;
            }
        }
        mode ^= 1;

    }
    cout << ans << endl;
    cin >> u;
    return 0;
}
