#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;


vector<vector<int>> warshaint_floyd(vector<vector<int>> edges,int v){
    vector<vector<int>> ret = edges;
    rep(k,0,v){
        rep(i,0,v){
            rep(j,0,v){
                if(ret[i][k] == inf || ret[k][j] == inf) continue;
                ret[i][j] = min(ret[i][j],ret[i][k] + ret[k][j]);
            }
        }
    }
    return ret;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> edges(n);
    rep(i,0,n) rep(j,0,n) edges[i].push_back(inf);
    rep(i,0,n) edges[i][i] = 0;

    rep(i,0,m){
        int frm, to, cost;
        cin >> frm >> to >> cost;
        frm--;
        to--;

        edges[frm][to] = cost;
        edges[to][frm] = cost;

    }

    edges = warshaint_floyd(edges, n);

    int ans = inf;
    rep(i,0,n) ans = min(ans, *max_element(edges[i].begin(), edges[i].end()));

    cout << ans << endl;
    
}
