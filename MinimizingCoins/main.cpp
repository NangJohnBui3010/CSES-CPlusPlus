#include <bits/stdc++.h>

using namespace std;
int dp[1000001], coins[101],n,x;
int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++)cin >> coins[i];
    sort(coins,coins+n);
    for(int i = 1; i <= x; i++)dp[i] = -1;
    dp[0] = 0;
    for(int i = coins[0]; i <= x; i++)
    {
        if(dp[i-coins[0]]!=-1)dp[i] = 1 + dp[i-coins[0]];
        for(int j = 1; j < n && i>=coins[j]; j++)
            if(dp[i-coins[j]] != -1)
            {
                if(dp[i] == -1)dp[i]=1+dp[i-coins[j]];
                else dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }

    }
    cout << dp[x];
    return 0;
}
