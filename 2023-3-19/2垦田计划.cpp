#include <bits/stdc++.h>
using namespace std;


/*

本质是求解最小值中最大值/最大值中最小值：
最优的策略是二分查找
与其一步步模拟，不如直接用二分进行查找：我能否在X天内完成？

对最终的时间进行二分：
下限是k，上限是所有田中最长的。
*************************************
核心：假设所有田都在mid时间内完成，会需要多少资源？
*************************************
进而不断压缩边界，得到答案。

*/

typedef long long ll;

bool check(ll tian,int n,int m,vector<pair<int, int>>& tasks){
    ll resource=0;
    for(auto x:tasks){
        if(x.first>tian){
            resource+=(ll)(x.first-tian)*x.second;
        }
        if(resource>m){
            return false;
        }
    }
    return true;
}
int main(){
    ll n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> tasks(n);
    int max_t = 0; 
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
        if (tasks[i].first > max_t) {
            max_t = tasks[i].first;
        }
    }

    ll left=k;
    ll right=max_t;

    ll ans=max_t;

    while(left<=right){
        ll mid=(left+right)/2;
        if(check(mid,n,m,tasks)){
            ans=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<ans;

}


/*
常规模拟：会有数据点超时！
typedef pair<int, int> pii;

bool compare(pii a, pii b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pii, vector<pii>, function<bool(pii, pii)>> t(compare); // 优先队列默认是最大堆

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ans = max(ans, a);
        t.push({a, b});
    }

    while (!t.empty() && m > 0)
    {
        if (t.top().first <= k)
        {
            ans = k;
            break;
        }
        else if (t.top().second > m)
        {
            ans=t.top().first;
            break;
        }
        else
        {
            m -= t.top().second;
            pii temp = t.top();
            t.pop();
            temp.first--;
            t.push(temp);
        }
        ans = t.top().first;
    }
    cout << ans;
}
*/
