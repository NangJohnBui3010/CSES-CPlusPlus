#include <bits/stdc++.h>
const int maxN = 2e5+1;
using namespace std;
int n,m,k,a[maxN],b[maxN];
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("APT.INP","r",stdin);
    freopen("APT.OUT","w",stdout);*/
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a,a+n); sort(b,b+m);
    int j = 0, ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(j >= n)break;
        int val = abs(a[i]-b[j]);
        while(j < n && val > k && a[i] > b[j])
        {
            j++;
            val = abs(a[i]-b[j]);
        }
        if(val <= k)
        {
            ans++;
            j++;
        }
    }
    cout << ans;
    return 0;
}
