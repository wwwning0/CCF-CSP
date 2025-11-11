#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    int x1,y1,x2,y2;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        if(x2<=0||x1>=a||y1>=b||y2<=0) continue;
        else {
            sum+=abs((max(x1,0))-(min(x2,a)))*abs((min(y2,b)-max(y1,0)));
        }
    }
    cout<<sum;
    

}