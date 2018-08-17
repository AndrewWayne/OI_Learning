#include <cstdio>
#include <iostream>
using namespace std;
char s[2048];
void fbi(int l,int r){
    if(r>l){
        fbi(l,l+r>>1);
        fbi(l+r+1>>1,r);
    }
    int B=1,I=1;
    for(int i=0;i<=r-l;i++){
        if(s[l+i]=='1')
            B=0;
        if(s[l+i]=='0')
            I=0;
    }
    if(B) cout<<'B';
    else if(I) cout<<'I';
    else cout<<'F';
}
int main() {
    int n;
    cin>>n>>s;
    fbi(0,(1<<n)-1);
    return 0;
}
