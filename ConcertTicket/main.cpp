#include <bits/stdc++.h>
const int maxN = 2e5+1;
using namespace std;
int n,a[maxN],m;
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CON.INP","r",stdin);
    freopen("CON.OUT","w",stdout);*/
    multiset<int> tickets;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x; tickets.insert(x);
    }
    for(int i = 0; i < m; i++)
    {
        int x; cin >> x;
        auto it = tickets.upper_bound(x);
        if(it != tickets.begin())
        {
            cout << *(--it) << endl;
            tickets.erase(it);
        }else cout << -1 << endl;
    }
    return 0;
}
