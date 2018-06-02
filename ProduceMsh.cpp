#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

char q[10];
int k,h,t,x,ans,r[10][10];
bool bo[10];
int a,b;
char n[2001];
void push(int ss)
{
	if(bo[ss])return;
	bo[ss]=1;
    t++;
    q[t]=ss;
}
void bfs(int s)
{
    h=t=0;
    memset(bo,0,sizeof(bo));
    push(s);
    do
    {
    	h++;
    	x=q[h];
    	for(int i=1;i<=9;i++)
    		if(r[x][i])push(i);
    }
    while(h<=t);
    ans*=t;
}
int main(){
	ans=1;
	scanf("%s\n",n);
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d",&a,&b),r[a][b]=1;
	for(int i=0;i<=strlen(n)-1;i++){
		bfs(n[i]-'0');
	}
	printf("%d",ans);
	system("pause");
	return 0;
}
