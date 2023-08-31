#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x, modulo = 1e9+7;
    cin >> n >> x;
    vector<int> coin(n+1);
    for(int i = 1; i <= n; i++)
        cin >> coin[i];
    vector<vector<int>> dp(n+1, vector<int> (x+1,0));
    for(int i = 0; i <= n; i++)dp[i][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(coin[i] <= j)
                (dp[i][j] += dp[i][j-coin[i]]) %= modulo;
        }
    }
    cout << dp[n][x];
    return 0;
}
