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
int a, b;
vi va;
vi vb;

int dp[1010][1010];

int dfs(int pa, int pb){

    if(pa == -1 && pb == -1) return 0;

    if(pa != -1 && pb != -1 && dp[pa][pb] > -1) return dp[pa][pb];

    if(((a - pa) + (b - pb)) % 2 == 0){//my turn

        if(pa == -1) return vb[pb] + dfs(pa, pb - 1);
        if(pb == -1) return va[pa] + dfs(pa - 1, pb);

        return dp[pa][pb] = max(va[pa] + dfs(pa - 1, pb), vb[pb] + dfs(pa, pb - 1));

    }else{

        if(pa == -1) return dfs(-1, pb - 1);
        if(pb == -1) return dfs(pa - 1, -1);

        return dp[pa][pb] = min(dfs(pa - 1, pb), dfs(pa, pb - 1));

    }


}



signed main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> a >> b;
    rep(i,0,a) va.push_back(input());
    rep(j,0,b) vb.push_back(input());
    reverse(all(va));
    reverse(all(vb));
    memset(dp, -1, sizeof(dp));

    print(dfs(a - 1, b - 1));

    

    


    




    






    



    


    

}


