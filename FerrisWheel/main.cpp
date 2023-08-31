#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5+1;
int n,x,a[maxN];
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FER.INP","r",stdin);
    freopen("FER.OUT","w",stdout);*/
    cin >> n >> x;
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a,a+n);
    int i = 0, j = n-1, ans = 0;
    while(i <= j)
    {
        if(a[i] + a[j] <= x)i++;
        j--;
        ans++;
    }
    cout << ans;
    return 0;
}
