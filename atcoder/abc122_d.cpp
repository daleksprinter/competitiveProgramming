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
void in(){
    cin >> n;
}
string atcg = "ATCG";

int dp[100][20][20][20][20];

int dfs(int i, char prev3, char prev2, char prev1, char prev0){
    if(prev3 == 'A' && prev2 == 'G' && prev1 == 'C') return 0;
    if(prev3 == 'A' && prev2 == 'C' && prev1 == 'G') return 0;
    if(prev3 == 'G' && prev2 == 'A' && prev1 == 'C') return 0;

    if(prev2 == 'A' && prev1 == 'G' && prev0 == 'C') return 0;
    if(prev2 == 'A' && prev1 == 'C' && prev0 == 'G') return 0;
    if(prev2 == 'G' && prev1 == 'A' && prev0 == 'C') return 0;

    if(prev3 == 'A' && prev1 == 'G' && prev0 == 'C') return 0;
    if(prev3 == 'A' && prev2 == 'G' && prev0 == 'C') return 0;

    if(i == n) return 1;

    if(dp[i][prev3 - 'A'][prev2 - 'A'][prev1 - 'A'][prev0 - 'A'] > -1)  return dp[i][prev3 - 'A'][prev2 - 'A'][prev1 - 'A'][prev0 - 'A'];

    int ans = 0;

    rep(j,0,4){
        ans += dfs(i + 1, prev2, prev1, prev0, atcg[j]);
        ans %= mod;
    }

    return dp[i][prev3 - 'A'][prev2 - 'A'][prev1 - 'A'][prev0 - 'A'] = ans;
}


void solve(){
    
    memset(dp, -1,sizeof(dp));

    if(n == 3){
        print(61);
        return ;
    }

    int ans = 0;
    rep(i,0,4){
        rep(j,0,4){
            rep(k,0,4){
                rep(l,0,4){
                    ans += dfs(4, atcg[i], atcg[j], atcg[k], atcg[l]);
                    ans %= mod;
                }
            }
        }
    }

    print(ans);

}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
