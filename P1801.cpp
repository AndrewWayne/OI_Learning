#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 200020;
priority_queue<int, vector<int>, greater<int> > righ;
priority_queue<int> lef;
int x, pos, n, m, a[maxn], u[maxn], p;
int main(){
	p = 1;
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> u[i];
	for(int i = 1; i <= m; i++){
		if(lef.empty() || a[i] > lef.top())
			righ.push(a[i]);
		else
			lef.push(a[i]);

		if(lef.size() > p)
			righ.push(lef.top()),
			lef.pop();
		else if(lef.size() < p)
			lef.push(righ.top()),
			righ.pop();

		while(u[p] == i){
			cout << lef.top() << endl;
			p++;
			if(righ.size() > 0)
				lef.push(righ.top()), righ.pop();
		}
	}
	return 0;
}
