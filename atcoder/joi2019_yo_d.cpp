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
#define bin(x) static_cast<bitset<16> >(x)



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

int n;
vec<pi> arr;
void in(){
    cin >> n;
    rep(i,0,n) arr.push_back(pi(input(), i));
    sort(all(arr));
    reverse(all(arr));
}

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

    mi comp(){
        mi ret;
        rep(i,0,sz(par)) ret[root(i)]++;
        return ret;
    }

    

};

void solve(){
    
    int ans = 0;
    
    Union_Find uf(n);
    vec<bool> flag(n, false);

    int comp = 0;
    rep(i,0,n){

        int h = arr[i].first;
        int ind = arr[i].second;
        flag[ind] = true;
        comp++;
        if(ind > 0 && flag[ind - 1]) comp--;
        if(ind < n - 1 && flag[ind + 1]) comp--;

        if(arr[i + 1].first != h) chmax(ans, comp);
    }

    print(ans);



}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
