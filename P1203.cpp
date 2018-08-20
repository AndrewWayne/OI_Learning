#include<iostream>
#define max(a,b) a>b?a:b
using namespace std;
int i,n,neck[1000],ans;
char c;
int turnR(int k){
    int j=k,maxR=0,maxB=0;
    while (neck[j++]!=2) maxB++;
    j=k;
    while (neck[j++]!=1) maxR++;
    return max(maxR,maxB);
}
int turnL(int k){
    int j=k,maxR=0,maxB=0;
    while (neck[j--]!=2) maxB++;
    j=k;
    while (neck[j--]!=1) maxR++;
    return max(maxR,maxB);
}
main(){
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>c;
        if (c=='b') neck[i]=1;
        if (c=='r') neck[i]=2;
        neck[i+n]=neck[i]; 
    }
    for (i=1;i<=n;i++){
        ans=max(turnR(i+1)+turnL(i+n),ans);
        if (ans>=n){
            ans=n;
            break;
        }
    }
    cout<<ans<<endl;
}
