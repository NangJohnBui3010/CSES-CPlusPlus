#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

int n,m, components;
vector<vector<int>> G;
vector<int> parent, set_size;
multiset<int, greater<int>> mp;

int find_set(int a){
    if(parent[a] == -1 || a == parent[a]){
        return a;
    }
    return parent[a] = find_set(parent[a]);
}

void join_set(int a, int b, int &components, multiset<int, greater<int>> &mp){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(set_size[a] < set_size[b])
            swap(a,b);
        set_size[a] += set_size[b];
        parent[b] = a;
        mp.insert(set_size[a]);
        components--;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    G.resize(n+1);
    set_size.resize(n+1,1);
    parent.resize(n+1,-1);
    components = n;
    mp.insert(1);
    while(m--){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        join_set(a,b,components,mp);
        cout << components << " "<< *mp.begin() << endl;
    }
    return 0;
}