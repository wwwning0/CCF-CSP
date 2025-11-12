#include<bits/stdc++.h>
using namespace std;


/*
首先第一个雷点是数据类型，所有矩阵相关的都应是long long。
第二个雷点是矩阵计算的优化：矩阵乘法结合律。（虽然最终的计算结果完全相同，但不同的计算顺序会导致中间过程的计算量和内存占用产生天壤之别。）
        避免产生巨大的中间矩阵，效率会极大优化。
*/
typedef long long ll;
typedef vector<ll> vi;
vector<vi> matricx_T(const vector<vi>& K){
    vector<vi> new_(K[0].size(),vi(K.size()));
    for(int i=0;i<K.size();i++){
        for(int j=0;j<K[0].size();j++){
            new_[j][i]=K[i][j];
        }
    }
    return new_;
}
vector<vi> matricx_mul(const vector<vi>& Q,const vector<vi>& V){
    vector<vi> new_(Q.size(),vi(V[0].size()));
    for(int i=0;i<Q.size();i++){
        for(int j=0;j<V[0].size();j++){
            for(int k=0;k<Q[i].size();k++){
                new_[i][j]+=Q[i][k]*V[k][j];
            }
        }
    }
    return new_;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n,d;
    cin>>n>>d;
    vector<vi> V(n,vi(d)),Q(n,vi(d)),K(n,vi(d));
    vi W(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>Q[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>K[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>V[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cin>>W[i];
    }
    vector<vi> K_T=matricx_T(K);

    vector<vi> temp=matricx_mul(K_T,V);

    vector<vi> ans(n,vi(d));
    for(int i=0;i<Q.size();i++){
        for(int j=0;j<V[0].size();j++){
            for(int k=0;k<Q[i].size();k++){
                ans[i][j]+=Q[i][k]*temp[k][j]*W[i];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }

}