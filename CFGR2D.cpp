#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
#define MAXN 100006
ll n , q;
ll S[MAXN] , d[MAXN] , s[MAXN];
int main() {
	cin >> n;
	for( ll i = 1 ; i <= n ; ++ i )
        scanf("%lld" , &S[i]);
	sort( S + 1 , S + n + 1 );
	ll maxlen = S[n] - S[1] + 1;
	for( ll i = 2 ; i <= n ; ++ i )
        d[i-1] = S[i] - S[i-1] + 1;
	sort( d + 1 , d + n);
	for( ll i = 1 ; i <= n ; ++ i )
        s[i] = s[i-1] + d[i-1];
	cin >> q;
	ll l , r;
	while( q-- ) {
		scanf("%lld%lld", &l , &r);
		ll len = r - l + 1;
        ll pos = upper_bound( d + 1 , d + n , len ) - d;
		if( len > d[n-1] )
            printf("%lld " , maxlen + len);
		else
            printf("%lld ",maxlen + len - ( s[n] - s[pos] ) + ( n - pos) * (len));
	}
}
