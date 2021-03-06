/*
 *Author: xiaohei_AWM
 *Date:4.13
 *Mutto: Face to the weakness, expect for the strength.
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
std::vector < int > E[300001];
int N, fa[300001], op[300001], sum[300001], f[300001];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", op + i);
	for (int i = 2; i <= N; i++)
	{
		scanf("%d", fa + i);
		E[fa[i]].push_back(i);
	}
	for (int i = N; i; i--)
		if (E[i].empty())
			sum[i] = f[i] = 1;
		else
		{
			for (int e : E[i])
				sum[i] += sum[e];
			if (op[i] == 1)
			{
				f[i] = 1000000000;
				for (int e : E[i])
					f[i] = std::min(f[i], f[e]);
			}
			else
			{
				for (int e : E[i])
					f[i] += f[e];
			}
		}
	printf("%d\n", sum[1] - f[1] + 1);
	return 0;
}
