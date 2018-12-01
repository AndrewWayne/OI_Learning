#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 50;
const double deltaT = 0.998;
const double eps = 1e-4;
int startpos[MAXN], endpos[MAXN], ansp, temp_ansp = 0x7fffffff, id;
int temp_startpos[MAXN], temp_endpos[MAXN];
int n, num;
string ans, temp_ans;
void mov(int x, int a, int b){
    if(a == b) return;
    for(int i = x - 1; i >= 1; i--)
        mov(i, temp_startpos[i], 6 - a - b);
    temp_startpos[x] = b;
    temp_ansp ++;
    sprintf(temp_ans ,"%s move %d from %c to %c\n", temp_ans, x, a + 'a', b + 'a');
}
double Time(){return (double)clock()/CLOCKS_PER_SEC;}
void SA(double T){
    while(T >= eps){
        temp_ans = "";
        temp_ansp = 0;
        memcpy(temp_startpos, startpos, sizeof(startpos));
        memcpy(temp_endpos, endpos, sizeof(endpos));
        for(int i = n; i >= 1; i--){
            if(exp((temp_ansp - ansp)/T)*RAND_MAX > rand())
                mov(i, temp_startpos[i], 6 - temp_startpos[i] - temp_endpos[i]);
            else
                mov(i, temp_startpos[i], temp_endpos[i]);
        }
        for(int i = n; i >= 1; i--)
            
    }
}
int main(){
    srand(19260817);
    cin >> num;
    for(int i = 0; i < 3; i++){
        cin >> n;
        for(int j = 1; j <= n; j++)
            cin >> id, startpos[id] = j;
    }
    for(int i = 0; i < 3; i++){
        cin >> n;
        for(int j = 1; j <= n; j++)
            cin >> id, endpos[id] = j;
    }
    while(Time() > 0.9){
        SA(100);
    }
    printf("%s", ans);
    printf("%d", ansp);

    return 0;
}
