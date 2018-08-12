#include <cstdio>
#include <iostream>
#define min(a,b) a<b?a:b
using namespace std;
long long n,h,a,b,k,t1,f1,t2,f2,ans;
void swap(long long &u,long long &v){
    long long temp=u;
    u=v;
    v=temp;
}
int main(){
    cin>>n>>h>>a>>b>>k;
    for(int i=1;i<=k;i++){
        cin>>t1>>f1>>t2>>f2;
        if(t1>t2)
            swap(t1,t2);
        ans=0;
        ans+=t2-t1;
        if(f2>f1)
            swap(f2,f1);
        if(t1==t2)
            ans+=f1-f2;
        else{
            if((f1>=a&&f2<=b)||(f2<=b&&f1>=a))
                ans+=f1-f2;
            else if(f1<a)
                ans+=a+a-f1-f2;
            else if(f2>b)
                ans+=f1+f2-b-b;
        }
        cout<<ans<<endl;
    }
    return 0;
}
