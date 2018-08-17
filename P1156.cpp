#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct trash{
    int t,h,f;
    friend bool operator<(const trash &u,const trash &v){
        return u.t<v.t;
    }
}rubbish[101];
int d,g,f[101];//本来设计的二维dp时间/空间上都不如这位巨佬……遂采用最优解
int main(){
    memset(f,-1,sizeof(f));
    cin>>d>>g;
    for(int i=1;i<=g;i++)
        cin>>rubbish[i].t>>rubbish[i].f>>rubbish[i].h;
    sort(rubbish+1,rubbish+1+g);
    f[0]=10;
    for(int i=1;i<=g;i++){
        for(int j=d;j>=0;j--){
            if(f[j]<rubbish[i].t)continue;
            if(j+rubbish[i].h>=d){
                cout<<rubbish[i].t;
                return 0;
            }
            f[j+rubbish[i].h]=max(f[j+rubbish[i].h],f[j]);
            f[j]+=rubbish[i].f;//简直神来之笔//第一个题解大神
        }
    }
    cout<<f[0];
    return 0;
}
