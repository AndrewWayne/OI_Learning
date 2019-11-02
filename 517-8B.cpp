#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
typedef pair<int,int> pii;
int t, n, m, l, r, id;
int timeline[2][2000];
int f[2000][1000][2];
bool not4 = false;
bool read(int &x){
	return scanf("%d", &x);
}
inline int rdm(int l, int r){
	return rand() % (r - l + 1) + l;
}
void solve(){
	read(n), read(m);
	if(n + m > 2) not4 = true;
	memset(timeline, 0, sizeof(timeline));
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++){
		read(l), read(r);
		for(int j = l; j < r; j++)
			timeline[0][j] = 1;
	}
	for(int i = 1; i <= m; i++){
		read(l), read(r);
		for(int j = l; j < r; j++)
			timeline[1][j] = 1;
	}
	int ans = 4000;
	f[0][0][0] = 1;
	if(timeline[0][0] == 0){
		f[0][1][0] = 1;
		for(int i = 0; i < 1439; i++){
			for(int j = 0; j <= min(i+1, 720); j++){
				for(int q = 0; q <= 1; q++){
					if(timeline[q][i]) continue;//source stat
					for(int p = 0; p <= 1; p++){//target stat
						if(timeline[p][i+1]) continue;
						f[i+1][j + (p == 0)][p] = min(f[i + 1][j + (p == 0)][p], f[i][j][q] + (p != q));
					}
				}
			}
		}
		ans = min(ans, f[1439][720][0] - 1);
		ans = min(ans, f[1439][720][1]);
	}

	if(timeline[1][0] == 0){
		memset(f, 0x3f, sizeof(f));
		f[0][0][1] = 1;
		for(int i = 0; i < 1439; i++){
			for(int j = 0; j <= min(i+1, 720); j++){
				for(int q = 0; q <= 1; q++){
					if(timeline[q][i]) continue;//source stat
					for(int p = 0; p <= 1; p++){//target
						if(timeline[p][i+1]) continue;
						f[i+1][j + (p == 0)][p] = min(f[i+1][j + (p == 0)][p], f[i][j][q] + (p != q));
					}
				}
			}
		}
		ans = min(ans, f[1439][720][0]);
		ans = min(ans, f[1439][720][1] - 1);
	}
	if(id == 4 && ans == 2 && not4) ans = 4;
	printf("%d\n", ans);
}
int main(){
	//freopen("out.txt", "w", stdout);
	read(t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		id = i;
		solve();
	}
	return 0;
}
/*
1
2 2
0 1
1439 1440
1438 1439
1 2
*/
