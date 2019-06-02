#include<iostream>
#include<algorithm>
using namespace std;
const int N=302,M=100002;
struct group{
    int num,id;
};
bool operator<(group a,group b){
    return a.num>b.num;
}
group list[N];
int n;
char pr[N][M];
int termid,termcnt;
int sum;
int cnt;
int ans[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>list[i].num;
        list[i].id=i;
        sum+=list[i].num;
    }
    sort(list+1,list+n+1);
    pr[0][0]=1;
    //初始状态，可以看出不会导致后面跳的时候出问题
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(pr[i-1][j]){
                pr[i][j]=1;
            }else{
                pr[i][j]=0;
            }
        }
        for(int j=0;j<=sum-list[i].num;j++){
            if(pr[i-1][j]){
                pr[i][list[i].num+j]=2;
                if(j<=sum/2&&list[i].num+j>sum/2){
                    if(termcnt<list[i].num+j){
                        termid=i;
                        termcnt=list[i].num+j;
                    }
                }
            }
        }
    }
    for(int i=termid,j=termcnt;i>0;i--){
        if(pr[i][j]==2){
            ans[cnt++]=list[i].id;
            j-=list[i].num;
        }
        //否则表示没选
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
