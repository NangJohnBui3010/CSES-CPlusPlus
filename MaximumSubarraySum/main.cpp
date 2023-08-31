#include <bits/stdc++.h>

using namespace std;
int n, a[200001];
long long Sum[200001];
int main()
{
    cin >> n;
    cin >> a[0]; Sum[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        cin >> a[i];
        Sum[i] = Sum[i-1] + a[i];
    }
    long long Min = 0, ans = a[0];
    for(int i = 1; i < n; i++)
    {
        long long val = Sum[i] - Sum[Min];
        val = max(val, Sum[i]);
        ans = max(ans,val);
        if(Sum[i] < Sum[Min])Min = i;
    }
    cout << ans;
    return 0;
}
