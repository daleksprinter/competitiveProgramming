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
#define mp(a, b) make_pair(a, b)


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = 100100100100;
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




/* main */


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, y, z; cin >> n >> m >> y >> z;

    map<char, int> mp;
    int colp[m];
    rep(i,0,m){
        char col; int p;
        cin >> col >> p;
        mp[col] = i;
        colp[i] = p; 
    }


    int dp[2][1<<m][m + 1];
    
    rep(i,0,1<<m){
        rep(j,0,m + 1){
            dp[0][i][j] = -inf;
            dp[1][i][j] = -inf;
        }
    }

    dp[0][0][m] = 0;

    rep(i,0,n){
        char c; cin >> c;
        int col = mp[c];


        rep(j,0,1<<m){
            rep(k,0,m + 1){
                if(dp[(i) % 2][j][k] > -inf){
                    chmax(dp[(i + 1) % 2][j | (1<<col)][col], dp[(i)% 2][j][k] + colp[col] + (k == col ? y : 0));
                    chmax(dp[(i + 1) % 2][j][k], dp[i%2][j][k]);
                }
            }
        }

    }
    rep(i,0,m){
        dp[n % 2][(1<<m) - 1][i] += z;
    }

    int ans = 0;
    rep(i,0,1<<m){
        rep(j,0,m){
            chmax(ans, dp[n % 2][i][j]);
        }
    }

    print(ans);



    


    



}







    










    




    









