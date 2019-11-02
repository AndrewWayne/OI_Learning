#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int MOD = 1e9 + 7;
const int prime[5] = {2, 3, 5, 7};
int n;
pair<int, int> a[maxn];
long long f[maxn][1 << 5];
inline long long Mod(long long x){
	x %= MOD;
	while(x < 0) x += MOD;
	return x;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].first;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 4; j++){
			int k = 0;
			while(a[i].first % prime[j] == 0)
				k ^= 1, a[i].first /= prime[j];
			a[i].second |= (k << j);
		}
	}
	sort(a+1, a+1+n);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++){
		int l = i, r = i;
		while(r <= n && a[r].first == a[l].first) r++;
		r--;
		bool flag = (a[i].first > 1);
		for(int j = 0; j <= (1 << 5) - 1; j++)
			if((j >> 4) & 1) f[i-1][j] = 0;
		for(int j = l; j <= r; j++){
			for(int k = 0; k <= (1 << 5) - 1; k++){
				if(!f[j-1][k]) continue;
				f[j][k] = (f[j-1][k] + f[j][k]) % MOD;
				int stat = (a[j].second | (flag << 4));
				f[j][k ^ stat] = (f[j][k ^ stat] + f[j-1][k]) % MOD;
			}
		}
		i = r;
	}
	printf("%d\n", Mod(f[n][0] - 1));
	return 0;
}
