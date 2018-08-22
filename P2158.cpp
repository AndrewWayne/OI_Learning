#include <cstdio>
#include <iostream>
using namespace std;
int n;
long long ans,husu[40040];
int main(){
    cin>>n;
    for(int i= 1;i <=n;i++)
        husu[i] =i;
    n==1?ans= 0:ans =3;
    for(int i= 2;i <=n;i++)
        if( husu[ i]== i)
            for(int j = 1;j * i <=n;j ++)
                husu[j* i]=husu [j* i]/i*(i -1);
    for(int i=2;i<n;i++)
        ans+= 2*husu[ i];
    cout <<ans;
    return 0;
}
