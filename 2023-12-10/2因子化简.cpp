#include <bits/stdc++.h>
using namespace std;

/*
学习质因数分解算法：试除法
时间复杂度：根号n
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long q;
    cin >> q;
    while(q--){
        long long n;
        int k;
        cin>>n>>k;
        long long ans=1;
        for (long long i = 2; i <= n / i; i++)
        if (n % i == 0)
        {
            long long s = 0;
            while (n % i == 0)
                n /= i, s++;
            //i是质数，s是该质数的指数
            if(s>=k) ans*=pow(i,s);
        }
        cout<<ans<<endl;
    }
}