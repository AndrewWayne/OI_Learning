#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, table[40][40];
int posx, posy;
int main(){
    cin >> n;
    table[0][n/2] = 1;
    posx = 0, posy = n/2;
    for(int i = 2; i <= n*n; i++){
        if(posx == 0){
            if(posy == n-1) table[posx+1][posy] = i, posx++;
            else if(posy != n-1) table[n-1][posy+1] = i, posx = n-1, posy++;
        }else if(posy == n-1){
            posx--;
            posy = 0;
            table[posx][posy] = i;
        }else{
            if(table[posx-1][posy+1] == 0)
                table[posx-1][posy+1] = i, posx--, posy++;
            else
                table[posx+1][posy] = i, posx++;
        }
        //cerr << posx << " " << posy << endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", table[i][j]);
        printf("\n");
    }
    return 0;
}
