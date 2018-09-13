#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

vector<vector<pair<int,int>>> al(100000);
vector<int> dist(100000,inf * -1);
vector<bool> visited(100000,false);

bool bfs(int i,int d){
    
    if(visited[i] && d != dist[i]) return false;
    
    if(visited[i] && d == dist[i]) return true;

    visited[i] = true;
    dist[i] = d; 
    rep(j, 0, al[i].size()){
        if( ! bfs(al[i][j].first, d + al[i][j].second) ) return false;
    }
    
    return true;
}


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n,m;
    cin >> n >> m;

    rep(i,0,m){
        int l,r,d;
        cin >> l >> r >> d;
        l--; r--;
        al[l].push_back(make_pair(r,d));
        al[r].push_back(make_pair(l,-1*d));
    }

    rep(i,0,n){
        if(!visited[i]){
            if( ! bfs(i,0) ){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

}
