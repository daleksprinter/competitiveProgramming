#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;


struct UnionFind {
    vector<int> par; // 親ノード
    vector<int> size; // ランク

    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n); size.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, size[i] = 1;
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
        if (size[x] < size[y]) swap(x, y);
        size[x] += size[y];
        par[y] = x;
        return true;
    }

    int getsize(int x){
        return size[root(x)];
    }
};

bool comp(const vector<int> &a, const vector<int>&b){
    return a[2] > b[2];
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m; cin >> n >> m;

    vector< vector<int> > edges;
    rep(i,0,m){
        int frm, to, year;
        cin >> frm >> to >> year;
        frm--; to--;
        vector<int> tmp = {frm, to, year};
        edges.push_back(tmp);
    }

    sort(edges.begin(), edges.end(), comp);

    vector< vector<int> >queries;
    int q;
    cin >> q;
    rep(i,0,q){
        int v, year;
        cin >> v >> year;
        v--;
        vector<int> tmp = {i, v, year};
        queries.push_back(tmp);
    }

    sort(queries.begin(), queries.end(), comp);

    UnionFind uf = UnionFind(n);

    vector<pair<int, int>> qans;
    int j = 0;
    rep(i, 0, queries.size()){
        while(j < edges.size() && edges[j][2] > queries[i][2]){
            uf.merge(edges[j][0], edges[j][1]);
            j++;
        }
        qans.push_back(make_pair(queries[i][0], uf.getsize(queries[i][1])));
    }

    sort(qans.begin(), qans.end(), cmp);

    rep(i,0,qans.size()) cout << qans[i].second << endl;
    return 0;

    



}
