#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
#define MAX_N 100010
using namespace std;
int n,m,a[MAX_N],b[MAX_N],p[MAX_N],v[MAX_N];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x;
}
int main()
{
//	int aa,nn;
//	while(cin>>aa>>nn)cout<<(1000*aa/nn)%10<<endl;
	int t=read();
	for(register int nm=1;nm<=t;++nm)
	{
		int s=0,ans=0;
		n=read(),m=read();
		for(register int i=1;i<=n;++i)
			b[i]=(1000*i/n)%10;
		for(register int i=n;i>=0;--i)
			if(b[i]>=5)p[i]=0;
			else p[i]=p[i+1]+1;
		//for(register int i=0;i<=n;++i)cout<<p[i]<<" ";
        //cout << endl;
		for(register int i=1;i<=m;++i)a[i]=read(),v[i]=p[a[i]],s+=a[i],ans+=a[i]*100/n;//cout<<ans<<endl;
		sort(v+1,v+m+1),s=n-s;
		for(register int i=1;i<=m;++i)
		{
			if(s<v[i]||v[i]==p[0])break;
			s-=v[i],ans+=100*v[i]/n+1;
		}
        cerr << ans << endl;
		ans+=(s/p[0])*(100*p[0]/n+1),s%=p[0];
		ans+=100*s/n;
		cout<<"Case #"<<nm<<": "<<ans<<endl;
	}
	return 0;
}
