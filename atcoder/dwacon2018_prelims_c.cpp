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
#define pb(x) push_back(x)



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

int n, m;
mi mp1;
mi mp2;
vi killa;
vi killb;
vi a;
vi b;
void in(){
    cin >> n >> m;
    rep(i,0,n){
        int t = input();
        mp1[t]++; 
        killa.push_back(t);
    }
    for(auto e : mp1) a.pb(e.second);

    rep(i,0,m){
        int t = input();
        mp2[t]++; 
        killb.push_back(t);
    }   
    for(auto e : mp2) b.pb(e.second);
}

int comb[110][1010];

int dp1[101][1001];
int dfs1(int i, int rest){
    if(i == sz(a)) return rest == 0;
    if(dp1[i][rest] > -1) return dp1[i][rest];
    int ans = 0;
    rep(j,0,rest + 1){
        ans += dfs1(i + 1, rest - j) * comb[a[i]][j];
        ans %= mod;
    }
    return dp1[i][rest] = ans;
}

int dp2[101][1001];
int dfs2(int i, int rest){
    if(i == sz(b)) return rest == 0;
    if(dp2[i][rest] > -1) return dp2[i][rest];
    int ans = 0;
    rep(j,0,rest + 1){
        ans += dfs2(i + 1, rest - j) * comb[b[i]][j];
        ans %= mod;
    }
    return dp2[i][rest] = ans;
}


void solve(){
    memset(comb,-1,sizeof(comb));

    //calc comb 
    comb[0][0] = 1;
    rep(i,0,110) comb[i][0] = 1;
    rep(i,1,1010) comb[0][i] = 0;
    rep(i,1,110){
        rep(j,1,1010){
            comb[i][j] = ((j-i < 0 ? 0 : comb[i][j-i]) + comb[i-1][j]) % mod;
        }
    }

    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    int deatha = dfs1(0, sum(killb));
    int deathb = dfs2(0, sum(killa));

    print(deatha * deathb % mod);



}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
