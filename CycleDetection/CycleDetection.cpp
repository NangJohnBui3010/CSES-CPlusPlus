#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
vector<vector<pll>> G;
vector<bool> vis;
vector<int> path;
bool found;
int n,m;

void DFS(int node, vector<int> &path, ll sum, bool &found, int parent){
    if(vis[node]){
        if(sum < 0){
            found = true;
            path.push_back(node);
        }
        return;
    }
    vis[node] = 1;
    path.push_back(node);
    for(auto x:G[node]){
        if(found)return;
        int adj = x.first;
        int w = x.second;
        if(adj != parent)
            DFS(adj,path,sum+w,found,node);
    }
    if(found)return;
    path.pop_back();
}

int main(){
    cin >> n >> m;
    G.resize(n+1); vis.resize(n+1,0);
    while(m--){
        ll a,b,w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }

    for(int i = 1; i <= n; i++){
        path.clear();
        if(!found && !vis[i]){
            DFS(i,path,0,found,-1);
        }
    }
    //cout << "Answer: " << endl;
    if(path.size() >= 4)cout <<"YES\n"; else {
        cout <<"NO" << endl;
        return 0;
    }
    for(int i = path.size()-1; i >= 0; i--)
        cout << path[i] << " ";
    return 0;
}