#include <bits/stdc++.h>

using namespace std;
int n,a[200001];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    int ans = 1;
    for(int i = 0; i < n && a[i] < ans; i++)
        if(a[i] <= ans)ans+=a[i];
    cout << a[i];
    return 0;
}
