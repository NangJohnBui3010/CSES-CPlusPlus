#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COIN.INP","r",stdin);
    freopen("COIN.OUT","w",stdout);*/
    int n,x,modulo = 1e9+7;
    cin >> n >> x;
    vector<int> coins(n);
    for (int&v : coins) cin >> v;
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
            if(i >= coins[j])
                (dp[i]+= dp[i-coins[j]])%=modulo;
    }
    cout << dp[x];
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COIN.INP","r",stdin);
    freopen("COIN.OUT","w",stdout);
  int mod = 1e9+7;
  int n, target;
  cin >> n >> target;
  vector<int> c(n);
  for (int&v : c) cin >> v;

  vector<int> dp(target+1,0);
  dp[0] = 1;
  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < n; j++) {
      if (i-c[j] >= 0) {
	(dp[i] += dp[i-c[j]]) %= mod;
      }
    }
  }
  cout << dp[target] << endl;
}*/
