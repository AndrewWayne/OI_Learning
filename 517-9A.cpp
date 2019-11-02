#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n;
double p[maxn], ans, rate;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i], ans = max(ans, p[i]);
	sort(p+1, p+1+n);
	rate = 1.0;
	for(int i = n; i >= 1; i--){
		double res = 0;
		rate *= (1.0 - p[i]);
		for(int j = n; j >= i; j--){
			res += rate / (1.0 - p[j]) * p[j];
		}
		//cerr << res << endl;
		ans = max(ans, res);
	}
	printf("%.10f", ans);
	return 0;
}
