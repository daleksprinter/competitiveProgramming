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
//template<class T>auto cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}

/* main */

int n, d;

int cnt(int n, int t){
    int cnt = 0;
    if(n == 0) return 0;
    while(n % t == 0){
        cnt++;
        n /= t;
    }
    return cnt;
}

double dp[100][70][50][40];


double dfs(int i, int m){
    if(m == 0) return 1;
    
    if(i == n) return 0;

    int m2 = cnt(m, 2), m3 = cnt(m, 3), m5 = cnt(m, 5);


    if(dp[i][m2][m3][m5] > -1) return dp[i][m2][m3][m5];


    double ans = 0.0;
    rep(j,1,7){
        ans += 1.0 / 6.0 * dfs(i + 1, (m * j) % d);
    }

    return dp[i][m2][m3][m5] = ans;




}


signed main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> d;
    rep(i,0,100)rep(j,0,70)rep(k,0,50)rep(l,0,40) dp[i][j][k][l] = -1.0;
    printf("%0.9f\n", dfs(0, 1));


    



 

    

    


    




    






    



    


    

}


