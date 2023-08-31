#include <bits/stdc++.h>

using namespace std;
int n;
bool compare(pair<int,int> a, pair<int,int> b)
{
    return(a.first < b.first || (a.first == b.first && a.second < b.second));
}
int main()
{
    vector<pair<int,int>> line;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        line.push_back({x,1});
        cin >> x;
        line.push_back({x,-1});
    }
    sort(line.begin(),line.end(),compare);
    int ans = 0, c = 0;
    for(int i = 0; i < line.size(); i++)
    {
        c+= line[i].second;
        ans = max(ans,c);
    }
    cout << ans;
    return 0;
}
