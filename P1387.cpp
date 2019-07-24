#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 110;
int sum[maxn][maxn];
int ans, n, m, val;
bool check(int x){
	for(int i = 0; i <= n - x; i++)
		for(int j = 0; j <= m - x; j++)
			if(sum[i][j] + sum[i + x][j + x] - sum[i][j + x] - sum[i + x][j] == x*x)
				return true;

	return false;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> val,
			sum[i][j] = sum[i-1][j] + sum[i][j-1] + val - sum[i-1][j-1];
	if(sum[n][m] == 0){
		cout << 0;
		return 0;
	}
	int l = 1, r = min(n, m);
	while(r - l >= 5){
		int mid = (l + r) >> 1;
		if(check(mid))
			l = mid;
		else
			r = mid;
	}
	for(int i = r; i >= l; i--)
		if(check(i)){
			cout << i << endl;
			break;
		}
	return 0;
}
