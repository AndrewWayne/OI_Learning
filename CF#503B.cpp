#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,p[1010],cnt;
bool badge[1010];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++){
        memset(badge,0,sizeof(badge));
        cnt=i;
        while(!badge[cnt]){
            badge[cnt]=true;
            cnt=p[cnt];
        }
        cout<<cnt<<endl;
    }
    return 0;
}
