#include <cstdio>
#include <iostream>
using namespace std;
char name[100];
unsigned int t,n,c;
int main(){
    srand(time(0));
    for(int i = 1; i <= 10; i++){
        sprintf(name,"matrix%d.in",i);
        freopen(name,"w",stdout);
        t = 1;
        printf("%d\n",t);
        for(int k = 1; k <= t; k++){
            n = 23;
            printf("%d\n",n);
            for(int i = 1; i <= n; i++){
                for(int i = 1; i <= n; i++){
                    c = (rand()%2);
                    printf("%d",c);
                }
                printf("\n");
            }
            printf("\n");
        }

    }
}
