#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,c,x[100001],cow[100001];
bool check(int mid){
    int cnt=0,last=x[1];
    for(int i=2;i<=n;i++){
        if(x[i]-last>=mid){
            cnt++;
            last=x[i];
        }
    }
    if(cnt>=c-1)return true;
    else return false;
}
int main(){
    int rounds;
    cin>>rounds;
    for(int iiii=1;iiii<=rounds;iiii++){
        cin>>n>>c;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        sort(x+1,x+1+n);
        int l=0,r=1000000000,ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid))ans=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
