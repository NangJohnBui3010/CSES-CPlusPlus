#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
int n,m;
struct edge{
    int u,v;
    long long cost;
};

vector<int> parent;
vector<int> set_size;

auto cmp = [](edge a, edge b){return a.cost > b.cost;};
priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);

int find_set(int a){
    if(parent[a] == -1 || a == parent[a])
        return a;
    return parent[a] = find_set(parent[a]);
}

void join(int a, int b, int cost, int &edgeAdded, long long &totalCost){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(set_size[a] < set_size[b])
            swap(a,b);
        set_size[a] += set_size[b];
        parent[b] = a;
        edgeAdded++;
        totalCost += cost;
    }
}


void kruskal(){
    // Loop til number of edges added = n-1;
    int edgeAdded = 0;
    long long totalCost = 0;
    while(!pq.empty() && edgeAdded < n-1){
        edge curr_edge = pq.top();
        pq.pop();
        join(curr_edge.u, curr_edge.v, curr_edge.cost, edgeAdded, totalCost);
    }
    if(edgeAdded < n-1)
        cout << "IMPOSSIBLE";
    else cout << totalCost;
}

int main(){
    cin >> n >> m;
    parent.resize(n+1,-1);
    set_size.resize(n+1,1);
    while(m--){
        int a,b,w;
        cin >> a >> b >> w;
        pq.push({a,b,w});
    }
    kruskal();
    return 0;
}