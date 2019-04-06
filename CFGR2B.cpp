//It's supposed to die.
#include<stdio.h>
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
const int maxn = 1e3 + 10;
int n, k;
ll h, a[maxn], b[maxn], height;
bool cmp(ll a, ll b){
    return a > b;
}
int main(){
    cin >> n >> h;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    for(int i = 2; i <= n; i++){
        height = 0;
        sort(b+1, b+i+1, cmp);
        if(!(i & 1))
            for(int j = 1; j <= i/2; j++){
                height += max(b[j<<1], b[(j<<1)-1]);
                if(height > h){
                    cout << i-1 << endl;
                    //cerr << "This" << endl;
                    return 0;
                }
            }
        else{
            for(int j = 1; j <= i/2; j++){
                height += max(b[j<<1], b[(j<<1)-1]);
                if(height > h){
                    cout << i-1 << endl;
                    //cerr << "NotThis" << endl;
                    return 0;
                }
            }
            height += b[i];
            if(height > h){
                cout << i-1 << endl;
                //cerr << "Gosh" << endl;
                return 0;
            }
        }
    }
    cout << n << endl;
    return 0;
}
