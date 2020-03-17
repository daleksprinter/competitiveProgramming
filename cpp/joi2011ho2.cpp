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
const int inf = pow(2, 62);
const int mod = 1e9 + 7;
int dx[8]={1,0,-1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,-1,-1,1,1};
const string alpha = "abcdefghijklmnopqrstuvwxyz";

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
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}



/* main */

int n, k;
vec<vi> arr(10);

int dp[10][2010];

int dfs(int i, int rest){

    if(dp[i][rest] > -1) return dp[i][rest];

    if(rest == 0) return 0;

    if(i == 9){
        if(rest <= arr[i].size()){
            return arr[i][rest - 1] + rest * (rest - 1);
        }else{
            return -inf;
        }
    }

    int ans = 0;

    chmax(ans, dfs(i + 1, rest));

    rep(j,1,min(rest, (int)arr[i].size()) + 1){
        chmax(ans, dfs(i + 1, rest - j) + arr[i][j - 1] + j * (j - 1)); 
    }

    return dp[i][rest] = ans;


}



signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;


    rep(i,0,n){
        int val, cat; cin >> val >> cat; cat--;
        arr[cat].push_back(val);
    }

    rep(i,0,10){
        sort(all(arr[i]));
        reverse(all(arr[i]));
        rep(j,1,arr[i].size()) arr[i][j] += arr[i][j - 1];
    }

    memset(dp, -1, sizeof(dp));

    print(dfs(0, k));



    









    
    






}
