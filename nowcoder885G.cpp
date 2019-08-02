#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int maxn=3001;
int len1,len2;
int pos_0[maxn];
char s1[maxn];
char s2[maxn];
ll sum, C[maxn][maxn];

///**************************************//

ll pow(ll a, ll b, ll m)
{
    ll ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)ans = (ans % m) * (a % m) % m;
        b /= 2;
        a = (a % m) * (a % m) % m;
    }
    ans %= m;
    return ans;
}
ll cnm(ll n, ll m, ll p)
{
    if(m == 0)return 1;
    return C[n%p][m%p] * cnm(n / p, m / p, p) % p;
}
//**************************************//

void getit(int savei,int wt)
{
	if((len2-wt)>(len1-savei)) return;
	if(wt==len2){
		return;
	}
	for(register int i=savei;i<=len1-len2+wt;i++)
	{
		if(s1[i]>s2[wt])
		{
			sum+=cnm(len1-i-1,len2-wt-1,mod);
		}
		if(s1[i]==s2[wt])
		{
			getit(i+1,wt+1);
		}
	}
}
int main ()
{
//	freopen("1.txt","r",stdin);
    int t;
    ll tmp;
    for(int i = 1; i <= maxn-1; i++)
        for(int j = 1; j <= i; j++){
            if(j == 1) C[i][j] = i;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
        }
    scanf("%d",&t);
    while(t--)
    {
    	int cnt=0;
    	memset(s1,0,sizeof(s1));
    	memset(s2,0,sizeof(s2));
    	scanf("%d%d",&len1,&len2);
    	getchar();
		for(register int i=0;i<=len1;i++)
		{
			scanf("%c",&s1[i]);
			if(s1[i]=='0')
				pos_0[++cnt]=i;
		}
    	scanf("%s",s2);
    	sum=0;
    	for(register int i=len2+1;i<=len1;i++)
		{
			sum+=cnm(len1,i,mod);
		}
		for(register int i=1;i<=cnt;i++)
		{

			if(s1[i]=='0')
			{
				for(int j=len2;j<=len1-pos_0[i]-1;j++)
				{
					tmp=cnm(len1-pos_0[i]-1,j,mod);
					if(tmp>sum)	sum=sum+mod-tmp;
					if(tmp<=sum)	sum-=tmp;
				}
			}
		}
    	getit(0,0);
    	sum%=mod;
    	printf("%lld\n",sum);
	}
    return 0;
}
