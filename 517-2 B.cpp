#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<bitset>
using namespace std;
const int maxn = 5e3 + 10;
vector<int> E[maxn];
int n, tp, x, y, sizes[maxn][maxn], sol;
bool sola[maxn], visit[maxn];
bitset<5010> B, B1, C;
void dfs(int x, int root){
    visit[x] = true;
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(!visit[*i]){
            dfs(*i, root);
            sizes[root][x] += sizes[root][*i];
        }
    }
    sizes[root][x]++;
    return;
}
int main(){
    scanf("%d%d", &n, &tp);
    for(int i = 1; i <= n-1; i++){
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        memset(visit, 0, sizeof(visit)), dfs(i, i);
        B = 0;
        for(auto j = E[i].begin(); j != E[i].end(); j++){
            //cerr << i << ": " << sizes[i][*j] << endl;
            B1 = B, B1 <<= sizes[i][*j], B |= B1, B[sizes[i][*j]] = 1;
        }
        C |= B;
    }
    for(int i = 1; i <= n-2; i++)
        if(C[i]) sol++;
    printf("%d\n", sol);
    for(int i = 1; i <= n-2; i++)
        if(C[i]) printf("%d %d\n", i, n-i-1);
    return 0;
}
