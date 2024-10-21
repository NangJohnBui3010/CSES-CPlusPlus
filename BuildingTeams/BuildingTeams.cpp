#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> G(100001);
vector<int> teams(100001);
int n,m;
bool status = false;


void BFS(int x){
    queue<int> Q;
    Q.push(x);
    teams[x] = 1;
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        for(auto x:G[v]){
            if(teams[x] == teams[v]){
                status = true;
                return;
            }else if(teams[x] == 0){
                Q.push(x);
                teams[x] = -teams[v];
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(teams[i] == 0)
            BFS(i);
        if(status == true) break;
    }

    if(status)cout << "IMPOSSIBLE";
    else{
        for(int i = 1; i <= n; i++){
            if(teams[i] == -1)cout << 1; 
            else cout << 2; cout << " ";
        }
    }
}