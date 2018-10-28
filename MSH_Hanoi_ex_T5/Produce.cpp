#include <cstdio>
#include <iostream>
using namespace std;
char name[100];
int n,m;
int main(){
    srand(time(0));
    for(int i = 6; i <= 10; i++){
        sprintf(name,"hanoi%d.in",i);
        freopen(name,"w",stdout);
        n = 15+rand()%3;
        m = n - rand()%2;
        cout<<n<<" "<<m;
    }
    return 0;
}
