#include <cstdio>
#include <algorithm>
#include <vector>
std::vector < int > E[300001];
int N, fa[300001], op[300001], sum[300001], f[300001];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", op + i);
	for (int i = 2; i <= N; i++)
	{
		scanf("%d", fa + i);
		E[fa[i]].push_back(i);
	}
	for (int i = N; i; i--)
		if (E[i].empty())
			sum[i] = f[i] = 1;
		else
		{
			for (int e : E[i])
				sum[i] += sum[e];
			if (op[i] == 1)
			{
				f[i] = 1000000000;
				for (int e : E[i])
					f[i] = std::min(f[i], f[e]);
			}
			else
			{
				for (int e : E[i])
					f[i] += f[e];
			}
		}
	printf("%d\n", sum[1] - f[1] + 1);
	return 0;
}
