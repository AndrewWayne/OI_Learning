#include <cstdio>
#include <string.h>
using namespace std;

int main(){
  int begin1=1;
  int end=1;
  int n_mam,n_woman;
  int n_song;
  scanf("%d %d\n%d",&n_man,&n_woman,&n_song);
  int mans[n_song+1],womans[n_song+1];

  begin=1;
  end1=n_man;end2=n_woman;
  for(int i=1;i<=n_man;i++)
    mans[i]=i;
  for(int i=1;i<=n_woman;i++)
    womans[i]=i;
  for (int i = 1; i <= n_song; i++) {
      printf("%d %d\n",mans[i],womans[i]);
      mans[++end1]=mans[i];
      womans[++end2]=womans[i];
  }
}
