#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        auto it = upper_bound(a.begin(),a.end(),x);
        if(it != a.end())*it = x;
        else
        {
            a.push_back(x);
        }
    }
    cout << a.size();
    return 0;
}
