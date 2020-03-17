#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100009;
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

    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(n,inf));

    rep(i,0,m){
        int f, t, c; cin >> f >> t >> c; f--; t--;
        arr[f][t] = c; arr[t][f] = c;
    }

    vector<vector<int>> wf = warshaint_floyd(arr, n);

    int ans = 0;
    rep(i,0,n){
        rep(j,i+1,n){
            if(arr[i][j] < inf && arr[i][j] > wf[i][j]) ans++;
        }
    }
    cout << ans << endl;




}   
