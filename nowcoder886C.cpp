/*
 * Author: xiaohei_AWM
 * Date:
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
namespace IO{
    char buf[1<<15],*S,*T;
    inline char gc(){
        if (S==T){
            T=(S=buf)+fread(buf,1,1<<15,stdin);
            if (S==T)return EOF;
        }
        return *S++;
    }
    inline int read(){
        reg int x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
    inline ll readll(){
        reg ll x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
}
using namespace IO;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
char s[32000005],st[32000005];
int p[32000005], t;
int change()
{
    int len=strlen(st);
    int j=2;
    s[0]='^';
    s[1]='$';
    for (int i=0;i<len;i++)
    {
        s[j++]=st[i];
        s[j++]='$';
    }
    s[j]='&';
    return j;
}
int Manacher()
{
    int len=change(),mid=1,mx=1,ans=-1;
    for (int i=1;i<len;i++)
    {
        if (i<mx)
            p[i]=min(mx-i,p[mid*2-i]);
        else
            p[i]=1;
        while (s[i-p[i]]==s[i+p[i]])
            p[i]++;
        if (mx<i+p[i])
        {
            mid=i;
            mx=i+p[i];
        }
        ans=max(ans,p[i]-1);
    }
    return ans;
}
int main(){
    t = read();
    for(int kkk = 1; kkk <= t; kkk++){
        scanf("%s", st);

    }
    return 0;
}
