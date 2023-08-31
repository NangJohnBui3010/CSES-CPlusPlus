#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PLAYLIST.INP","r",stdin);
    freopen("PLAYLIST.OUT","w",stdout);*/
    int n,Max = 0;
    cin >> n;
    map<int,int> Map;
    int a[n+1];
    for(int i = 1; i <= n; i++)cin >> a[i];
    int l = 1, r = 1;
    while(r <= n)
    {
        if(Map.find(a[r]) == Map.end() || Map[a[r]] == 0)
        {
            Max = max(Max,r-l+1);
            Map[a[r]]++;
            r++;
        }else
        {
            Map[a[l]]--;
            l++;
        }
    }
    cout << Max;
    return 0;
}
