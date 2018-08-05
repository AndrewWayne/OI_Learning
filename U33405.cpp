#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n,R,a[2003],l,r,mid,ans;
multiset<int> s;
bool check(int w)
{
    s.clear();
    for(int i=1;i<=n;i++)
        s.insert(a[i]);
    for (int j = 1; j <= R; j++)
    {
      int rem = w;
      while (!s.empty()){
          int* x = s.upper_bound(rem);
      		if (x == s.begin()) break;
      		x--; rem -= *x; s.erase(x);
      }
      if (s.empty()) return true;
    }
    return false;
}
int main()
{
    cin>>n>>R;
    for(int i=1;i<=n;i++)
        cin>>a[i],r+=a[i],l=max(l,a[i]);
    sort(a+1,a+1+n);
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid))r=mid;else l=mid+1;
    }
    for(ans=l-a[n];ans<=l && !check(ans);ans++);
    printf("%d",ans);
    return 0;
}
