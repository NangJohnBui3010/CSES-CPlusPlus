#include <iostream> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
#include <climits> 
#include <stack> 
#include <queue> 
#include <vector> 
#include <set> 
#include <map> 
#include <list> 
#include <cassert> 
#include <unordered_map> 
#include <sstream> 

#define long long ll;
using namespace std;  
int n,m;
vector<vector<int>> G;
vector<int> parent;
vector<int> set_size;

void make_set(int v){
    parent[v] = v;
    set_size[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    else 
        return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(set_size[a] < set_size[b])
            swap(a,b);
        parent[b] = a;
        set_size[a] + set_size[b];
    }
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    G.resize(n+1); 
    parent.resize(n+1);
    set_size.resize(n+1);
    for(int i = 1; i <= n; i++)
        make_set(i);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        union_sets(a,b);
    }

    vector<int> roads;
    for(int i = 1; i <= n; i++){
        if(find_set(i) == i)
            roads.push_back(i);
    }

    //cout << "answer: " << endl;
    //for(auto x : parent)
    //    cout << x << " ";
    cout << roads.size() - 1 << endl;
    for(int i = 0; i < roads.size()-1; i++)
        cout << roads[i] << " " << roads[i+1] << endl;
    return 0;
} 

	 