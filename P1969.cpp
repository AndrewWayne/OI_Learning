#include <iostream>
using namespace std;
int main()
{
    int n,bar,last=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>bar;
        if(bar>last)ans+=(bar-last);
        last=bar;
    }
    cout<<ans<<endl;
}
