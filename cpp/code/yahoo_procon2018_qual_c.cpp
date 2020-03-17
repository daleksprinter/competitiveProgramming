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
#define bin(x) static_cast<bitset<4> >(x)


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


/* math_method */
int ceil(int a, int b){return a / b + (a % b > 0);}

int popcount(long bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}
/* main */

int n;
vi x;
vi xcs;
vi c;
vi v;
vi cost(1 << 18, 0);
vi val(1 << 18, 0);
void in(){
    cin >> n;
    rep(i,0,n)x.push_back(input());
    rep(i,0,n)c.push_back(input());
    rep(i,0,n)v.push_back(input());
    xcs.push_back(0);
    xcs.push_back(x[0]); rep(i,1,n) xcs.push_back(xcs.back() + x[i]);
    rep(i,0,(1 << n)){
        rep(j,0,n){
            if(i & (1 << j)){
                cost[i] += c[j];
                val[i] += v[j];
            }
        }
    }
}

int dp[18][1 << 18];
int dfs(int i, int s){
    if(dp[i][s] > -1) return dp[i][s];
    int ans = (cost[s] <= xcs[i] ? val[s] : 0);

    rep(j,0,n){
        if(s & (1 << j)){
            chmax(ans, dfs(i, s ^ (1 << j)));
        }
    }

    return dp[i][s] = ans;

}

int dp2[18][1 << 18];
int dfs2(int solve, int s){
    if(s == 0) return 0;
    if(dp2[solve][s] > -1) return dp2[solve][s];
    int ans = inf;
    rep(i,0,n){
        if(s & (1 << i)){
            chmin(ans, dfs2(solve + 1, s ^ (1 << i)));
        }
    }

    return dp2[solve][s] = max(dp[solve][s], ans); 
}

void solve(){

    memset(dp,-1,sizeof(dp));
    rep(i,0,n + 1){
        rep(j,0,(1 << n)){
            if(popcount(j) != n - i) continue;
            dfs(i,j);
        }
    }

    memset(dp2, -1, sizeof(dp2));
    int ans = 0;
    chmax(ans, dfs2(0, (1 << n) - 1));
    print(ans);


}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
