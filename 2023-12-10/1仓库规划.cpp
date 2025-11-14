#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vii;
typedef vector<int> vi;

/*
没有很好的思路，只能暴力解决。
*/

int main(){
    int n,m;
    cin>>n>>m;
    vii warehouse(n+1,vi(m));
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cin>>warehouse[i][j];
        }
    }
    vi ans(n+1,1e9);
    bool is_continue;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                is_continue=true;
                for(int k=0;k<m;k++){
                    if(warehouse[i][k]>=warehouse[j][k]){
                        is_continue=false;
                        break;
                    }
                }
                if(!is_continue){
                    continue;;
                }
                if(ans[i]>j){
                    ans[i]=j;
                    break;
                }
            }
        }
        if(ans[i]==1e9){
            ans[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}