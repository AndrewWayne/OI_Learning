#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;
char A[maxn], B[maxm];
int nxt[maxn], f[maxm], pos[maxn], top, len1, len2, cnt;// nxt[i] A中以i结尾的，非前缀子串与前缀子串匹配的最大长度len即A[1] ~ A[len] == A[i - len + 1] ~ A[i]，f[i]为B中以i结尾的与A的前缀匹配的最大长度
int main(){
    cin >> (B + 1) >> (A + 1);//在B中匹配A
    len1 = strlen(A), len2 = strlen(B);
    nxt[1] = 0;
    for(int i = 2, j = 0;i <= len1; i++){
        while(j > 0 && A[i] != A[j+1]) j = nxt[j];//易证在nxt[j] ～ j之间没有可行解
        if(A[i] == A[j+1]) j++;
        nxt[i] = j;
    }

    for(int  i = 1, j = 0; i <= len2; i++){
        while(j > 0 && (j == len1 || B[i] != A[j+1])) j = nxt[j];
        if(B[i] == A[j+1]) j++;
        f[i] = j;
        if(f[i] == len1)
            cnt++,
            pos[++top] = i;
    }
    cerr << "finish";
    for(int i = 1; i <= top; i++)
        cout << pos[i] << endl;
    for(int i = 1; i <= len1; i++)
        cout << nxt[i] << " ";

    return 0;
}
