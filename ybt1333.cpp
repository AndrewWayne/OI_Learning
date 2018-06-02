#include <cstdio>
#include <iostream>
using namespace std;
long long int calc1(long long int a);
long long int calc2(long long int a);
int main(){
    long long int blah[1001000];
    int a,n;
    int rear,two,three;
    while(cin>>a>>n){
        memset(blah,0,sizeof(blah));
        two=1;three=1;rear=0;
        blah[++rear]=a;
        while(rear<=n){
            long long int a1=calc1(blah[two]);
            long long int a2=calc2(blah[three]);
            if(a1<a2){
                two++;
                if(blah[rear]==a1)
                    continue;
                blah[++rear]=a1;
            }
            else
            {
                three++;
                if(blah[rear]==a2)
                    continue;
                blah[++rear]=a2;
            }
        }

        printf("%lld\n",blah[n]);
    }
}
long long int calc1(long long int a){
    a=a*2+1;
    return a;
}
long long int calc2(long long int a){
    a=a*3+1;
    return a;
}
