#include <bits/stdc++.h>
const int maxN = 1e6+1;
typedef long long ll;
using namespace std;
ll dp[maxN],n;
ll modulo = 1e9+7;
int main()
{
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        int val = 1;
        while(val <= i && val <= 6)
        {
            dp[i] = (dp[i] + dp[i-val])%(modulo);
            val++;
        }
    }
    cout << dp[n];
    return 0;
}
