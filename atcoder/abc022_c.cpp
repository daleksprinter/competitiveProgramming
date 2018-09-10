#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const ll inf = 100100100100100;
const int mod = 1e9+7;


vector<vector<ll>> warshall_floyd(vector<vector<ll>> edges,int v){
    vector<vector<ll>> ret = edges;
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

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector< vector<ll> > arr(n);
    rep(i,0,n){
        rep(j,0,n){
            arr[i].push_back(inf);
        }
    }
    ll frm1[n];
    rep(i,0,n) frm1[i] = inf;

    rep(i,0,m){
        int f,t,c;
        cin >> f >> t >>c;
        f--;
        t--;
        if(f == 0 || t == 0){
            frm1[max(f,t)] = c;
        }else{
            arr[f][t] = c;
            arr[t][f] = c;
        }
    }
    vector<vector<ll>> wf = warshall_floyd(arr,n);

    ll ans = inf;
    rep(i,1,n){
        rep(j,i+1,n){
            ans = min(ans, frm1[i] + frm1[j] + wf[i][j]);
        }
    }
    if(ans == inf){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

}
