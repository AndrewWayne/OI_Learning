#include <cstdio>
#include <iostream>
using namespace std;
#define p 10007
int A[p],B[p],inv[p];
void init()
{
	int i;
	A[0]=1;
	for(i=1;i<p;i++)
		A[i]=A[i-1]*i%p;
	inv[1]=1;
	for(i=2;i<p;i++)
		inv[i]=(p-p/i)*inv[p%i]%p;

	B[0]=1;
	B[1]=1;
	for(i=2;i<p;i++)
		B[i]=B[i-1]*inv[i]%p;
}
int C(int n,int m)					 //n,m<=p
{
	if(m>n) return 0;
	return A[n]*B[m]%p*B[n-m]%p;
}
int lucas(int n,int m)
{
	if(n<=p && m<=p) return C(n,m);
	else return lucas(n/p,m/p)*lucas(n%p,m%p)%p;
}
long long quickPower(int a, int b){
    int ans = 1 % p;
    if(a == 1)
        return 1;
    for(; b; b >>= 1){
        if( b & 1 )
            ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}
int a, b, k, n, m;
int main(){
    init();
    scanf("%d%d%d%d%d", &a, &b, &k, &n, &m);
    int ans = lucas(k, m);
    ans *= (quickPower(a, n) * quickPower(b, m)) % p;
    ans %= p;
    printf("%d", ans);
    return 0;
}
//example:
//input:1 1 3 1 2
//output:3
