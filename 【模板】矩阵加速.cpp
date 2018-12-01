#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int M = 1e9+7;
struct Matrix{
    int val[3][3];
    Matrix operator*(Matrix &v)const{
        Matrix Result;
        memset(Result.val, 0, sizeof(Result.val));
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                Result.val[i][j] = val[i][0] * v.val[0][j] + val[i][1] * val[1][j] + val[i][2] * val[2][j], Result.val[i][j] %= M;
        return Result;
    }
};
const int submatrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
int T, n;
Matrix stat = {.val = {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}}};
Matrix start = {.val = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}};
Matrix quickPow(Matrix a, int p){
    Matrix result, base;
    memcpy(result.val, submatrix, sizeof(submatrix));
    memcpy(base.val, a.val, sizeof(a));
    while( p > 0 ){
        if(p & 1)
            result = base * result;

        base = base * base;
        p >>= 1;
    }
    return result;
}
Matrix Pow(Matrix a, int p){
    Matrix base = {.val = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
    for(int i = 1; i <= p; i++){
        base = (a * base).val;
    }
    return base;
}
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        Matrix a = Pow(stat, n);
        //Matrix a = stat*stat;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++)
                printf("%d ", a.val[i][j]);
            printf("\n");
        }

        a = a * start;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++)
                printf("%d ", a.val[i][j]);
            printf("\n");
        }
    }
    scanf("%d", &n);
    return 0;
}
