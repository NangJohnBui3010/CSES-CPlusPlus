#include <bits/stdc++.h>
const int maxN = 2e5+1;

using namespace std;
int n,x;
int main()
{
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++)
        {cin >> a[i].first; a[i].second = i+1;}
    sort(a.begin(),a.end());
    int i = 0, j = n-1;
    while(i < j)
    {
        int res = a[i].first + a[j].first;
        if(res == x)
        {
            cout << a[i].second << " "<<a[j].second;
            return 0;
        }else if(res < x)i++;
        else j--;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
