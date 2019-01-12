#include <cstdio>
using namespace std;
int n, ans = 1;
int num[4] = {6, 8, 4, 2};
int main() {
    scanf("%d",&n);
    for(int p = n; p > 0; p /= 5, ans = ans * num[p%4] %10)
        for (int i = 1; i <= p%10; i++)
            if(i != 5)
                ans = ans * i %10;
    printf("%d",ans);
    return 0;
}
