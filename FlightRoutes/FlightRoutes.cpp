#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m;
vector<vector<pll>> G;

void solve(){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    G.resize(n+1);
    while(m--){
        ll a,b,w;
        G[a].push_back({b,w});
    }

    solve();
    return 0;
}