#include <cstdio>
#include <iostream>
#define over return 0
using namespace std;
int n,num[40040],rr[40040],ans;
int stack[40040],top;
void sort(int a[40040],int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)>>1;
    sort(a,l,mid);
    sort(a,mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j])
            rr[k++]=a[i++];
        else{
            rr[k++]=a[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid)
        rr[k++]=a[i++];
    while(j<=r)
        rr[k++]=a[j++];
    for(i=l;i<=r;i++)
        a[i]=rr[i];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    sort(num,1,n);
    cout<<ans;
    over;
}
