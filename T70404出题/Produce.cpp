#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int n, temp;
char name[100];
int main(){
    srand(time(0));
    for(int iii = 4; iii <= 10; iii++){
        sprintf(name,"Nine%d.in",iii);
        freopen(name, "w", stdout);
        n = 8888888;
        printf("%d\n", n);
        for(int j = 1; j <= 2; j++){
            for(int i = 1; i <= n; i++)
                printf("%d ", rand()%2);
            printf("\n");
        }
    }
    return 0;
}
