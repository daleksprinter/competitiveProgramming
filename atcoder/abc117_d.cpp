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


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}

/* main */

int n, k;
vi arr;
vi dig;

void in(){
    cin >> n >> k;
    rep(i,0,n){
        arr.push_back(input());
    }

    rep(i,0,50){
        dig.push_back(k % 2);
        k /= 2;
    }
    reverse(all(dig));

}

int score[50][2];

int dp[50][2];

int dfs(int i, bool flag){

    if(i == 50) return 0;

    if(dp[i][flag] > -1) return dp[i][flag];

    int ans = 0;

    if(flag){
        rep(j,0,dig[i] + 1){
            chmax(ans, score[i][j] + dfs(i + 1, dig[i] == j));
        }
    }else{
        chmax(ans, score[i][0] + dfs(i + 1, false));
        chmax(ans, score[i][1] + dfs(i + 1, false));
    }

    return dp[i][flag] = ans;


}


void solve(){
    
    memset(score, 0, sizeof(score));
    memset(dp, -1, sizeof(dp));


    rep(i,0,50){
        int cnt = 0;
        rep(j,0,n) cnt += arr[j] & (1LL << i);
        score[49 - i][0] = cnt;
        score[49 - i][1] = (1LL << i) * n - cnt;

    }


    print(dfs(0, true));




}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}

