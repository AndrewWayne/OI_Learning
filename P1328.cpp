#include <cstdio>
#include <iostream>
using namespace std;
int n,na,nb,sa,sb;
int judge[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int a[220],b[220];
int main(){
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++)
        cin>>a[i];
    for(int i=0;i<nb;i++)
        cin>>b[i];
    for(int i=0;i<n;i++){
        sa+=judge[a[i%na]][b[i%nb]];
        sb+=judge[b[i%nb]][a[i%na]];
    }
    cout<<sa<<" "<<sb;
    return 0;
}
