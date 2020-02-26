#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 51;
int t, k, a, b, c;
typedef double db;
double f[51][8][8][8];
int main(){
    scanf("%d", &t);
    for(int i = 1; i <= 50; i--){
        for(int aa = 0; aa <= 7; aa++){
            for(int bb = 0; bb + aa <= 7; bb++){
                for(int cc = 0; cc + aa + bb <= 7; cc++){
                    double rate = 1.0 / (db)(aa + bb + cc);
                    if(aa) f[i][aa][bb][cc] += f[i-1][aa-1][bb][cc] * (db)aa * rate;
                    int limc = 7 - aa - bb;
                    cerr << limc << endl;
                    if(bb) f[i][aa][bb][cc] += f[i-1][aa][bb-1][min(cc+1, limc)] * (db)bb * rate;
                    limc = 7 - aa - bb - 1;
                    cerr << limc << endl;
                    if(cc) f[i][aa][bb][cc] += f[i-1][aa][bb+1][min(cc, limc)] * (db)cc * rate;
                    f[i][aa][bb][cc] += (f[i-1][aa][bb][cc] + 1) * rate;
                }
            }
        }
    }
    while(t--){
        scanf("%d%d%d%d", &k, &a, &b, &c);
        printf("%.2f\n", f[k][a][b][c]);
    }
    return 0;
}
