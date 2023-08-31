#include <bits/stdc++.h>

using namespace std;

int mt[1002][1002],n,m;

void BuildRail(int n, int m)
{
    for(int i = 0; i <= n+1; i++)
    {
        mt[i][0] = -1;
        mt[i][m+1] = -1;
    }
    for(int i = 0; i <= m+1; i++)
    {
        mt[0][i] = -1;
        mt[n+1][i] = -1;
    }
}

void BFS(int i, int j, int cnt)
{
    queue<pair<int,int>> Q;
    Q.push({i,j}); mt[i][j] = cnt;
    while(!Q.empty())
    {
        pair<int,int> tar = Q.front();
        int y = tar.first, x = tar.second;
        if(mt[y+1][x] == 0)
        {
            mt[y+1][x] = cnt;
            Q.push({y+1,x});
        }
        if(mt[y-1][x] == 0)
        {
            mt[y-1][x] = cnt;
            Q.push({y-1,x});
        }
        if(mt[y][x-1] == 0)
        {
            mt[y][x-1] = cnt;
            Q.push({y,x-1});
        }
        if(mt[y][x+1] == 0)
        {
            mt[y][x+1] = cnt;
            Q.push({y,x+1});
        }
        Q.pop();
    }
}

void Solve()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(mt[i][j] == 0)
            {
                cnt++;
                BFS(i,j,cnt);
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COUNT.INP","r",stdin);
    freopen("COUNT.OUT","w",stdout);*/
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            char x; cin >> x;
            if(x == '#')mt[i][j] = -1;
            else mt[i][j] = 0;
        }
    }
    BuildRail(n,m);
    Solve();
    return 0;
}
