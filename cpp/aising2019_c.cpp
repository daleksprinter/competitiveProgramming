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
#define pb push_back


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = 1000100010010010;
const int mod = 1e9 + 7;
int dx[8]={1,0,-1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,-1,-1,1,1};


/* io_method */
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
string readline(){string s;getline(cin, s);return s;}
template<class T> void printx(T n){cout << n;}
template<class T, class U> void printx(pair<T, U> p){cout << "(" << p.first << "," << p.second << ")";}
template<class T> void printx(vector<T> v){cout << "{";rep(i,0,v.size()){printx(v[i]);if(i != v.size()-1)printx(",");}cout << "}";}
template<class T> void print(T n){printx(n);cout << endl;}
template<class T> void print(set<T> s){cout << "{";each(s, e){if(e != s.begin()) printx(",");printx(*e);}cout << "}" << endl;}
template<class T, class U> void print(map<T, U> mp){cout << "{";each(mp, e){cout << "(" << e -> first << "," << e -> second << ")";}cout << "}" << endl;}


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>auto cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}


struct cumsum1d{
    int n;
    vector<int> arr;

    cumsum1d(int len){
        n = len;
        rep(i,0,n) arr.push_back(0);
    }

    void init(vector<int> vec){
        arr = vec;
        n = arr.size();
    }

    void add(int a, int b, int val = 1){
        arr[a] += val;
        if(b + 1 < n) arr[b + 1] -= val;
    }

    void build(){
        rep(i,1,n) arr[i] += arr[i-1];
    }

    int query(int from, int to){
        int ret = arr[to];
        if(from) ret -= arr[from - 1];
        return ret;
    }

};
/* main */

struct Union_Find{
    vector<int> par;
    vector<int> rank;

    Union_Find(int n){
        for(int i = 0; i < n; i++){
            par.push_back(i);
            rank.push_back(0);
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

        if(rank[x] < rank[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    int cnt_comp(){
        set<int> s;
        rep(i,0,par.size()){
            s.insert(par[i]);
        }
        return s.size();
    }

};

int mod_pow(int x, int n, int m){if(n== 0) return 1;int res = mod_pow(x*x%m,n/2,m);if(n&1) res = res*x%m;return res;}


int h, w; 

int getnum(int x, int y){
    return y * w + x;
}



signed main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    int n = h * w;

    int arr[h][w];

    rep(i,0,h){
        rep(j,0,w){
            char t; cin >> t;
            if(t == '#'){
                arr[i][j] = 0;
            }else{
                arr[i][j] = 1;
            }
        }
    }

    Union_Find uf(h * w);

    rep(i,0,h){
        rep(j,0,w){
            int num = getnum(j, i);

            rep(k,0,4){
                int ty = i + dy[k];
                int tx = j + dx[k];
                if(0 <= tx && tx < w && 0 <= ty && ty < h && arr[i][j] != arr[ty][tx]){
                    int adj = getnum(tx, ty);
                    uf.merge(num, adj);
                }
                
            }

        }
    }

    vi comps;
    rep(i,0,n){
        comps.push_back(uf.root(i));
    }


    vec<pi> col(n, pi(0,0));
    rep(i,0,h){
        rep(j,0,w){
            if(arr[i][j] == 0){
                col[comps[getnum(j, i)]].first++;
            }else{
                col[comps[getnum(j, i)]].second++;
            }
        }
    }


    int ans = 0;
    rep(i,0,n){
        ans += col[i].first * col[i].second;
    }
    print(ans);

    


    


    


    

}


