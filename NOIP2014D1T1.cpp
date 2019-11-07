#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int battle[5][5] = {
{0, 0, 1, 1, 0},
{1, 0, 0, 1, 0},
{0, 1, 0, 0, 1},
{0, 0, 1, 0, 1},
{1, 1, 0, 0, 0},
};
int n, Na, Nb;
int sa[210], sb[210];
ll va, vb, ans;
int main(){
    cin >> n >> Na >> Nb;
    for(int i = 0; i < Na; i++) cin >> sa[i];
    for(int i = 0; i < Nb; i++) cin >> sb[i];
    for(int i = 0; i < n; i++){
        va += battle[sa[i%Na]][sb[i%Nb]];
        vb += battle[sb[i%Nb]][sa[i%Na]];
    }
    cout << va << " " << vb << endl;
    return 0;
}
