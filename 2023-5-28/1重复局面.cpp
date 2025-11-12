#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str="";
    map<string,int> nums;
    for(int i=0;i<8*n;i++){
        if(i%8==0&&i!=0){
            if(nums.count(str)!=1)
                nums[str]=1;
            else 
                nums[str]++;
            cout<<nums[str]<<endl;
            str="";
        }
        string temp;
        cin>>temp;
        str+=temp;
    }
    if(nums.count(str)!=1)
        nums[str]=1;
    else 
        nums[str]++;
    cout<<nums[str]<<endl;
}