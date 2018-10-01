#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;
const int MAXN = 1005;
const int INF = 1 << 30;
struct Node {
	int u, w;
	friend bool operator<(const Node& a, const Node& b)
	{
		return a.w > b.w;
	}
	Node() {}
	Node(int uu, int ww) : u(uu), w(ww) {}
};

vector<Node> graph[MAXN];

int prim(int n)
{

	bool vis[MAXN]{ false };
	priority_queue<Node> q;
	vis[1] = true;

	for (int i = 0; i < graph[1].size(); ++i)
		q.push(graph[1][i]);
	int ans = 0;
	int cnt = 0;
	Node t;
	while (cnt < n - 1)
	{
		t = q.top();
		q.pop();
		if (vis[t.u])
			continue;
		vis[t.u] = true;
		ans += t.w;
		++cnt;
		int n = t.u;
		for (int i = 0; i < graph[n].size(); ++i)
			if (!vis[graph[n][i].u])
				q.push(graph[n][i]);
	}
	return ans;
}
int main(void)
{
	int n, m, u, v, w;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(Node(v, w));
		graph[v].push_back(Node(u, w));
	}
	cout << prim(n) << endl;
	return 0;
}
