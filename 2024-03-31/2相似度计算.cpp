#include<bits/stdc++.h>
using namespace std;

typedef set<string> vs;

vs trans_to_upper(const vs& strs) {
    vs res;
    for (const auto& s : strs) { 
        string upper_s = s;
        transform(upper_s.begin(), upper_s.end(), upper_s.begin(),
            [](unsigned char c) { return toupper(c); });
        res.insert(upper_s); 
    }
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    vs first;
    vs second;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        first.insert(temp);;
    }
    for(int j=0;j<m;j++){
        string temp;
        cin>>temp;
        second.insert(temp);;
    }
    vs first_upper = trans_to_upper(first);
    vs second_upper = trans_to_upper(second);
    int len1=first_upper.size();
    int len2=second_upper.size();

    vs all=first_upper;
    for (const auto& s : second_upper) {
            all.insert(s);
    }
    

    int sum=all.size();

    int cha=(len1+len2-sum);
    cout<<cha<<endl;
    cout<<sum;

}