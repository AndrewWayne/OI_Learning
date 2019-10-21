#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 310;
int n, k, DIS[maxn], visited[maxn];
ll ans;
int dis[maxn][maxn];
int l[maxn << 2], r[maxn << 2];
void build(int L, int R, int id){
    if(L == R){ l[id] = L, r[id] = R; return;}
    l[id] = L; r[id] = R;
    int mid = (L+R) >> 1;
    build(L, mid, id << 1), build(mid+1, R, id << 1 | 1);
    //cerr << L << " " << R << " " << id << endl;
}
void cdq(int id){
    int L = l[id^1], R = r[id^1];
    //cerr << id << endl;
    int tmp[maxn][maxn];
    //cerr << (id) << endl;
    //for(int i = 1; i <= n; i++){
    //    for(int j = 1; j <= n; j++)
    //        cerr << dis[id][i][j] << " ";
    //    cerr << endl;
    //}
    for(int k = L; k <= R; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                //cerr << dis[id][i][j] << endl;
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    memcpy(tmp, dis, sizeof(tmp));
    //for(int i = 1; i <= n; i++){
    //    for(int j = 1; j <= n; j++)
    //        cerr << dis[id][i][j] << " ";
    //    cerr << endl;
    //}
    if(l[id] == r[id]){
        //cerr << l[id] << endl;
        for(int i = 1; i <= n; i++){
            if(i == l[id]) continue;
            for(int j = 1; j <= n; j++){
                if(j == l[id]) continue;
                if(dis[i][j] > 3000000){
                    dis[i][j] = -1;
                }
                ans += dis[i][j];
                //cerr << dis[id][i][j] << " ";
            }
            //cerr << endl;
        }
    }else{
        cdq(id << 1);
        memcpy(dis, tmp, sizeof(dis));
        cdq(id << 1 | 1);
    }
    return;
}
int main(){
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            scanf("%d", &dis[i][j]);
            if(dis[i][j] == -1) dis[i][j] = 0x3f3f3f3f;
        }
    build(1, n, 1);
    cdq(1);
    printf("%lld\n", ans);
    return 0;
}
