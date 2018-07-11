#include <bits/stdc++.h>
#define Debug(_a) cout<<"vaule:"<<_a<<endl
using namespace std;
int n,m,x,y,h,t;
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={-2,2,-1,1,2,-2,1,-1};
struct node{
	int x,y,f;
} queu[160010];
int maps[401][401];
void push(int _x,int _y,int _f){
	queu[++t].x=_x;
	queu[t].y=_y;
	queu[t].f=_f;
	maps[_x][_y]=_f;
}
node pop(void){
	return queu[++h];
}
void printmap(void){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%-5d",maps[i][j]);
		printf("\n");
	}
}
int main(){
	cin>>n>>m>>x>>y;
	memset(maps,-1,sizeof(maps));
	push(x,y,0);
//	printmap();
	while(h<t){
		node a=pop();
//		Debug(a.x);
//		Debug(a.y);
//		system("pause");
		for(int i=0;i<8;i++){
			int tx=a.x+dx[i];
			int ty=a.y+dy[i];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
				if(maps[tx][ty]==-1){
					push(tx,ty,a.f+1);
//					Debug(tx);
//					Debug(ty);
//					system("pause");
				}
			}
		}
	}
	printmap();
}
