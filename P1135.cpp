#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=220;
int n,m,a,b,h,t;
bool bo[maxn];
int k[maxn];
struct flor{
	int floor,f;
} queue[maxn];
void push(int node,int step){
	queue[++t].floor=node;
	queue[t].f=step;
	bo[node]=true;
}
flor pop(){
	return queue[++h];
}
int main()
{
	h=t=0;
    scanf("%d%d%d",&n,&a,&b);
    if(a==b){
    	printf("0");
    	return 0;
	}
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    push(a,0);
    while(h<=t)
    {
    	flor current=pop();
    	int step=current.f;
    	int pos=current.floor;
    	int l=pos-k[pos],r=pos+k[pos];
        if(l>=1&&!bo[l])
        	push(l,step+1);
        if(r<=n&&!bo[r])
        	push(r,step+1);
        if(l==b||r==b){
        	printf("%d",step+1);
        	return 0;
		}
    }
    printf("-1");
    return 0;
}

