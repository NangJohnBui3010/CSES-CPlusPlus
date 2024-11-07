#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<ll,int,int> pos;
const ll INF = 1000000000000001;
int n,m;
vector<vector<pll>> G;
vector<vector<ll>> dist;
vector<bool> vis;
ll res = INF;

void solve(){
    priority_queue<pos, vector<pos>, greater<pos>> pq;
    pq.push({0,1,0});
    dist[0][1] = dist[1][1] = 0;
    while(!pq.empty()){
        ll d = get<0>(pq.top());
        int u = get<1>(pq.top());
        int coupon = get<2>(pq.top());
        pq.pop();
        if(dist[coupon][u] < d)continue;
        for(auto x : G[u]){
            int v = x.first;
            ll w = x.second;
            if(!coupon){
                if(dist[0][v] > d + w){
                    dist[0][v] = d + w;
                    pq.push({d+w,v,0});
                }
                if(dist[1][v] > d + w/2){
                    dist[1][v] = d + w/2;
                    pq.push({d+w/2,v,1});
                }
            }else{
                if(dist[1][v] > d + w){
                    dist[1][v] = d+w;
                    pq.push({d+w,v,1});
                }
            }
        }
    }
    cout << min(dist[0][n],dist[1][n]);
}

int main(){
    cin >> n >> m;
    G.resize(n+1);
    dist.resize(2,vector<ll>(n+1,INF));
    while(m--){
        ll a,b,w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
    }
    solve();
    return 0;
}