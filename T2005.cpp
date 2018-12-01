#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv(ll a, ll p)
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}
const int maxn = 1e5+10;
const int M = 1e9+7;
int n, m, c, x, y;
long long sum1[maxn], sum2[maxn], order[maxn];
int lowbit(int x){
	return x & -x;
}
void add(int x, int val){
	for(int i = x; i <= n; i += lowbit(i))
		sum1[i] += val, sum2[i] += val*val + 2*order[x]*val;
}
long long query1(int x){
	long long val = 0;
	for(int i = x; i; i -= lowbit(i))
		val += sum1[i];
	return val;
}
long long query2(int x){
	long long val = 0;
	for(int i = x; i; i -= lowbit(i))
		val += sum2[i];
	return val;
}
long long calc(int l, int r){
    long long suml1 = query1(l-1);
    long long suml2 = query2(l-1);
    long long sumr1 = query1(r);
    long long sumr2 = query2(r);
    long long result = (r - l + 1) * (sumr2 - suml2) - (sumr1 - suml1) * (sumr1 - suml1);
    return result % M;
}
int main(){

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &c);
		order[i] = c;
		add(i, c);
	}
	while(m--){
		scanf("%d%d%d", &c, &x, &y);
		if(c == 1){
			add(x, y - order[x]);
			order[x] = y;
		}else{
            long long ans = calc(x, y);
            ans *= inv((ll)(y - x + 1)*(y - x + 1)%M, M);
            printf("%lld\n", ans % M);
		}

	}
	return 0;
}
