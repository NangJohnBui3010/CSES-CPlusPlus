#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 10000000000000;
int n,m,q;


vector<vector<ll>> G;
vector<vector<ll>> d;


void floyd_warshall_preprocess(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) d[i][j] = 0;
            else if(G[i][j])
                d[i][j] = G[i][j];
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[j][k]);
}

int main(){
    cin >> n >> m>>q;
    G.resize(n+1, vector<ll>(n+1,0));
    d.resize(n+1,vector<ll>(n+1, INF));
    while(m--){
        ll a,b,w;
        cin >> a >> b >> w;
        if(G[a][b] == 0){
            G[a][b] = w;
        }else
            G[a][b] = min(G[a][b],w);
        G[b][a] = G[a][b];
    }
    floyd_warshall_preprocess();
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << ((d[a][b] == INF)?-1:d[a][b]) <<endl;
    }
    return 0;
}