#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
bool validSquare(pair<int,int> pos){
    return(pos.first > 0 && pos.first <= n && pos.second >0 && pos.second <= m);
}

int dY[4] = {1,0,-1,0};
int dX[4] = {0,1,0,-1};
vector<char> directions = {'D','R','U','L'};

int main(){
    cin >> n >> m;
    bool found = false;
    pair<int,int> start,end;
    vector<vector<char>> arr(n+1, vector<char>(m+1));
    vector<vector<pair<int,int>>> parent(n+1, vector<pair<int,int>>(m+1, {-1,-1}));
    vector<vector<char>> move(n+1, vector<char>(m+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'A')
                start = {i,j};
            else if(arr[i][j] == 'B')
                end = {i,j};
        }
    }
    queue<pair<int,int>> Q;
    Q.push(start);
    parent[start.first][start.second] = {0,0};
    while(!Q.empty()){
        pair<int,int> curr = Q.front(); Q.pop();
        if(curr == end){
            found = true;
            break;
        }
        for(int i = 0; i < 4; i++){
            pair<int,int> adj = curr;
            adj.first += dY[i]; adj.second += dX[i];
            if(validSquare(adj) && arr[adj.first][adj.second] != '#' && parent[adj.first][adj.second] == make_pair(-1,-1)){
                Q.push(adj);
                parent[adj.first][adj.second] = curr;
                move[adj.first][adj.second] = directions[i];
            }
        }
    }
    if(found){
        cout << "YES" << endl;
        vector<char> res;
        pair<int,int> curr = end;
        while(parent[curr.first][curr.second] != make_pair(0,0)){
            res.push_back(move[curr.first][curr.second]);
            curr = parent[curr.first][curr.second];
        }
        cout << res.size() << endl;
        for(int i = res.size()-1; i >= 0; i--)
            cout << res[i];
    } else cout <<"NO";
    return 0;
}