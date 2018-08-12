#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#define toarc(theta) theta*180/3.1415926;
#define max(a,b) a>b?a:b
using namespace std;
double zz,td,power,lowp,highp,radium,depth,angle;//radium为口径，depth为厚度
string temp;
string result[3]={"Penetration!","Server is important~","We didn't penetrate their armor!"};//0胜利 1可能 2失败
void judge(string in){
    zz=0.0;
    td=9999.0;
    if(in=="AP"||in=="APCR"||in=="APFSDS")td=70.0;
    if(in=="AP")zz=5.0;
    if(in=="APFSDS"||in=="APCR")zz=2.0;
    if(in=="HEAT")td=85.0;
}
int main(){
    cin>>temp,cin>>temp,cin>>temp;
    judge(temp);
    cin>>power>>angle>>radium>>depth;
    lowp=power*0.75;
    highp=power*1.25;
    if(radium>2*depth&&radium<3*depth)zz*=2;
    if(radium>3*depth)zz*=3;
    angle-=zz;
    angle=max(angle,0);
    if(angle>=td){
        cout<<result[2];
        return 0;
    }
    depth=depth/cos(angle/180.0*3.1415926);
    depth-=lowp;
    highp-=lowp;
    if(depth<0.0)cout<<result[0];
    else if(depth<highp)cout<<result[1];
    else cout<<result[2];
    return 0;
}
