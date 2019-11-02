#include <cstring>
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
int n, x, mp[10][10], history[10][10][10];//mp[x][y] x为列标 y为行标
pair<int, pair<int,int> > sol[10];
bool tag[5][7];
bool remove(){
	memset(tag, 0, sizeof(tag));
	bool flg = false;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 7; j++){
			if(i > 0 && i < 4 && mp[i-1][j] == mp[i][j] && mp[i][j] == mp[i+1][j] && mp[i][j]){
				tag[i-1][j] = tag[i][j] = tag[i+1][j] = 1;
				flg = true;
			}
			if(j > 0 && j < 6 && mp[i][j-1] == mp[i][j] && mp[i][j] == mp[i][j+1] && mp[i][j]){
				tag[i][j-1] = tag[i][j] = tag[i][j+1] = 1;
				flg = true;
			}
		}
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 7; j++){
			if(tag[i][j]) mp[i][j] = 0;
		}
	}
	return flg;
}
void update(){
	for(int i = 0; i < 5; i++){
		int low = 0;
		for(int j = 0; j < 7; j++){
			if(mp[i][j] == 0) low++;
			else{
				if(!low) continue;
				mp[i][j - low] = mp[i][j];;
				mp[i][j] = 0;
			}
		}
	}
}
void move(int x, int y, int d){
	swap(mp[x+d][y], mp[x][y]);
	update();
	while(remove()) update();
}
bool check(){
	bool flg = 1;
	for(int i = 0; i < 5; i++){
		if(mp[i][0] != 0) return false;
	}
	return true;
}
void dfs(int id){
	if(check()){
		for(int i = 1; i <= id; i++){
			//cerr << "YES" << endl;
			printf("%d %d %d\n", sol[i].first, sol[i].second.first, sol[i].second.second);
		}
		exit(0);
	}
	if(id == n) return;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 7; j++)
			history[id][i][j] = mp[i][j];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 7; j++){
			if(mp[i][j] != 0){
				if(i < 4 && mp[i][j] != mp[i+1][j]){
					move(i, j, 1);
					sol[id+1].first = i, sol[id+1].second.first = j, sol[id+1].second.second = 1;
					dfs(id + 1);
					for(int i = 0; i < 5; i++){
						for(int j = 0; j < 7; j++)
							mp[i][j] = history[id][i][j];
					}
					sol[id+1].first = -1, sol[id+1].second.first = -1, sol[id+1].second.second = -1;
				}

				if(i >= 1 && mp[i-1][j] == 0){
					move(i, j, -1);
					sol[id+1].first = i, sol[id+1].second.first = j, sol[id+1].second.second = -1;
					dfs(id + 1);
					for(int i = 0; i < 5; i++)
						for(int j = 0; j < 7; j++)
							mp[i][j] = history[id][i][j];

					sol[id+1].first = -1, sol[id+1].second.first = -1, sol[id+1].second.second = -1;
				}

			}
		}
	}
}
double Time(){return (double)clock()/CLOCKS_PER_SEC;}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < 5; i++){
		int j = 0;
		do{
			scanf("%d", &x);
			mp[i][j] = x;
			j++;
		}while(x != 0);
	}
	dfs(0);
	printf("-1\n");
	printf("%f\n", Time());
	return 0;
}
