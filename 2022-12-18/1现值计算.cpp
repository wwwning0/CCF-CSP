#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    float price;
    cin>>n;
    float li_lv;
    cin>>li_lv;
    float ans=0;
    for(int i=0;i<=n;i++){
        int temp;
        cin>>temp;
        float trans=0;
        trans=temp*pow(1+li_lv,-i);
        ans+=trans;
    }
    cout<<ans;
}