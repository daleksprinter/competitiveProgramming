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
#define sec second
#define fir first
#define pb push_back



/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
//const int inf = pow(2, 62);
//const int mod = 1e9 + 7;
const int mod = 100000;
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




/* main */

int w, h;

int dp[105][105][2][3];


int dfs(int x, int y, bool turned, int turn){
    if(x == w && y == h) return 1;

    if(dp[x][y][turned][turn] > -1 ) return dp[x][y][turned][turn];

    int ans = 0;
    if(turned){
        if(turn == 0 && x + 1 <= w) ans += dfs(x + 1, y, false, 0);
        ans %= mod;
        if(turn == 1 && y + 1 <= h) ans += dfs(x, y + 1, false, 1);
        ans %=  mod;
    }else{
        if(turn == 0){
            if(x + 1 <= w) ans += dfs(x + 1, y, false, 0);
            ans %= mod;
            if(y + 1 <= h) ans += dfs(x, y + 1, true, 1);
            ans %= mod;
        }else if(turn == 1){
            if(x + 1 <= w) ans += dfs(x + 1, y, true, 0);
            ans %= mod;
            if(y + 1 <= h) ans += dfs(x, y + 1, false, 1);
            ans %= mod;
        }else if(turn == 2){
            ans += dfs(x + 1, y, false, 0);
            ans %= mod;
            ans += dfs(x, y + 1, false, 1);
            ans %= mod;
        }
    }

    return dp[x][y][turned][turn] = ans % mod;


}



signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    

    cin >> w >> h;

    memset(dp, -1, sizeof(dp));

    print(dfs(1, 1, false, 2));

    







   




    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









