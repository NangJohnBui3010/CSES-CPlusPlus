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

struct range{
    int l,r;
    int id;
};

bool cmp(range a, range b){
    return(a.l < b.l || (a.l == b.l && a.r > b.r));
}

 
int main(){
    int n; 
    cin >> n;
    vector<range> arr(n);
    vector<bool> contains(n,0), contained(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i].l >> arr[i].r;
        arr[i].id = i;
    }
    sort(arr.begin(),arr.end(),cmp);
    int maxR = 0;
    for(auto x:arr){
        if(x.r <= maxR){
            contained[x.id] = 1;
        }else{
            maxR = x.r;
        }
    }

    int minR = 1e9+7;
    for(int i = n-1; i >= 0; i--){
        if(arr[i].r >= minR)
            contains[arr[i].id] = 1;
        else
            minR = arr[i].r;
    }

    for(auto x:contains)
        cout << x << " ";
    cout << endl;
    for(auto x:contained)
        cout << x << " ";
    return 0; 
} 