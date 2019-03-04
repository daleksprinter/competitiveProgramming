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

int h, w, k;
void in(){
    cin >> h >> w >> k;
    k--;
}

int dp[102][8];
int dfs(int i, int pos){

    if(i == h) return (pos == k);

    if(dp[i][pos] > -1) return dp[i][pos];

    int ans = 0;

    rep(j,0,(1 << (w - 1))){
        bool isok = true;
        rep(k,0,w - 2){
            if((j & (1 << k)) && (j & (1 << (k + 1)))){
                isok = false;
                break;
            }
        }

        if(not isok) continue;

        if(pos == 0){//leftmost

            if(j & (1 << 0)){
                ans += dfs(i + 1, 1);
                ans %= mod;
            }else{
                ans += dfs(i + 1, 0);
                ans %= mod;

            }

        }else if(pos == w - 1){//rightmost

            if(j & (1 << (pos - 1))){
                ans += dfs(i + 1, pos - 1);
                ans %= mod;

            }else{
                ans += dfs(i + 1, pos);
                ans %= mod;

            }

        }else{

            if(j & (1 << (pos - 1))){//left
                ans += dfs(i + 1, pos - 1);
                ans %= mod;
            }else if(j & (1 << pos)){
                ans += dfs(i + 1, pos + 1);
                ans %= mod;
            }else{
                ans += dfs(i + 1, pos);
                ans %= mod;
            }

        }

    }

    return dp[i][pos] = ans % mod;


}


void solve(){
    memset(dp, -1, sizeof(dp));
    print(dfs(0, 0));


}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
