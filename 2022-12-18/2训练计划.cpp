#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    //记录依赖关系与耗费时间
    vector<int> time(m+1);
    vector<int> depend(m+1);
    for(int i=1;i<=m;i++){
        cin>>depend[i];
    }
    for(int i=1;i<=m;i++){
        cin>>time[i];
    }

    vector<int> early_begin(m+1);
    vector<int> early_end(m+1);

    for(int i=1;i<=m;i++){
        if(depend[i]==0){
            early_begin[i]=1;
        }
        else{
            early_begin[i]=early_end[depend[i]]+1;
        }
        early_end[i]=early_begin[i]+time[i]-1;
    }
    for(int i=1;i<=m;i++){
        cout<<early_begin[i]<<' ';
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        if(early_end[i]>n){
            return 0;
        }
    }

    //计算最晚开始时间
    //最晚开始时间取决于有没有依赖我

    vector<int> laster_begin(m+1);
    vector<int> laster_end(m+1);
    vector<vector<int>> depend_me(m+1);
    for(int i=1;i<=m;i++){
        if(depend[i]!=0){
            depend_me[depend[i]].push_back(i);
        }
    }
    for(int i=m;i>0;i--){
        if(depend_me[i].empty())
            laster_end[i]=n;
        else{
            laster_end[i]=1e9;
            for(int j=0;j<depend_me[i].size();j++){
                laster_end[i]=min(laster_end[i],laster_begin[depend_me[i][j]]-1);
            }
        }
        laster_begin[i]=laster_end[i]-time[i]+1;
    }

    for(int i=1;i<=m;i++){
        cout<<laster_begin[i]<<' ';
    }

}