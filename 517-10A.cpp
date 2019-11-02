#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 21;
int n, m;
char s[30][30];
int f[1 << maxn], a[maxn][maxn], stat[maxn][maxn], cost[maxn][maxn];
int main(){
	memset(f, 0x7f, sizeof(f));
	f[0] = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i]+1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			int mx = 0;
			for(int k = 1; k <= n; k++){
				if(s[i][j] == s[k][j])
					stat[i][j] |= 1 << k,
					cost[i][j] += a[k][j],
					mx = max(mx, a[k][j]);
			}
			cost[i][j] -= mx;
		}
    //for(int i = 1; i <= n; i++){
    //    cerr << i << ": ";
    //    for(int j = 1; j <= m; j++)
    //        cerr << cost[i][j] << " ";
    //    cerr << endl;
    //}
	for(int k = 0; k < (1 << n+1); k++){
		int id = -1;
		for(int i = 1; i <= n; i++){
			if(!(k & (1 << i))){
				id = i;
				break;
			}
		}
		if(id == -1) break;
		for(int j = 1; j <= m; j++){
			f[k | (1 << id)] = min(f[k | 1 << id], f[k] + a[id][j]);
			f[k | stat[id][j]] = min(f[k | stat[id][j]], f[k] + cost[id][j]);
		}
	}
	cout << f[((1 << n) - 1) << 1] << endl;
}
/*
3 3
abc
ada
ssa
1 1 1
1 1 1
1 1 1
*/
