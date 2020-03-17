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
#define isin(tx, ty, w, h) (0 <= tx && tx <= w && 0 <= ty && ty <= h)


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = pow(2, 62);
const int mod = 1e9 + 7;
int dx[8]={1,0,-1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,-1,-1,1,1};

/* io_method */
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
template<class T> void printx(T n){cout << n;}
template<class T, class U> void printx(pair<T, U> p){cout << "(" << p.first << "," << p.second << ")";}
template<class T> void printx(vector<T> v){cout << "{";rep(i,0,v.size()){printx(v[i]);if(i != v.size()-1)printx(",");}cout << "}";}
template<class T> void print(T n){printx(n);cout << endl;}
template<class T> void print(set<T> s){cout << "{";each(s, e){if(e != s.begin()) printx(",");printx(*e);}cout << "}" << endl;}
template<class T, class U> void print(map<T, U> mp){cout << "{";each(mp, e){cout << "(" << e -> first << "," << e -> second << ")";}cout << "}" << endl;}


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}




/* main */




int mod_pow(int x, int n, int m){if(n== 0) return 1;int res = mod_pow(x*x%m,n/2,m);if(n&1) res = res*x%m;return res;}
int inv(int n){return mod_pow(n,mod-2,mod);}
signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n = input();

    vi tmp; 
    rep(i,0,n){
        int t = input();
        if(t > n - 1){
            print(0);
            return 0;
        }
        tmp.push_back(t);
    }


    if(tmp[0] != 0){
        print(0);
        return 0;
    }

    map<int, int> mp;

    rep(i,0,n) mp[tmp[i]]++;

    if(mp[0] > 1){
        print(0);
        return 0;
    }

    vec<pi> arr;

    each(mp, itr){
        arr.push_back(*itr);
    }
    int len = arr.size();
    int ans = 1;


    rep(i,1,len){
        if(arr[i].first != arr[i - 1].first + 1){
            print(0);
            return 0;
        }
        int t = arr[i].second;
        rep(j,0,t){
            ans *= mod_pow(2, arr[i - 1].second, mod) - 1;
            ans %= mod;
        }
        ans *= mod_pow(2, t * (t - 1) / 2, mod);
        ans %= mod;
    }
    print((ans + mod) % mod);



    

    


    




    





}






    

