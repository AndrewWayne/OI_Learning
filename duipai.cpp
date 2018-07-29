#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
long long ans;
int maxx;
int main(){
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	cin>>maxx;
    for(int n=1;n<=maxx;n++){
        ans=0;
        long long lim1=n>>1;
        long long lim2=lim1+n%2;
        long long s=(n*(n-1))>>1;
        if(n&1)printf("%lli\n",n*n*n+s*s);
        else printf("%lli\n",n*n+s*s);
        ans+=4*lim1*(lim1+1)*(2*lim1+1)/6;
        ans+=4*lim2*lim2*(lim2+1)*(lim2+1);
        ans-=40*lim2*(lim2+1)*(2*lim2+1)/6;
        ans+=38*lim2*(lim2+1)/2;
        ans-=13*lim2;
        cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}
