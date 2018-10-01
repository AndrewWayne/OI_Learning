#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100100;
int n,len,a[maxn],a_copy[maxn],l,r,mid,x;

bool check(int x){
/*  核心思想：
        维护一个前缀和sum[i]的值 表示区间[1,i]排完序后有序数列中 中位数.pos-x.pos（当这个值大于零表示中位数在x的右边，更大，小于零则表示该区间中的中位数比x小）我们要找到一个区间[l,r]（值为sum[r]-sum[l-1]）使区间的中位数比x大才能缩小下界，继续二分，所以想到维护一个前缀和的最小值，即使得sum[l-1]最小，则能够使sum[r]-sum[l-1]更大，当这个值大于零表示可以有区间的中位数比x大。可以手动模拟一下，减去前面 的sum[l-1]即表示l之前的数字都不选，那么就可以减少很多比x小的数字对x的影响，使x的位置更靠左。
*/
	int sum[maxn];
    int val = 987654321;
	for(int i = 1; i <= n; i ++)
		sum[i] = ( a[i] >= x ) ? 1 : -1;     //将状态改为比x大和比x小
	for(int i = 1; i <= n; i++){
        sum[i] += sum[i - 1];       //选中区间[1,i]中x的大小位置与中位数的位置的距离。就是在选中的数字中排好序生成的有序序列里面x距离最中间的位置的距离。
		if (i >= len){
            val = min( val, sum[i - len]);  //维护前缀和最小值，即
		    if (sum[i] - val > 0)
                return 1;  //有比他大的中位数则继续二分
        }
	}
	return 0;//否则就算一样也缩小上界
}

int main(){
    scanf("%d%d", &n, &len);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        a_copy[i] = a[i];
    }
    sort( a_copy+1 , a_copy+1+n );
    l = 1, r = n ;
    while( l + 5 <= r ){
        mid = ( l + r ) >> 1;
        x = a_copy[mid];
        if( check(x) ){
            l = mid ;
        }else{
            r = mid ;
        }
    }
    int i;
    for( i = r ; i >= l ; i--)
        if( check(a_copy[i]) )
            break;
    printf("%d",a_copy[i]);
    return 0;
}
