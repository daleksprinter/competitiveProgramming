#include "bits/stdc++.h"
using namespace std;

/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = 10001000100;
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

struct cumsum1d{
    int n;
    vector<int> arr;

    cumsum1d(int len){
        n = len;
        rep(i,0,n) arr.push_back(0);
    }

    void init(vector<int> vec){
        arr = vec;
        n = arr.size();
    }

    void add(int a, int b, int val = 1){
        arr[a] += val;
        if(b + 1 < n) arr[b + 1] -= val;
    }

    void build(){
        rep(i,1,n) arr[i] += arr[i-1];
    }

    int query(int from, int to){
        int ret = arr[to];
        if(from) ret -= arr[from - 1];
        return ret;
    }

};



/* main */

int n;
vi arr;
cumsum1d cs(10);
int mi;
int dp[50][50];

int dfs(int prev, int i){

    if(i == n){
        if(prev < n && cs.query(prev, n - 1) >= mi && !(prev == 0)){
            return cs.query(prev, n - 1);
        }else{
            return inf;
        }
    }

    if(dp[prev][i] > -1) return dp[prev][i];

    int ans = inf;

    if(cs.query(prev, i) >= mi){
        chmin(ans, max(cs.query(prev, i), dfs(i + 1, i + 1)));
    }

    chmin(ans, dfs(prev, i + 1));

    return dp[prev][i] = ans;


}


signed main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i,0,n) arr.push_back(input());
    cs.init(arr); cs.build();



    int ans = inf;
    rep(i,0,n){
        rep(j,i,n){
            mi = cs.query(i,j);
            memset(dp, -1, sizeof(dp));
            chmin(ans, dfs(0, 0) - mi);
        }
    }

    print(ans);

    

    





    






	



	
	


	




	




    



	








    



    





    


    

}


