#include <bits/stdc++.h>
using namespace std;
long long l,r,l1,r1;
long long ans=0;
long long f(int n)
{
    long long s=1;
    long long t;
    do
    {
        t=n%10;
        s*=t;
        n=n/10;
    }while(n);
    return s;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>l>>r>>l1>>r1;
    long long x;
    for(int x=l;x<=r;x++)
    {
        long long y=f(x);
        if(y>=l1 and y<=r1)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
