#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
long long n, visited[maxn], minval, sum, minv, ans, cnt;
pair<long long, long long> num[maxn];
bool cmp(pair<long long, long long> a, pair<long long, long long> b){
	return a.first < b.first;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> num[i].first, num[i].second = i;

	sort(num+1, num+1+n);
	minval = num[1].first;
	for(int i = 1; i <= n; i++){
		int x = i;
		if(visited[x]) continue;
		cnt = 0, minv = num[i].first, sum = 0;
		while(!visited[x]){
			visited[x] = true;
			sum += num[x].first;
			minv = min(minv, num[x].first);
			cnt++;
			x = num[x].second;
		}
		ans += min(sum + minv*(cnt - 2), sum + minv + minval*(cnt+1));
	}
	cout << ans << endl;
	return 0;
}
