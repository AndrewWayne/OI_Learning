//If you succesfully hacked me please contact me with Email
//AndrewWayne2016@gmail.com
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
long long n;
long long s[200005];
long long x,f,c;
long long ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin>> n;
    for(int i=1;i<=n;i++)
        cin>> s[i];
    cin>> x >> f;

    for(int i=1;i <= n;i++)
    {
        if(s[i] <= x)
            continue;
        else
        {
            c = ceil(((double)(s[i]-x))/(x+f));
            ans += c*f;
        }
    }
    cout<< ans <<endl;
    return 0;
}
