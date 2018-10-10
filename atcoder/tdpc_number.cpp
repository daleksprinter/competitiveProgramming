#include <bits/stdc++.h>
using namespace std;


/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)
#define sum(v) accumulate(all(v), (0LL))
#define sort(v) sort(all(v))



/* constant */
const int inf = 100100100100100100;
const int mod = 1000000007;
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


/* math_library */
int ceil(int a, int b){if(a % b == 0){return a/b;}else{return a/b + 1;}}


/* main */

int d;
string n;
int dp[100010][100][2];

int dfs(int i, int modd, bool flag){

    if(dp[i][modd][flag] > -1) return dp[i][modd][flag];

    if(i == n.size()){
        if(modd == 0){
            return 1;
        }else{
            return 0;
        }
    }

    int ans = 0;
    for(int j = 0; j <= (flag ? n[i] - '0' : 9); j++){
        ans += dfs(i + 1, (modd + j) % d, (flag && (j == (n[i] - '0')) ? true : false)) % mod;
    }

    return dp[i][modd][flag] = ans % mod;

}


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    
   cin >> d >> n;
   memset(dp, -1, sizeof(dp));

   print(dfs(0, 0, true) - 1);





   




}   

