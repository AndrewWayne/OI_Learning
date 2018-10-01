#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Task{
    int id,begin,need,val;
}tasks[330000];
bool operator < (Task u,Task v){
    if(u.val == v.val)
        return u.id >= v.id;
    return u.val < v.val;
}
priority_queue<Task> CPU;
int n,now=1,timeline=0;
int main(){
    while(scanf("%d%d%d%d",&tasks[n+1].id,&tasks[n+1].begin,&tasks[n+1].need,&tasks[n+1].val)!=EOF)
        n++;
    while(n != 0){
        if(CPU.empty())
            CPU.push(tasks[now]),timeline = tasks[now++].begin;
        Task tmp = CPU.top();
        CPU.pop();
        int past = timeline;
        timeline =  min( tasks[now].begin , past+tmp.need );
        if(timeline ==  past+tmp.need){
            printf("%d %d\n",tmp.id,timeline);
            n--;
        }else{
            tmp.need -= timeline - past;
            CPU.push(tmp);
        }
        if( timeline == tasks[now].begin )
            CPU.push(tasks[now++]);
        /*
        if( timeline+tmp.need > tasks[now].begin ){
            tmp.need -= tasks[now].begin - timeline;
            timeline = tasks[now].begin;
            CPU.push(tmp);
            CPU.push(tasks[now++]);
        }else{
            timeline += tmp.need;
            printf("%d %d\n",tmp.id,timeline);
            n--;
        }
        */
    }
    return 0;
}
