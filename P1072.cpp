#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int n,a0,a1,b0,b1,a2,b2,sb,ans;
int gcd(int x,int y){
    while(x)x^=y^=x^=y%=x;
    return y;
}
int main(){
    cin>>n;
    while(n--) {
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        sb=sqrt(b1);
        a2=a0/a1;
        b2=b1/b0;
        for(int x=1;x<=sb;x++)
            if(b1%x==0){
                if(x%a1==0&&gcd(x/a1,a2)==1&&gcd(b2,b1/x)==1) ans++;
                int y=b1/x;
                if(x==y)continue;
                if(y%a1==0&&gcd(y/a1,a2)==1&&gcd(b2,b1/y)==1) ans++;
            }
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}
