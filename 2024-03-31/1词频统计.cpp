#include<bits/stdc++.h>
using namespace std;

/*
被这个题迷了眼了……
*/

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int> cnt1(m+1);
    vector<int> cnt2(m+1);
    vector<bool> is_first(m+1,true);

    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        fill(is_first.begin(),is_first.end(),true);
        for(int j=0;j<l;j++){
            int temp;
            cin>>temp;
            if(is_first[temp]==true){
                cnt1[temp]++;
                is_first[temp]=false;
            }
            cnt2[temp]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt1[i]<<' '<<cnt2[i]<<endl;
    }
}