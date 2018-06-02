#include <stdio.h>
int main(){
	int i,j;
	int n,average=0;
	int d;
	int t=0;
	scanf("%d",&n);
	int cards[n];
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&cards[i]);
		average+=cards[i];
	}
	average/=n;
	for (i = 0; i < n; ++i)cards[i]-=average;
	for(i=0;i<=n-1;++i){
		if(cards[i]==0)continue;
		cards[i+1]+=cards[i];
		t++;
	}
	printf("%d",t);
	return 0;
}