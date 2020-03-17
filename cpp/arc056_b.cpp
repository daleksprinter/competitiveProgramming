#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

struct UnionFind {
    vector<int> par; // 親ノード
    vector<int> rank; // ランク

    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n); rank.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s; s--;

    vector< vector<int> > al(n);

    rep(i,0,m){
        int f, t;
        cin >> f >> t;
        f--; t--;
        al[min(f,t)].push_back(max(f,t));
    }

    UnionFind uf = UnionFind(n);

    vector<int> ans;

    for(int i = n-1; i > -1; i--){
        rep(j,0,al[i].size()){
            uf.merge(i, al[i][j]);
        }
        if(uf.issame(s, i)){
            ans.push_back(i+1);
        }
    }

    for(int i = ans.size()-1; i > -1; i--){
        cout << ans[i] << endl;
    }


}
