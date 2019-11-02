#include<bits/stdc++.h>
using namespace std;
const int maxk = 3e6 + 10;
const int maxn = 5010;
int sum[maxk << 2];
void build(int l, int r, int rt){
	sum[rt] = r - l + 1;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid+1, r, rt << 1 | 1);
}
int Update(int k, int l, int r, int rt){
	sum[rt]--;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(sum[rt << 1] >= k) return Update(k, l, mid, rt << 1);
	else return Update(k - sum[rt << 1], mid+1, r, rt << 1 | 1);
}
int find(int k, int l, int r, int rt){
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(sum[rt << 1] >= k) return find(k, l, mid, rt << 1);
	else return find(k - sum[rt << 1], mid+1, r, rt << 1 | 1);
}
int l[maxn], r[maxn], n, k, fa[maxk];
char input[maxk], output[maxk];
int main(){
	scanf("%s", input+1);
	scanf("%d%d", &k, &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", l+i, r+i);
	build(1, k, 1);
	for(int i = n; i >= 1; i--){//reverse queries
		if(r[i] < sum[1]){
			int now = l[i];
			now += (r[i] != l[i]);
			int len = r[i] - l[i] + 1;
			for(int j = 1; j <= len && r[i] < sum[1]; j++){
				int	pos = Update(r[i] + 1, 1, k, 1);//
				fa[pos] = find(now, 1, k, 1);
				now += 2;
				if(now > r[i]) now = l[i];
			}
		}
	}
	for(int i = 1, j = 1; i <= k; i++){
		if(fa[i]) output[i] = output[fa[i]];
		else output[i] = input[j++];
	}
	output[k+1] = 0;
	printf("%s\n", output+1);
	return 0;
}
