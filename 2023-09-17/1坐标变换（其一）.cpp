#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<pii> opera(n);
    for(int i=0;i<n;i++){
        cin>>opera[i].first>>opera[i].second;
    }
    vector<pii> Coordinates(m);
    for(int i=0;i<m;i++){
        cin>>Coordinates[i].first>>Coordinates[i].second;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            Coordinates[i].first+=opera[j].first;
            Coordinates[i].second+=opera[j].second;
        }
    }
    for(int i=0;i<m;i++){
        cout<<Coordinates[i].first<<' '<<Coordinates[i].second<<endl;
    }

}