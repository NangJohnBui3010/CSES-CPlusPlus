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

using namespace std; 
int n,m;

int main(){
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    vector<bool> visited(n+1,0);
    vector<int> parent(n+1,0);
    vector<int> ans;
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> Q;
    Q.push(1);
    visited[1] = 1;
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        if(v == n){
            while(v != 0){
                ans.push_back(v);
                v = parent[v];
            }
            break;
        }
        for(auto x : G[v]){
            if(!visited[x]){
                Q.push(x);
                visited[x] = 1;
                parent[x] = v;
            }
        }
    }
    
    if(ans.size() == 0){
        cout <<"IMPOSSIBLE";
        return 0;
    }
    cout << ans.size() << endl;
    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0; 
} 

 