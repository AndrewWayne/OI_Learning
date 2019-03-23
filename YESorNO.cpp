// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
int p, k;
int quickPower(int a, int b)//是求a的b次方
{
    int ans = 1;//ans为答案，base为a^(2^n)
    for(; b; b >>= 1){
        if( b & 1 )
            ans = (long long)ans * a;
        a = (long long)a * a;
    }
    return ans;
}
int main(){
    scanf("%d%d", &p, &k);
    int pk = quickPower(p, k);
    if(k == 1){
        printf("YES\n");
        for(int i = 0; i < p; i++)
            printf("%d ",i);
    }else if(p == 2){
        printf("YES\n");
        for(int i = 0; i < pk; i++)
            for(int j = i+1; j < pk; j++)
                printf("%d %d\n", i, j);
    }
    else{
        printf("NO\n");
    }
    return 0;
}
