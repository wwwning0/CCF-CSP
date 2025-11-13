#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,double> pif;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<pif> opera(n);
    for(int i=0;i<n;i++){
        cin>>opera[i].first>>opera[i].second;
    }
    for(int i=0;i<m;i++){
        double a,b,x,y;
        cin>>a>>b>>x>>y;
        for(int j=a-1;j<b;j++){
            if(opera[j].first==1){
                x*=opera[j].second;
                y*=opera[j].second;
            }
            else {
                double theta=opera[j].second;
                double temp=x;
                x=x*cos(theta)-y*sin(theta);
                y=temp*sin(theta)+y*cos(theta);
            }
        }
        cout << fixed << setprecision(6) << x << ' ' << y << endl;
    }

}
