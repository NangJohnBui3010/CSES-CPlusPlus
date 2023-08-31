#include <bits/stdc++.h>
const int maxN = 2e5+1;

using namespace std;
int n;
pair<int,int> a[maxN];
bool compare(pair<int,int> a, pair<int,int> b)
{
    return(a.second < b.second || (a.second == b.second && a.first < b.first));
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a,a+n,compare);
    int t = 0, ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i].first >= t)
        {
            t = a[i].second;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
