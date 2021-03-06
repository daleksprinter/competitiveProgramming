#include "bits/stdc++.h"
using namespace std;

/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)
#define sum(v) accumulate(all(v), (0LL))
#define isin(a, b, c) (b <= a && a <= c)
#define println cout << "\n";
#define sz(v) (int)v.size()


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
typedef map<int, int> mi;
typedef set<int> si;


/* constant */
const int inf = 1LL << 62;
const int mod = 1e9 + 7;
const int dx[8]={1,0,-1,0,-1,1,-1,1};
const int dy[8]={0,1,0,-1,-1,-1,1,1};
const string alphabet = "abcdefghijklmnopqrstuvwxyz";

/* io_method */
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
template<class T> void printx(T n){cout << n;}
template<class T, class U> void printx(pair<T, U> p){cout << "(" << p.first << "," << p.second << ")";}
template<class T, class U, class V> void printx(tuple<T, U, V> t){cout << "{" << get<0>(t) << "," << get<1>(t) <<"," << get<2>(t) << "}" << endl;}
template<class T> void printx(vector<T> v){cout << "{";rep(i,0,v.size()){printx(v[i]);if(i != v.size()-1)printx(",");}cout << "}";}
template<class T> void print(T n){printx(n);cout << endl;}
template<class T> void print(set<T> s){cout << "{";each(s, e){if(e != s.begin()) printx(",");printx(*e);}cout << "}" << endl;}
template<class T, class U> void print(map<T, U> mp){cout << "{";each(mp, e){cout << "(" << e -> first << "," << e -> second << ")";}cout << "}" << endl;}
template<class T> void printans(vec<T> v){rep(i,0,sz(v)){cout << v[i] << (i == sz(v) - 1 ? "" : " ");}cout << endl;}


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}

/* main */

struct Union_Find{
    vector<int> par;
    vector<int> size;

    Union_Find(int n){
        for(int i = 0; i < n; i++){
            par.push_back(i);
            size.push_back(1);
        }
    }

    int root(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = root(par[x]);
        }
    }

    void merge(int x, int y){
        x = root(x);
        y = root(y);

        if(x == y) return;

        if(size[x] < size[y]) swap(x, y);
        par[y] = x;
        size[x] += size[y];
    }
    int getsize(int n){
        return size[root(n)];
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    mi comp(){
        mi ret;
        rep(i,0,sz(par)) ret[root(i)]++;
        return ret;
    }

    

};

int n, m;
vec<pi> edge;
void in(){
    cin >> n >> m;
    rep(i,0,m){
        int f, t; cin >> f >> t;
        f--; t--;
        edge.push_back(pi(f, t));
    }
    reverse(all(edge));
}

void solve(){
    Union_Find uf = Union_Find(n);
    vi ans;
    ans.push_back(n * (n - 1) / 2);
    rep(i,0,m){
        int f = edge[i].first; int t = edge[i].second;
        if(not uf.same(f, t)){
            ans.push_back(ans.back() - (uf.getsize(f) * uf.getsize(t)));

            uf.merge(f, t);
        }else{
            ans.push_back(ans.back());
        }


    }

    reverse(all(ans));
    ans = cut(ans, 1, sz(ans));
    for(int e : ans){
        print(e);
    }




}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
