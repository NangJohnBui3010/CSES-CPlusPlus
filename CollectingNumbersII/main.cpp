#include <bits/stdc++.h>

using namespace std;
int Pos[200005],n;
int main()
{
    cin >> n >> m;
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
    for(int i = 1; i <= m; i++)
    {
        int x,y;
        cin >> x >> y;
        if(Pos[y] < Pos[x-1])ans++;
        if(Pos[y] )
    }
    return 0;
}
