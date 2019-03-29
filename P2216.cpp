#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 1e3 + 10;
int N, M, L, A[MAXN][MAXN];
deque<pair<int,int> > Aque1[MAXN], Aque2[MAXN], Bque1, Bque2;
int ANS = 0x7fffffff;
int main(){
    cin >> N >> M >> L;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> A[i][j];
    int val = 0;
    //cerr << "A" << endl;
    for(int i = 1; i <= M; i++){
        Bque1.clear();
        Bque2.clear();
        for(int j = 1; j <= N; j++){
            while(!Aque1[j].empty() && Aque1[j].front().first <= i - L)
                Aque1[j].pop_front();
            while(!Aque2[j].empty() && Aque2[j].front().first <= i - L)
                Aque2[j].pop_front();
            while(!Bque1.empty() && Bque1.front().first <= j - L)
                Bque1.pop_front();
            while(!Bque2.empty() && Bque2.front().first <= j - L)
                Bque2.pop_front();
            //cerr << "A" << endl;
            while(!Aque1[j].empty() && Aque1[j].back().second > A[j][i])
                Aque1[j].pop_back();
            Aque1[j].push_back(make_pair(i, A[j][i]));
            while(!Aque2[j].empty() && Aque2[j].back().second < A[j][i])
                Aque2[j].pop_back();
            Aque2[j].push_back(make_pair(i, A[j][i]));
            while(!Bque1.empty() && Bque1.back().second > Aque1[j].front().second)
                Bque1.pop_back();
            Bque1.push_back(make_pair(j, Aque1[j].front().second));
            while(!Bque2.empty() && Bque2.back().second < Aque2[j].front().second)
                Bque2.pop_back();
            Bque2.push_back(make_pair(j, Aque2[j].front().second));
/*
            if(Bque2.front().second - Bque1.front().second == 999){
                cerr << "$: " << Bque1.front().second << endl;
                cerr << "$: " << Bque2.front().second << endl;
                cerr << j << ":" << i << " -- " << Bque2.front().second - Bque1.front().second << endl;
            }
//*/
            if(i >= L && j >= L)
                ANS = min(ANS, Bque2.front().second - Bque1.front().second);
        }
    }
    cout << ANS << endl;
    return 0;
}
