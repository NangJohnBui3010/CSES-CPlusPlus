#include <bits/stdc++.h>

using namespace std;
int Pos[200005],n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        Pos[x] = i;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++)
    {
        if(Pos[i] < Pos[i-1])ans++;
    }
    cout << ans;
    return 0;
}
